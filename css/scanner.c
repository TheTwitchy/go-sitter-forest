#include "parser.h"

#include <wctype.h>

enum TokenType {
    DESCENDANT_OP,
    PSEUDO_CLASS_SELECTOR_COLON,
    ERROR_RECOVERY,
};

static inline void advance_css(TSLexer *lexer) { lexer->advance_css(lexer, false); }

static inline void skip_css(TSLexer *lexer) { lexer->advance_css(lexer, true); }

void *tree_sitter_css_external_scanner_create() { return NULL; }

void tree_sitter_css_external_scanner_destroy(void *payload) {}

unsigned tree_sitter_css_external_scanner_serialize(void *payload, char *buffer) { return 0; }

void tree_sitter_css_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

bool tree_sitter_css_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    if (valid_symbols[ERROR_RECOVERY]) {
        return false;
    }

    if (iswspace(lexer->lookahead) && valid_symbols[DESCENDANT_OP]) {
        lexer->result_symbol = DESCENDANT_OP;

        skip_css(lexer);
        while (iswspace(lexer->lookahead)) {
            skip_css(lexer);
        }
        lexer->mark_end(lexer);

        if (lexer->lookahead == '#' || lexer->lookahead == '.' || lexer->lookahead == '[' || lexer->lookahead == '-' ||
            lexer->lookahead == '*' || iswalnum(lexer->lookahead)) {
            return true;
        }

        if (lexer->lookahead == ':') {
            advance_css(lexer);
            if (iswspace(lexer->lookahead)) {
                return false;
            }
            for (;;) {
                if (lexer->lookahead == ';' || lexer->lookahead == '}' || lexer->eof(lexer)) {
                    return false;
                }
                if (lexer->lookahead == '{') {
                    return true;
                }
                advance_css(lexer);
            }
        }
    }

    if (valid_symbols[PSEUDO_CLASS_SELECTOR_COLON]) {
        while (iswspace(lexer->lookahead)) {
            skip_css(lexer);
        }
        if (lexer->lookahead == ':') {
            advance_css(lexer);
            if (lexer->lookahead == ':') {
                return false;
            }
            lexer->mark_end(lexer);
            lexer->result_symbol = PSEUDO_CLASS_SELECTOR_COLON;
            // We need a { to be a pseudo class selector, a ; indicates a property
            while (lexer->lookahead != ';' && lexer->lookahead != '}' && !lexer->eof(lexer)) {
                advance_css(lexer);
                if (lexer->lookahead == '{') {
                    return true;
                }
            }

            // If we're at eof, and we happened to *not* find an opening brace to indicate we have a pseudo class
            // selector, we should *still* return one at EOF. This will improve error recovery, and the malformed code
            // can be parsed as an erroneous pseudo-class selector, rather than an erroneous property.
            return lexer->eof(lexer);
        }
    }

    return false;
}
