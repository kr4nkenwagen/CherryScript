#include "../program.h"
#include "../syntax/syntax.h"
#include "../vm.h"

void eval_while(jl_syntax_t *syntax, vm_t *vm, jl_program_t *program);
void eval_for(jl_syntax_t *syntax, vm_t *vm, jl_program_t *program);
void eval_if(jl_syntax_t *syntax, vm_t *vm, jl_program_t *program);
void eval_return(jl_syntax_t *syntax, vm_t *vm, jl_program_t *program);
void eval_break(jl_syntax_t *syntax, vm_t *vm, jl_program_t *program);
void eval_continue(jl_syntax_t *syntax, vm_t *vm, jl_program_t *program);
void eval_error(jl_syntax_t *syntax, vm_t *vm, jl_program_t *program);
void eval_out(jl_syntax_t *syntax, vm_t *vm, jl_program_t *program);
