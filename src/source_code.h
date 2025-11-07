#include <stdbool.h>
#include <stddef.h>

#ifndef SOURCE
#define SOURCE

typedef struct jl_source_code {
  bool is_at_end;
  size_t size;
  int pointer;
  int line;
  int column;
  char *src;
} jl_source_code_t;

#endif

jl_source_code_t *jl_source_code_new();
jl_source_code_t *jl_source_code_from_file(char *src);
jl_source_code_t *jl_source_code_from_repl(char *line);
char jl_source_code_advance(jl_source_code_t *src);
char jl_source_code_peek(jl_source_code_t *src, int distance);
void jl_source_code_import_file(jl_source_code_t *target, char *src);
