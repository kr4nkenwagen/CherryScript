#include "source_code.h"
#include "token/token_list.h"

void clear_buffer(jl_source_code_t *src);
jl_token_list_t *scan(jl_source_code_t *src);
