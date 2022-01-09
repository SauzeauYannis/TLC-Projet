%{

#include <iostream>
#include "printer.hh"

extern int yylex();
void yyerror(const char* s) {
	std::cerr << "ERREUR: " << s << std::endl;	
}

%}

%code requires {
	#include "printer.hh"
}

%union {
	char ident[255];
	double value;
  	Instruction* inst;
  	Expression* expr;
}

%token DOWN UP
%token MOVE LINE RECTANGLE
%token COLOR COLOR_VAL
%token OPADD OPSUB OPMUL OPDIV
%token VAR
%token LOOP END
%token AFFECT
%token SC
%token LPAR RPAR COMMA

%token<ident> ID
%token<value> NUM

%type<inst> declaration code instruction affectation loop move color
%type<expr> pos value op

%left OPADD OPSUB
%left OPMUL OPDIV


%start program

%%

program: code { }
;

code: code instruction SC {
	Code *c = new Code($2);
	c->add($1);
	$$ = c;
}
| { }
;

instruction: 
  declaration { $$ = $1; }
| affectation { $$ = $1; }
| loop 		  { $$ = $1; }
| move 	      { $$ = $1; }
| color 	  { $$ = $1; }
| DOWN 		  { $$ = new Pen(true); }
| UP 		  { $$ = new Pen(false); }
;

declaration: VAR ID {
	Declaration *d = new Declaration($2);
	free ($2);
	$$ = d;	  
 }
| VAR ID AFFECT value {
	Declaration *d = new Declaration($2);
	Affectation *a = new Affectation($2, $4);
	free($2);
}
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

/* int main(int argc, char *argv[]){
    int res = yyparse();
	std::cout << "RES=" << res << std::endl
			  << "Le programme fourni respecte notre syntaxe ? " 
			  << (res == 0 ? "Oui" : "Non") << std::endl;
	return res == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
} */
