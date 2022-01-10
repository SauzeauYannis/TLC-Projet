#include "parseur.tab.hh"
#include "printer.hh"

extern Instruction *fullinstruction; // variable retenant le resultat final du parser...

int main(int argc, char **argv) {
  int res = yyparse();
	std::cout << "RES=" << res << std::endl
			  << "Le programme fourni respecte notre syntaxe ? " 
			  << (res == 0 ? "Oui" : "Non") << std::endl;
  Printer printer;
  if (fullinstruction != NULL)
    fullinstruction->visit(printer);
  return EXIT_SUCCESS;
}
