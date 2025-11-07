#include "../object/object.h"
#include "../token/token.h"

#ifndef SYNTAX
#define SYNTAX

typedef struct jl_syntax jl_syntax_t;

typedef struct jl_syntax {
  jl_token_t *token;
  jl_syntax_t *left;
  jl_syntax_t *right;
  jl_syntax_t *value;
  void *branch;
  void *args;
} jl_syntax_t;

#endif

jl_syntax_t *jl_syntax_new();
