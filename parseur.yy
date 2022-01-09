%{

#include <iostream>
#include "printer.hh"

extern int yylex();
void yyerror(const char* s) {
	std::cerr << "ERREUR: " << s << std::endl;	
}

%}

%code requires{
#include "printer.hh"
}

%token DOWN UP
%token MOVE LINE RECTANGLE
%token COLOR COLOR_VAL
%token VAR
%token OPADD OPSUB OPMUL OPDIV
%token LOOP END
%token AFFECT
%token SC
%token LPAR RPAR COMMA
%token NUM ID

%left OPADD OPSUB
%left OPMUL OPDIVi

%type<instruction> declaration code instruction affectation loop move color
%type<expression> pos value op 

%start program

%%

program: code { }
;

code: code instruction SC { }
| { }
;

instruction: 
  declaration { }
| affectation { }
| loop { }
| move { }
| color { }
| DOWN { }
| UP { }
;

declaration: VAR ID { }
| VAR affectation { }
;

affectation: ID AFFECT value { }
;

loop: LOOP ID value value SC code END LOOP { }
;

move: MOVE pos { }
| LINE pos pos { }
| RECTANGLE pos pos { }
;

color: COLOR COLOR_VAL { }
;

value: NUM { }
| ID { }
| value op value { }
| LPAR value op value RPAR { }
;

op : OPADD { }
| OPSUB { }
| OPMUL { }
| OPDIV { }
;

pos: LPAR value COMMA value RPAR { }
;

%%

int main(int argc, char *argv[]){
    int res = yyparse();
	std::cout << "RES=" << res << std::endl
			  << "Le programme fourni respecte notre syntaxe ? " 
			  << (res == 0 ? "Oui" : "Non") << std::endl;
	return res == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
