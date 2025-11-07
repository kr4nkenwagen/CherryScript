#include "../object/object.h"
#include "../program.h"
#include "../syntax/syntax.h"
#include "../vm.h"

void eval_function_declaration(jl_syntax_t *syntax, vm_t *vm,
                               jl_program_t *program);
jl_object_t *eval_function_identifier(jl_syntax_t *syntax, vm_t *vm,
                                      jl_program_t *program);
