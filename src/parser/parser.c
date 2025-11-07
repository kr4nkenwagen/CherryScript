#include "parser.h"
#include "../error.h"
#include "../object/object.h"
#include "../syntax/syntax.h"
#include "../token/token.h"
#include "../token/token_list.h"
#include "parse_expressions.h"
#include "parse_function.h"
#include "parse_logic.h"
#include "parse_variables.h"
#include <string.h>

jl_program_t *parse_branch(jl_token_list_t *tokens, jl_program_t *parent) {
  if (jl_token_list_peek(tokens, 0)->type == TERMINATOR) {
    jl_token_list_advance(tokens);
  }
  if (jl_token_list_peek(tokens, 0)->type != LEFT_BRACE) {
    err_bracket_not_opened(jl_token_list_peek(tokens, 0));
    return NULL;
  }
  jl_program_t *program = jl_new_program(parent);
  jl_token_list_advance(tokens);
  while (jl_token_list_peek(tokens, 0)->type != RIGHT_BRACE) {
    if (jl_token_list_peek(tokens, 0)->type == END_OF_FILE) {
      err_unexpected_eof(jl_token_list_peek(tokens, 0));
      return NULL;
    }
    jl_syntax_t *syntax = NULL;
    jl_syntax_t *prev_syntax = NULL;
    while (jl_token_list_peek(tokens, 0)->type != TERMINATOR &&
           jl_token_list_peek(tokens, 0)->type != RIGHT_BRACE) {
      if (syntax == NULL) {
        syntax = parse_statement(tokens, program);
        prev_syntax = syntax;
        continue;
      }
      syntax = parse_statement(tokens, program);
      if (syntax == NULL) {
        continue;
      }
      syntax->left = prev_syntax;
      prev_syntax = syntax;
    }
    jl_token_list_advance(tokens);
    jl_program_add(program, syntax);
  }
  jl_token_list_advance(tokens);
  return program;
}

jl_syntax_t *parse_line(jl_token_list_t *tokens, jl_program_t *parent) {
  jl_syntax_t *syntax = NULL;
  jl_syntax_t *prev_syntax = NULL;
  while (jl_token_list_peek(tokens, 0)->type != TERMINATOR &&
         jl_token_list_peek(tokens, 0)->type != RIGHT_PAREN) {
    if (syntax == NULL) {
      syntax = parse_statement(tokens, parent);
      prev_syntax = syntax;
      continue;
    }
    syntax = parse_statement(tokens, parent);
    if (syntax == NULL) {
      continue;
    }
    syntax->left = prev_syntax;
    prev_syntax = syntax;
  }
  while (jl_token_list_peek(tokens, 0)->type == TERMINATOR) {
    jl_token_list_advance(tokens);
  }
  return syntax;
}

jl_program_t *parse(jl_token_list_t *tokens, jl_program_t *parent) {
  jl_program_t *program = jl_new_program(parent);
  while (jl_token_list_peek(tokens, 0)->type != END_OF_FILE) {
    jl_syntax_t *syntax = NULL;
    jl_syntax_t *prev_syntax = NULL;
    while (jl_token_list_peek(tokens, 0)->type != TERMINATOR &&
           jl_token_list_peek(tokens, 0)->type != RIGHT_BRACE &&
           jl_token_list_peek(tokens, 0)->type != LEFT_BRACE) {
      if (syntax == NULL) {
        syntax = parse_statement(tokens, parent);
        prev_syntax = syntax;
        continue;
      }
      syntax = parse_statement(tokens, parent);
      if (syntax == NULL) {
        continue;
      }
      syntax->left = prev_syntax;
      prev_syntax = syntax;
    }
    jl_token_list_advance(tokens);
    jl_program_add(program, syntax);
  }
  return program;
}
