#include "token.h"
#include <stdlib.h>

#ifndef TOKEN_LIST
#define TOKEN_LIST

typedef struct jl_token_list {
  jl_token_t **list;
  size_t size;
  int count;
  int index;
} jl_token_list_t;

#endif

jl_token_list_t *jl_token_list_new();
void jl_token_list_add(jl_token_list_t *list, jl_token_t *token);
jl_token_t *jl_token_list_advance(jl_token_list_t *list);
jl_token_t *jl_token_list_peek(jl_token_list_t *list, int distance);
