%{
#include <iostream>
extern int yylex();
void yyerror(const char* s){
	std::cerr<<"ERREUR: " << s << std::endl;	
}

%}

%token VAR
%token LOOP END_LOOP
%token ID INT
%token DOWN UP
%token MOVE RECTANGLE
%token COLOR
%token OPADD OPSUB OPMUL OPDIV
%token LPAR RPAR
%token AFFECT
%token SC

%%

program:code;

code: code instruction
| ;

instruction: declaration
| affectation
| loop 
| vert_move
| horiz_move
| color;

declaration: VAR ID SC
| VAR affectation;

affectation: ID AFFECT value SC;

loop: LOOP ID value value SC code END_LOOP SC;

vert_move: MOVE value SC
| RECTANGLE value SC;

horiz_move: DOWN SC
| UP SC;

color: COLOR ID SC;

value: INT
| ID
| LPAR value op value RPAR;

op : OPADD
| OPSUB
| OPMUL
| OPDIV;


%%

int main(int argc, char *argv[]){
	yyparse();
	return EXIT_SUCCESS;
}


