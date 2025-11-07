#include "debug.h"
#include "interpreter/interpreter.h"
#include "parser/parser.h"
#include "program.h"
#include "scan.h"
#include "source_code.h"
#include "token/token_list.h"
#include "vm.h"

void execute(char *file) {
  jl_source_code_t *src = jl_source_code_from_file(file);
  jl_token_list_t *tokens = scan(src);
  jl_program_t *program = parse(tokens, NULL);
  //   debug(tokens, program);
  vm_t *vm = vm_new();
  vm_push_frame(vm, stack_new(), false);
  interprete(program, vm);
}
