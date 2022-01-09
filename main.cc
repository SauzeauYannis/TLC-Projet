#include "parseur.tab.hh"
#include "printer.hh"

Instruction *fullinstruction = NULL;

int main(int argc, char **argv) {
  yyparse();
  Printer printer;
  if (fullinstruction)
    fullinstruction->visit(printer);
  return EXIT_SUCCESS;
}
