#include "execute_file.h"
#include "repl.h"

int main(int argc, char *argv[]) {
  // l_token_list_t *tokens = scan(jl_source_code_from_file("test.jonx"));

  // jl_program_t *syntax = pars5dwxxe(tokens);
  if (argc > 1) {
    execute(argv[1]);
  } else {
    repl();
  }
  return 0;
}
