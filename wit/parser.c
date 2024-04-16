#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 78
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 79
#define ALIAS_COUNT 0
#define TOKEN_COUNT 55
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 10

enum ts_symbol_identifiers {
  anon_sym_interface = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_type = 4,
  anon_sym_EQ = 5,
  anon_sym_SEMI = 6,
  anon_sym_bool = 7,
  anon_sym_s8 = 8,
  anon_sym_s16 = 9,
  anon_sym_s32 = 10,
  anon_sym_s64 = 11,
  anon_sym_u8 = 12,
  anon_sym_u16 = 13,
  anon_sym_u32 = 14,
  anon_sym_u64 = 15,
  anon_sym_float32 = 16,
  anon_sym_float64 = 17,
  anon_sym_char = 18,
  anon_sym_string = 19,
  anon_sym_func = 20,
  anon_sym_LPAREN = 21,
  anon_sym_RPAREN = 22,
  anon_sym_DASH_GT = 23,
  anon_sym_package = 24,
  anon_sym_COLON = 25,
  anon_sym_AT = 26,
  anon_sym_list = 27,
  anon_sym_tuple = 28,
  sym_identifier = 29,
  sym_version = 30,
  anon_sym_world = 31,
  anon_sym_import = 32,
  sym_line_comment = 33,
  sym_block_comment = 34,
  sym_ident = 35,
  sym_unit = 36,
  sym_star = 37,
  anon_sym_COMMA = 38,
  anon_sym_LT = 39,
  anon_sym_GT = 40,
  anon_sym_option = 41,
  anon_sym_result = 42,
  anon_sym_future = 43,
  anon_sym_stream = 44,
  anon_sym_as = 45,
  anon_sym_use = 46,
  anon_sym_from = 47,
  anon_sym_record = 48,
  anon_sym_flags = 49,
  anon_sym_variant = 50,
  anon_sym_enum = 51,
  anon_sym_union = 52,
  anon_sym_static = 53,
  anon_sym_resource = 54,
  sym_source_file = 55,
  sym__definition = 56,
  sym_interface = 57,
  sym__interface_content = 58,
  sym_type_definition = 59,
  sym_type = 60,
  sym_function_declaration = 61,
  sym_package = 62,
  sym_list = 63,
  sym_tuple = 64,
  sym_world = 65,
  sym_import = 66,
  sym_ty = 67,
  sym_tp1 = 68,
  sym_tp2 = 69,
  sym_tps = 70,
  sym_option = 71,
  sym_result = 72,
  sym_future = 73,
  sym_stream = 74,
  aux_sym_source_file_repeat1 = 75,
  aux_sym_interface_repeat1 = 76,
  aux_sym_world_repeat1 = 77,
  aux_sym_tps_repeat1 = 78,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_interface] = "interface",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_type] = "type",
  [anon_sym_EQ] = "=",
  [anon_sym_SEMI] = ";",
  [anon_sym_bool] = "bool",
  [anon_sym_s8] = "s8",
  [anon_sym_s16] = "s16",
  [anon_sym_s32] = "s32",
  [anon_sym_s64] = "s64",
  [anon_sym_u8] = "u8",
  [anon_sym_u16] = "u16",
  [anon_sym_u32] = "u32",
  [anon_sym_u64] = "u64",
  [anon_sym_float32] = "float32",
  [anon_sym_float64] = "float64",
  [anon_sym_char] = "char",
  [anon_sym_string] = "string",
  [anon_sym_func] = "func",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_package] = "package",
  [anon_sym_COLON] = ":",
  [anon_sym_AT] = "@",
  [anon_sym_list] = "list",
  [anon_sym_tuple] = "tuple",
  [sym_identifier] = "identifier",
  [sym_version] = "version",
  [anon_sym_world] = "world",
  [anon_sym_import] = "import",
  [sym_line_comment] = "line_comment",
  [sym_block_comment] = "block_comment",
  [sym_ident] = "ident",
  [sym_unit] = "unit",
  [sym_star] = "star",
  [anon_sym_COMMA] = ",",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_option] = "option",
  [anon_sym_result] = "result",
  [anon_sym_future] = "future",
  [anon_sym_stream] = "stream",
  [anon_sym_as] = "as",
  [anon_sym_use] = "use",
  [anon_sym_from] = "from",
  [anon_sym_record] = "record",
  [anon_sym_flags] = "flags",
  [anon_sym_variant] = "variant",
  [anon_sym_enum] = "enum",
  [anon_sym_union] = "union",
  [anon_sym_static] = "static",
  [anon_sym_resource] = "resource",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_interface] = "interface",
  [sym__interface_content] = "_interface_content",
  [sym_type_definition] = "type_definition",
  [sym_type] = "type",
  [sym_function_declaration] = "function_declaration",
  [sym_package] = "package",
  [sym_list] = "list",
  [sym_tuple] = "tuple",
  [sym_world] = "world",
  [sym_import] = "import",
  [sym_ty] = "ty",
  [sym_tp1] = "tp1",
  [sym_tp2] = "tp2",
  [sym_tps] = "tps",
  [sym_option] = "option",
  [sym_result] = "result",
  [sym_future] = "future",
  [sym_stream] = "stream",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_interface_repeat1] = "interface_repeat1",
  [aux_sym_world_repeat1] = "world_repeat1",
  [aux_sym_tps_repeat1] = "tps_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_interface] = anon_sym_interface,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_s8] = anon_sym_s8,
  [anon_sym_s16] = anon_sym_s16,
  [anon_sym_s32] = anon_sym_s32,
  [anon_sym_s64] = anon_sym_s64,
  [anon_sym_u8] = anon_sym_u8,
  [anon_sym_u16] = anon_sym_u16,
  [anon_sym_u32] = anon_sym_u32,
  [anon_sym_u64] = anon_sym_u64,
  [anon_sym_float32] = anon_sym_float32,
  [anon_sym_float64] = anon_sym_float64,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_func] = anon_sym_func,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_list] = anon_sym_list,
  [anon_sym_tuple] = anon_sym_tuple,
  [sym_identifier] = sym_identifier,
  [sym_version] = sym_version,
  [anon_sym_world] = anon_sym_world,
  [anon_sym_import] = anon_sym_import,
  [sym_line_comment] = sym_line_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_ident] = sym_ident,
  [sym_unit] = sym_unit,
  [sym_star] = sym_star,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_option] = anon_sym_option,
  [anon_sym_result] = anon_sym_result,
  [anon_sym_future] = anon_sym_future,
  [anon_sym_stream] = anon_sym_stream,
  [anon_sym_as] = anon_sym_as,
  [anon_sym_use] = anon_sym_use,
  [anon_sym_from] = anon_sym_from,
  [anon_sym_record] = anon_sym_record,
  [anon_sym_flags] = anon_sym_flags,
  [anon_sym_variant] = anon_sym_variant,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_union] = anon_sym_union,
  [anon_sym_static] = anon_sym_static,
  [anon_sym_resource] = anon_sym_resource,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_interface] = sym_interface,
  [sym__interface_content] = sym__interface_content,
  [sym_type_definition] = sym_type_definition,
  [sym_type] = sym_type,
  [sym_function_declaration] = sym_function_declaration,
  [sym_package] = sym_package,
  [sym_list] = sym_list,
  [sym_tuple] = sym_tuple,
  [sym_world] = sym_world,
  [sym_import] = sym_import,
  [sym_ty] = sym_ty,
  [sym_tp1] = sym_tp1,
  [sym_tp2] = sym_tp2,
  [sym_tps] = sym_tps,
  [sym_option] = sym_option,
  [sym_result] = sym_result,
  [sym_future] = sym_future,
  [sym_stream] = sym_stream,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_interface_repeat1] = aux_sym_interface_repeat1,
  [aux_sym_world_repeat1] = aux_sym_world_repeat1,
  [aux_sym_tps_repeat1] = aux_sym_tps_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_interface] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_func] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_package] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_list] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tuple] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_version] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_world] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_ident] = {
    .visible = true,
    .named = true,
  },
  [sym_unit] = {
    .visible = true,
    .named = true,
  },
  [sym_star] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_option] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_result] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_future] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_stream] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_as] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_use] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_from] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_record] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_flags] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_variant] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_union] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_static] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_resource] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_interface] = {
    .visible = true,
    .named = true,
  },
  [sym__interface_content] = {
    .visible = false,
    .named = true,
  },
  [sym_type_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_function_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_package] = {
    .visible = true,
    .named = true,
  },
  [sym_list] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple] = {
    .visible = true,
    .named = true,
  },
  [sym_world] = {
    .visible = true,
    .named = true,
  },
  [sym_import] = {
    .visible = true,
    .named = true,
  },
  [sym_ty] = {
    .visible = true,
    .named = true,
  },
  [sym_tp1] = {
    .visible = true,
    .named = true,
  },
  [sym_tp2] = {
    .visible = true,
    .named = true,
  },
  [sym_tps] = {
    .visible = true,
    .named = true,
  },
  [sym_option] = {
    .visible = true,
    .named = true,
  },
  [sym_result] = {
    .visible = true,
    .named = true,
  },
  [sym_future] = {
    .visible = true,
    .named = true,
  },
  [sym_stream] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_interface_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_world_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tps_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_function_name = 1,
  field_import = 2,
  field_import_name = 3,
  field_name = 4,
  field_namespace = 5,
  field_return_type = 6,
  field_type = 7,
  field_type_name = 8,
  field_version = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_function_name] = "function_name",
  [field_import] = "import",
  [field_import_name] = "import_name",
  [field_name] = "name",
  [field_namespace] = "namespace",
  [field_return_type] = "return_type",
  [field_type] = "type",
  [field_type_name] = "type_name",
  [field_version] = "version",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 2},
  [6] = {.index = 8, .length = 1},
  [7] = {.index = 9, .length = 3},
  [8] = {.index = 12, .length = 2},
  [9] = {.index = 14, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_import, 0},
  [2] =
    {field_name, 3},
    {field_namespace, 1},
  [4] =
    {field_import, 3, .inherited = true},
    {field_name, 1},
  [6] =
    {field_import, 0, .inherited = true},
    {field_import, 1, .inherited = true},
  [8] =
    {field_import_name, 1},
  [9] =
    {field_name, 3},
    {field_namespace, 1},
    {field_version, 5},
  [12] =
    {field_type, 3},
    {field_type_name, 1},
  [14] =
    {field_function_name, 1},
    {field_return_type, 5},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(115);
      if (lookahead == '(') ADVANCE(162);
      if (lookahead == ')') ADVANCE(163);
      if (lookahead == '*') ADVANCE(262);
      if (lookahead == ',') ADVANCE(263);
      if (lookahead == '-') ADVANCE(19);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == ':') ADVANCE(166);
      if (lookahead == ';') ADVANCE(121);
      if (lookahead == '<') ADVANCE(264);
      if (lookahead == '=') ADVANCE(120);
      if (lookahead == '>') ADVANCE(265);
      if (lookahead == '@') ADVANCE(167);
      if (lookahead == '_') ADVANCE(261);
      if (lookahead == 'a') ADVANCE(96);
      if (lookahead == 'b') ADVANCE(78);
      if (lookahead == 'c') ADVANCE(53);
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == 'f') ADVANCE(60);
      if (lookahead == 'i') ADVANCE(68);
      if (lookahead == 'l') ADVANCE(54);
      if (lookahead == 'o') ADVANCE(84);
      if (lookahead == 'p') ADVANCE(20);
      if (lookahead == 'r') ADVANCE(39);
      if (lookahead == 's') ADVANCE(8);
      if (lookahead == 't') ADVANCE(108);
      if (lookahead == 'u') ADVANCE(9);
      if (lookahead == 'v') ADVANCE(21);
      if (lookahead == 'w') ADVANCE(76);
      if (lookahead == '{') ADVANCE(117);
      if (lookahead == '}') ADVANCE(118);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(5);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(210);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '%') ADVANCE(114);
      if (lookahead == '>') ADVANCE(265);
      if (lookahead == '_') ADVANCE(261);
      if (lookahead == 'b') ADVANCE(242);
      if (lookahead == 'c') ADVANCE(231);
      if (lookahead == 'f') ADVANCE(236);
      if (lookahead == 'l') ADVANCE(232);
      if (lookahead == 'o') ADVANCE(245);
      if (lookahead == 'r') ADVANCE(228);
      if (lookahead == 's') ADVANCE(212);
      if (lookahead == 't') ADVANCE(257);
      if (lookahead == 'u') ADVANCE(213);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '.') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(211);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 8:
      if (lookahead == '1') ADVANCE(17);
      if (lookahead == '3') ADVANCE(10);
      if (lookahead == '6') ADVANCE(14);
      if (lookahead == '8') ADVANCE(125);
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 9:
      if (lookahead == '1') ADVANCE(18);
      if (lookahead == '3') ADVANCE(11);
      if (lookahead == '6') ADVANCE(15);
      if (lookahead == '8') ADVANCE(137);
      if (lookahead == 'n') ADVANCE(56);
      if (lookahead == 's') ADVANCE(40);
      END_STATE();
    case 10:
      if (lookahead == '2') ADVANCE(131);
      END_STATE();
    case 11:
      if (lookahead == '2') ADVANCE(143);
      END_STATE();
    case 12:
      if (lookahead == '2') ADVANCE(149);
      END_STATE();
    case 13:
      if (lookahead == '3') ADVANCE(12);
      if (lookahead == '6') ADVANCE(16);
      END_STATE();
    case 14:
      if (lookahead == '4') ADVANCE(134);
      END_STATE();
    case 15:
      if (lookahead == '4') ADVANCE(146);
      END_STATE();
    case 16:
      if (lookahead == '4') ADVANCE(152);
      END_STATE();
    case 17:
      if (lookahead == '6') ADVANCE(128);
      END_STATE();
    case 18:
      if (lookahead == '6') ADVANCE(140);
      END_STATE();
    case 19:
      if (lookahead == '>') ADVANCE(164);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == 'o') ADVANCE(28);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(52);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(88);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(67);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(105);
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(74);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(100);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(35);
      END_STATE();
    case 30:
      if (lookahead == 'b') ADVANCE(196);
      if (lookahead == 'c') ADVANCE(189);
      if (lookahead == 'f') ADVANCE(194);
      if (lookahead == 'l') ADVANCE(190);
      if (lookahead == 's') ADVANCE(174);
      if (lookahead == 't') ADVANCE(205);
      if (lookahead == 'u') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(30)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 31:
      if (lookahead == 'c') ADVANCE(59);
      END_STATE();
    case 32:
      if (lookahead == 'c') ADVANCE(161);
      END_STATE();
    case 33:
      if (lookahead == 'c') ADVANCE(282);
      END_STATE();
    case 34:
      if (lookahead == 'c') ADVANCE(45);
      END_STATE();
    case 35:
      if (lookahead == 'c') ADVANCE(46);
      END_STATE();
    case 36:
      if (lookahead == 'c') ADVANCE(82);
      if (lookahead == 's') ADVANCE(83);
      END_STATE();
    case 37:
      if (lookahead == 'd') ADVANCE(208);
      END_STATE();
    case 38:
      if (lookahead == 'd') ADVANCE(277);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(36);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(275);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(119);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(171);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(270);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(165);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(283);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(116);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == 'i') ADVANCE(73);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 49:
      if (lookahead == 'f') ADVANCE(29);
      END_STATE();
    case 50:
      if (lookahead == 'g') ADVANCE(158);
      END_STATE();
    case 51:
      if (lookahead == 'g') ADVANCE(97);
      END_STATE();
    case 52:
      if (lookahead == 'g') ADVANCE(44);
      END_STATE();
    case 53:
      if (lookahead == 'h') ADVANCE(24);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(98);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(80);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 59:
      if (lookahead == 'k') ADVANCE(23);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 'r') ADVANCE(77);
      if (lookahead == 'u') ADVANCE(72);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(122);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(37);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(42);
      END_STATE();
    case 64:
      if (lookahead == 'l') ADVANCE(102);
      END_STATE();
    case 65:
      if (lookahead == 'm') ADVANCE(280);
      END_STATE();
    case 66:
      if (lookahead == 'm') ADVANCE(276);
      END_STATE();
    case 67:
      if (lookahead == 'm') ADVANCE(272);
      END_STATE();
    case 68:
      if (lookahead == 'm') ADVANCE(87);
      if (lookahead == 'n') ADVANCE(104);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(107);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(281);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(266);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(32);
      if (lookahead == 't') ADVANCE(109);
      END_STATE();
    case 73:
      if (lookahead == 'n') ADVANCE(50);
      END_STATE();
    case 74:
      if (lookahead == 'n') ADVANCE(103);
      END_STATE();
    case 75:
      if (lookahead == 'o') ADVANCE(61);
      END_STATE();
    case 76:
      if (lookahead == 'o') ADVANCE(92);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(66);
      END_STATE();
    case 78:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 79:
      if (lookahead == 'o') ADVANCE(70);
      END_STATE();
    case 80:
      if (lookahead == 'o') ADVANCE(71);
      END_STATE();
    case 81:
      if (lookahead == 'o') ADVANCE(95);
      END_STATE();
    case 82:
      if (lookahead == 'o') ADVANCE(90);
      END_STATE();
    case 83:
      if (lookahead == 'o') ADVANCE(110);
      if (lookahead == 'u') ADVANCE(64);
      END_STATE();
    case 84:
      if (lookahead == 'p') ADVANCE(106);
      END_STATE();
    case 85:
      if (lookahead == 'p') ADVANCE(63);
      END_STATE();
    case 86:
      if (lookahead == 'p') ADVANCE(41);
      END_STATE();
    case 87:
      if (lookahead == 'p') ADVANCE(81);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(155);
      END_STATE();
    case 89:
      if (lookahead == 'r') ADVANCE(49);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 91:
      if (lookahead == 'r') ADVANCE(58);
      END_STATE();
    case 92:
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 93:
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 94:
      if (lookahead == 'r') ADVANCE(43);
      END_STATE();
    case 95:
      if (lookahead == 'r') ADVANCE(101);
      END_STATE();
    case 96:
      if (lookahead == 's') ADVANCE(274);
      END_STATE();
    case 97:
      if (lookahead == 's') ADVANCE(278);
      END_STATE();
    case 98:
      if (lookahead == 's') ADVANCE(99);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(168);
      END_STATE();
    case 100:
      if (lookahead == 't') ADVANCE(13);
      END_STATE();
    case 101:
      if (lookahead == 't') ADVANCE(209);
      END_STATE();
    case 102:
      if (lookahead == 't') ADVANCE(268);
      END_STATE();
    case 103:
      if (lookahead == 't') ADVANCE(279);
      END_STATE();
    case 104:
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 105:
      if (lookahead == 't') ADVANCE(55);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(57);
      END_STATE();
    case 107:
      if (lookahead == 'u') ADVANCE(65);
      END_STATE();
    case 108:
      if (lookahead == 'u') ADVANCE(85);
      if (lookahead == 'y') ADVANCE(86);
      END_STATE();
    case 109:
      if (lookahead == 'u') ADVANCE(94);
      END_STATE();
    case 110:
      if (lookahead == 'u') ADVANCE(93);
      END_STATE();
    case 111:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(111)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 112:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(207);
      END_STATE();
    case 113:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      END_STATE();
    case 114:
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_interface);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_bool);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_bool);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_s8);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_s8);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_s8);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_s16);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_s16);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_s16);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_s32);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_s32);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_s32);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_s64);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_s64);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_s64);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_u8);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_u8);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_u8);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_u16);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_u16);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_u16);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_u32);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_u32);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_u32);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_u64);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_u64);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_u64);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_float32);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_float32);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_float32);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_float64);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_float64);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_float64);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_char);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_char);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_string);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_string);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_list);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_list);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_list);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_tuple);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_tuple);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_tuple);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(183);
      if (lookahead == '3') ADVANCE(176);
      if (lookahead == '6') ADVANCE(180);
      if (lookahead == '8') ADVANCE(127);
      if (lookahead == 't') ADVANCE(201);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(184);
      if (lookahead == '3') ADVANCE(177);
      if (lookahead == '6') ADVANCE(181);
      if (lookahead == '8') ADVANCE(139);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2') ADVANCE(133);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2') ADVANCE(145);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2') ADVANCE(151);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '3') ADVANCE(178);
      if (lookahead == '6') ADVANCE(182);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4') ADVANCE(136);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4') ADVANCE(148);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4') ADVANCE(154);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6') ADVANCE(130);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6') ADVANCE(142);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(200);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(204);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(173);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(160);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(185);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(202);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(195);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(124);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(187);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(198);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(188);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(197);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(192);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(186);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(193);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(157);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(191);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(203);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(170);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(179);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(199);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_version);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(207);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_world);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_line_comment);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_block_comment);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '1') ADVANCE(221);
      if (lookahead == '3') ADVANCE(214);
      if (lookahead == '6') ADVANCE(218);
      if (lookahead == '8') ADVANCE(126);
      if (lookahead == 't') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '1') ADVANCE(222);
      if (lookahead == '3') ADVANCE(215);
      if (lookahead == '6') ADVANCE(219);
      if (lookahead == '8') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '2') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '2') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '2') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '3') ADVANCE(216);
      if (lookahead == '6') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '4') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '4') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '4') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '6') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == '6') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'a') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'a') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'a') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(223);
      if (lookahead == 'i') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'g') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'h') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'i') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'i') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'l') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'l') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'l') ADVANCE(243);
      if (lookahead == 'u') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'l') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'm') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'n') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'n') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'o') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'o') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'o') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'o') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'p') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'p') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'r') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'r') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'r') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 's') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 's') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 't') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 't') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 't') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 't') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 't') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'u') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'u') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (lookahead == 'u') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_unit);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_star);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(anon_sym_option);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(anon_sym_option);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_result);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(anon_sym_result);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(anon_sym_future);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(anon_sym_future);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(anon_sym_stream);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(anon_sym_stream);
      if (lookahead == '-') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(260);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(anon_sym_as);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(anon_sym_use);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_from);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(anon_sym_record);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_flags);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_variant);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_union);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_static);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_resource);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 30},
  [10] = {.lex_state = 30},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 111},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 111},
  [64] = {.lex_state = 111},
  [65] = {.lex_state = 111},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 111},
  [74] = {.lex_state = 111},
  [75] = {.lex_state = 111},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_interface] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_s8] = ACTIONS(1),
    [anon_sym_s16] = ACTIONS(1),
    [anon_sym_s32] = ACTIONS(1),
    [anon_sym_s64] = ACTIONS(1),
    [anon_sym_u8] = ACTIONS(1),
    [anon_sym_u16] = ACTIONS(1),
    [anon_sym_u32] = ACTIONS(1),
    [anon_sym_u64] = ACTIONS(1),
    [anon_sym_float32] = ACTIONS(1),
    [anon_sym_float64] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_func] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_list] = ACTIONS(1),
    [anon_sym_tuple] = ACTIONS(1),
    [sym_version] = ACTIONS(1),
    [anon_sym_world] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(1),
    [sym_block_comment] = ACTIONS(1),
    [sym_unit] = ACTIONS(1),
    [sym_star] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_option] = ACTIONS(1),
    [anon_sym_result] = ACTIONS(1),
    [anon_sym_future] = ACTIONS(1),
    [anon_sym_stream] = ACTIONS(1),
    [anon_sym_as] = ACTIONS(1),
    [anon_sym_use] = ACTIONS(1),
    [anon_sym_from] = ACTIONS(1),
    [anon_sym_record] = ACTIONS(1),
    [anon_sym_flags] = ACTIONS(1),
    [anon_sym_variant] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_union] = ACTIONS(1),
    [anon_sym_static] = ACTIONS(1),
    [anon_sym_resource] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(72),
    [sym__definition] = STATE(11),
    [sym_interface] = STATE(11),
    [sym_package] = STATE(11),
    [sym_world] = STATE(11),
    [aux_sym_source_file_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_interface] = ACTIONS(5),
    [anon_sym_package] = ACTIONS(7),
    [anon_sym_world] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    ACTIONS(17), 1,
      anon_sym_GT,
    ACTIONS(19), 1,
      anon_sym_option,
    ACTIONS(21), 1,
      anon_sym_result,
    ACTIONS(23), 1,
      anon_sym_future,
    ACTIONS(25), 1,
      anon_sym_stream,
    STATE(44), 1,
      sym_ty,
    STATE(48), 6,
      sym_list,
      sym_tuple,
      sym_option,
      sym_result,
      sym_future,
      sym_stream,
    ACTIONS(11), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_ident,
  [49] = 10,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    ACTIONS(19), 1,
      anon_sym_option,
    ACTIONS(21), 1,
      anon_sym_result,
    ACTIONS(23), 1,
      anon_sym_future,
    ACTIONS(25), 1,
      anon_sym_stream,
    ACTIONS(27), 1,
      anon_sym_GT,
    STATE(44), 1,
      sym_ty,
    STATE(48), 6,
      sym_list,
      sym_tuple,
      sym_option,
      sym_result,
      sym_future,
      sym_stream,
    ACTIONS(11), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_ident,
  [98] = 10,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    ACTIONS(19), 1,
      anon_sym_option,
    ACTIONS(21), 1,
      anon_sym_result,
    ACTIONS(23), 1,
      anon_sym_future,
    ACTIONS(25), 1,
      anon_sym_stream,
    ACTIONS(29), 1,
      sym_unit,
    STATE(46), 1,
      sym_ty,
    STATE(48), 6,
      sym_list,
      sym_tuple,
      sym_option,
      sym_result,
      sym_future,
      sym_stream,
    ACTIONS(11), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_ident,
  [147] = 9,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    ACTIONS(19), 1,
      anon_sym_option,
    ACTIONS(21), 1,
      anon_sym_result,
    ACTIONS(23), 1,
      anon_sym_future,
    ACTIONS(25), 1,
      anon_sym_stream,
    STATE(44), 1,
      sym_ty,
    STATE(48), 6,
      sym_list,
      sym_tuple,
      sym_option,
      sym_result,
      sym_future,
      sym_stream,
    ACTIONS(11), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_ident,
  [193] = 9,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    ACTIONS(19), 1,
      anon_sym_option,
    ACTIONS(21), 1,
      anon_sym_result,
    ACTIONS(23), 1,
      anon_sym_future,
    ACTIONS(25), 1,
      anon_sym_stream,
    STATE(76), 1,
      sym_ty,
    STATE(48), 6,
      sym_list,
      sym_tuple,
      sym_option,
      sym_result,
      sym_future,
      sym_stream,
    ACTIONS(11), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_ident,
  [239] = 9,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    ACTIONS(19), 1,
      anon_sym_option,
    ACTIONS(21), 1,
      anon_sym_result,
    ACTIONS(23), 1,
      anon_sym_future,
    ACTIONS(25), 1,
      anon_sym_stream,
    STATE(56), 1,
      sym_ty,
    STATE(48), 6,
      sym_list,
      sym_tuple,
      sym_option,
      sym_result,
      sym_future,
      sym_stream,
    ACTIONS(11), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_ident,
  [285] = 9,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    ACTIONS(19), 1,
      anon_sym_option,
    ACTIONS(21), 1,
      anon_sym_result,
    ACTIONS(23), 1,
      anon_sym_future,
    ACTIONS(25), 1,
      anon_sym_stream,
    STATE(29), 1,
      sym_ty,
    STATE(48), 6,
      sym_list,
      sym_tuple,
      sym_option,
      sym_result,
      sym_future,
      sym_stream,
    ACTIONS(11), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_ident,
  [331] = 5,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    STATE(77), 1,
      sym_type,
    STATE(69), 2,
      sym_list,
      sym_tuple,
    ACTIONS(31), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_identifier,
  [361] = 5,
    ACTIONS(13), 1,
      anon_sym_list,
    ACTIONS(15), 1,
      anon_sym_tuple,
    STATE(55), 1,
      sym_type,
    STATE(69), 2,
      sym_list,
      sym_tuple,
    ACTIONS(31), 14,
      anon_sym_bool,
      anon_sym_s8,
      anon_sym_s16,
      anon_sym_s32,
      anon_sym_s64,
      anon_sym_u8,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_float32,
      anon_sym_float64,
      anon_sym_char,
      anon_sym_string,
      sym_identifier,
  [391] = 5,
    ACTIONS(5), 1,
      anon_sym_interface,
    ACTIONS(7), 1,
      anon_sym_package,
    ACTIONS(9), 1,
      anon_sym_world,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    STATE(12), 5,
      sym__definition,
      sym_interface,
      sym_package,
      sym_world,
      aux_sym_source_file_repeat1,
  [411] = 5,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(37), 1,
      anon_sym_interface,
    ACTIONS(40), 1,
      anon_sym_package,
    ACTIONS(43), 1,
      anon_sym_world,
    STATE(12), 5,
      sym__definition,
      sym_interface,
      sym_package,
      sym_world,
      aux_sym_source_file_repeat1,
  [431] = 4,
    ACTIONS(46), 1,
      anon_sym_RBRACE,
    ACTIONS(48), 1,
      anon_sym_type,
    ACTIONS(51), 1,
      anon_sym_func,
    STATE(13), 4,
      sym__interface_content,
      sym_type_definition,
      sym_function_declaration,
      aux_sym_interface_repeat1,
  [447] = 4,
    ACTIONS(54), 1,
      anon_sym_RBRACE,
    ACTIONS(56), 1,
      anon_sym_type,
    ACTIONS(58), 1,
      anon_sym_func,
    STATE(15), 4,
      sym__interface_content,
      sym_type_definition,
      sym_function_declaration,
      aux_sym_interface_repeat1,
  [463] = 4,
    ACTIONS(56), 1,
      anon_sym_type,
    ACTIONS(58), 1,
      anon_sym_func,
    ACTIONS(60), 1,
      anon_sym_RBRACE,
    STATE(13), 4,
      sym__interface_content,
      sym_type_definition,
      sym_function_declaration,
      aux_sym_interface_repeat1,
  [479] = 1,
    ACTIONS(62), 4,
      ts_builtin_sym_end,
      anon_sym_interface,
      anon_sym_package,
      anon_sym_world,
  [486] = 1,
    ACTIONS(64), 4,
      ts_builtin_sym_end,
      anon_sym_interface,
      anon_sym_package,
      anon_sym_world,
  [493] = 1,
    ACTIONS(66), 4,
      ts_builtin_sym_end,
      anon_sym_interface,
      anon_sym_package,
      anon_sym_world,
  [500] = 1,
    ACTIONS(68), 4,
      ts_builtin_sym_end,
      anon_sym_interface,
      anon_sym_package,
      anon_sym_world,
  [507] = 4,
    ACTIONS(70), 1,
      anon_sym_RBRACE,
    ACTIONS(72), 1,
      anon_sym_import,
    STATE(20), 1,
      aux_sym_world_repeat1,
    STATE(52), 1,
      sym_import,
  [520] = 4,
    ACTIONS(75), 1,
      anon_sym_RBRACE,
    ACTIONS(77), 1,
      anon_sym_import,
    STATE(20), 1,
      aux_sym_world_repeat1,
    STATE(52), 1,
      sym_import,
  [533] = 3,
    ACTIONS(81), 1,
      anon_sym_LT,
    STATE(50), 1,
      sym_tp2,
    ACTIONS(79), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [544] = 3,
    ACTIONS(85), 1,
      anon_sym_LT,
    STATE(51), 1,
      sym_tp1,
    ACTIONS(83), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [555] = 1,
    ACTIONS(87), 4,
      ts_builtin_sym_end,
      anon_sym_interface,
      anon_sym_package,
      anon_sym_world,
  [562] = 4,
    ACTIONS(77), 1,
      anon_sym_import,
    ACTIONS(89), 1,
      anon_sym_RBRACE,
    STATE(21), 1,
      aux_sym_world_repeat1,
    STATE(52), 1,
      sym_import,
  [575] = 1,
    ACTIONS(91), 4,
      ts_builtin_sym_end,
      anon_sym_interface,
      anon_sym_package,
      anon_sym_world,
  [582] = 3,
    ACTIONS(81), 1,
      anon_sym_LT,
    STATE(40), 1,
      sym_tp2,
    ACTIONS(93), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [593] = 1,
    ACTIONS(95), 3,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_func,
  [599] = 3,
    ACTIONS(97), 1,
      anon_sym_COMMA,
    ACTIONS(99), 1,
      anon_sym_GT,
    STATE(35), 1,
      aux_sym_tps_repeat1,
  [609] = 1,
    ACTIONS(101), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_GT,
  [615] = 1,
    ACTIONS(103), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_GT,
  [621] = 1,
    ACTIONS(105), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_GT,
  [627] = 1,
    ACTIONS(107), 3,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_func,
  [633] = 1,
    ACTIONS(109), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_GT,
  [639] = 3,
    ACTIONS(17), 1,
      anon_sym_GT,
    ACTIONS(111), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_tps_repeat1,
  [649] = 1,
    ACTIONS(113), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_GT,
  [655] = 1,
    ACTIONS(115), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_GT,
  [661] = 3,
    ACTIONS(117), 1,
      anon_sym_COMMA,
    ACTIONS(120), 1,
      anon_sym_GT,
    STATE(38), 1,
      aux_sym_tps_repeat1,
  [671] = 2,
    ACTIONS(122), 1,
      anon_sym_LT,
    STATE(34), 1,
      sym_tps,
  [678] = 1,
    ACTIONS(124), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [683] = 1,
    ACTIONS(126), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [688] = 1,
    ACTIONS(128), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [693] = 2,
    ACTIONS(85), 1,
      anon_sym_LT,
    STATE(36), 1,
      sym_tp1,
  [700] = 1,
    ACTIONS(120), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [705] = 1,
    ACTIONS(130), 2,
      anon_sym_RBRACE,
      anon_sym_import,
  [710] = 2,
    ACTIONS(132), 1,
      anon_sym_COMMA,
    ACTIONS(134), 1,
      anon_sym_GT,
  [717] = 2,
    ACTIONS(136), 1,
      anon_sym_SEMI,
    ACTIONS(138), 1,
      anon_sym_AT,
  [724] = 1,
    ACTIONS(140), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [729] = 2,
    ACTIONS(85), 1,
      anon_sym_LT,
    STATE(53), 1,
      sym_tp1,
  [736] = 1,
    ACTIONS(142), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [741] = 1,
    ACTIONS(144), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [746] = 1,
    ACTIONS(146), 2,
      anon_sym_RBRACE,
      anon_sym_import,
  [751] = 1,
    ACTIONS(148), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [756] = 1,
    ACTIONS(150), 1,
      anon_sym_EQ,
  [760] = 1,
    ACTIONS(152), 1,
      anon_sym_SEMI,
  [764] = 1,
    ACTIONS(154), 1,
      anon_sym_GT,
  [768] = 1,
    ACTIONS(156), 1,
      anon_sym_LPAREN,
  [772] = 1,
    ACTIONS(158), 1,
      anon_sym_DASH_GT,
  [776] = 1,
    ACTIONS(160), 1,
      sym_version,
  [780] = 1,
    ACTIONS(162), 1,
      anon_sym_SEMI,
  [784] = 1,
    ACTIONS(164), 1,
      sym_identifier,
  [788] = 1,
    ACTIONS(166), 1,
      anon_sym_RPAREN,
  [792] = 1,
    ACTIONS(168), 1,
      sym_identifier,
  [796] = 1,
    ACTIONS(170), 1,
      sym_identifier,
  [800] = 1,
    ACTIONS(172), 1,
      sym_identifier,
  [804] = 1,
    ACTIONS(132), 1,
      anon_sym_COMMA,
  [808] = 1,
    ACTIONS(174), 1,
      anon_sym_SEMI,
  [812] = 1,
    ACTIONS(176), 1,
      anon_sym_LBRACE,
  [816] = 1,
    ACTIONS(178), 1,
      anon_sym_SEMI,
  [820] = 1,
    ACTIONS(180), 1,
      anon_sym_COLON,
  [824] = 1,
    ACTIONS(182), 1,
      anon_sym_LBRACE,
  [828] = 1,
    ACTIONS(184), 1,
      ts_builtin_sym_end,
  [832] = 1,
    ACTIONS(186), 1,
      sym_identifier,
  [836] = 1,
    ACTIONS(188), 1,
      sym_identifier,
  [840] = 1,
    ACTIONS(190), 1,
      sym_identifier,
  [844] = 1,
    ACTIONS(192), 1,
      anon_sym_GT,
  [848] = 1,
    ACTIONS(194), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 49,
  [SMALL_STATE(4)] = 98,
  [SMALL_STATE(5)] = 147,
  [SMALL_STATE(6)] = 193,
  [SMALL_STATE(7)] = 239,
  [SMALL_STATE(8)] = 285,
  [SMALL_STATE(9)] = 331,
  [SMALL_STATE(10)] = 361,
  [SMALL_STATE(11)] = 391,
  [SMALL_STATE(12)] = 411,
  [SMALL_STATE(13)] = 431,
  [SMALL_STATE(14)] = 447,
  [SMALL_STATE(15)] = 463,
  [SMALL_STATE(16)] = 479,
  [SMALL_STATE(17)] = 486,
  [SMALL_STATE(18)] = 493,
  [SMALL_STATE(19)] = 500,
  [SMALL_STATE(20)] = 507,
  [SMALL_STATE(21)] = 520,
  [SMALL_STATE(22)] = 533,
  [SMALL_STATE(23)] = 544,
  [SMALL_STATE(24)] = 555,
  [SMALL_STATE(25)] = 562,
  [SMALL_STATE(26)] = 575,
  [SMALL_STATE(27)] = 582,
  [SMALL_STATE(28)] = 593,
  [SMALL_STATE(29)] = 599,
  [SMALL_STATE(30)] = 609,
  [SMALL_STATE(31)] = 615,
  [SMALL_STATE(32)] = 621,
  [SMALL_STATE(33)] = 627,
  [SMALL_STATE(34)] = 633,
  [SMALL_STATE(35)] = 639,
  [SMALL_STATE(36)] = 649,
  [SMALL_STATE(37)] = 655,
  [SMALL_STATE(38)] = 661,
  [SMALL_STATE(39)] = 671,
  [SMALL_STATE(40)] = 678,
  [SMALL_STATE(41)] = 683,
  [SMALL_STATE(42)] = 688,
  [SMALL_STATE(43)] = 693,
  [SMALL_STATE(44)] = 700,
  [SMALL_STATE(45)] = 705,
  [SMALL_STATE(46)] = 710,
  [SMALL_STATE(47)] = 717,
  [SMALL_STATE(48)] = 724,
  [SMALL_STATE(49)] = 729,
  [SMALL_STATE(50)] = 736,
  [SMALL_STATE(51)] = 741,
  [SMALL_STATE(52)] = 746,
  [SMALL_STATE(53)] = 751,
  [SMALL_STATE(54)] = 756,
  [SMALL_STATE(55)] = 760,
  [SMALL_STATE(56)] = 764,
  [SMALL_STATE(57)] = 768,
  [SMALL_STATE(58)] = 772,
  [SMALL_STATE(59)] = 776,
  [SMALL_STATE(60)] = 780,
  [SMALL_STATE(61)] = 784,
  [SMALL_STATE(62)] = 788,
  [SMALL_STATE(63)] = 792,
  [SMALL_STATE(64)] = 796,
  [SMALL_STATE(65)] = 800,
  [SMALL_STATE(66)] = 804,
  [SMALL_STATE(67)] = 808,
  [SMALL_STATE(68)] = 812,
  [SMALL_STATE(69)] = 816,
  [SMALL_STATE(70)] = 820,
  [SMALL_STATE(71)] = 824,
  [SMALL_STATE(72)] = 828,
  [SMALL_STATE(73)] = 832,
  [SMALL_STATE(74)] = 836,
  [SMALL_STATE(75)] = 840,
  [SMALL_STATE(76)] = 844,
  [SMALL_STATE(77)] = 848,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(73),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(75),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(74),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_repeat1, 2),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_repeat1, 2), SHIFT_REPEAT(64),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_repeat1, 2), SHIFT_REPEAT(63),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface, 4, .production_id = 1),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 7, .production_id = 7),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_world, 5, .production_id = 4),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_world, 4, .production_id = 1),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_world_repeat1, 2, .production_id = 5),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_world_repeat1, 2, .production_id = 5), SHIFT_REPEAT(61),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stream, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_future, 1),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface, 5, .production_id = 1),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 5, .production_id = 3),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_result, 1),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 7, .production_id = 9),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tps, 5),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tp1, 3),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tps, 3),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_definition, 5, .production_id = 8),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple, 2),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tps, 4),
  [117] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tps_repeat1, 2), SHIFT_REPEAT(5),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tps_repeat1, 2),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_result, 2),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tp2, 5),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tp2, 3),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 3, .production_id = 6),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ty, 1),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stream, 2),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_future, 2),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_world_repeat1, 1, .production_id = 2),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [184] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_wit() {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
