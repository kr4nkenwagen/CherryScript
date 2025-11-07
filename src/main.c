#include "execute_file.h"
#include "repl.h"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    execute(argv[1]);
  } else {
    repl();
  }
  return 0;
}
