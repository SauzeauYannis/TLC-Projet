%{

#include <iostream>
#include "printer.hh"

Instruction *fullinstruction = NULL;

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
	char color[7];
	double value;
  	Instruction* inst;
  	Expression* expr;
}

%token MOVE LINE RECTANGLE
%token COLOR
%token OPADD OPSUB OPMUL OPDIV
%token VAR
%token LOOP END
%token AFFECT
%token SC
%token LPAR RPAR COMMA

%token<ident> ID
%token<value> NUM
%token<color> COLOR_VAL
%token<inst> DOWN UP

%type<inst> code instruction declaration affectation loop move color
%type<expr> pos value

%left OPADD OPSUB
%left OPMUL OPDIV

%start program

%%

program: code { fullinstruction = $1; }
;

code: code instruction SC {
	Code *c = new Code($1);
	c->add($2);
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

declaration: VAR ID AFFECT value {
	Declaration *d = new Declaration($2);
	Affectation *a = new Affectation($2, $4);
	Code *code = new Code(d);
	code->add(a);
	$$ = code;
}
| VAR ID {
	Declaration *d = new Declaration($2);
	$$ = d;
}
;

affectation: ID AFFECT value {
	$$ = new Affectation( $1, $3);	  
}
;

loop: LOOP ID value value SC code END LOOP { $$ = new Loop($2, $3, $4, $6); }
;

move: MOVE pos { $$ = new Travel($2); }
| LINE pos pos { $$ = new Line($2, $3); }
| RECTANGLE pos pos { $$ = new Rectangle($2, $3); }
;

color: COLOR COLOR_VAL { $$ = new Color($2); }
;

value: NUM 			{ $$ = new Value($1);}
| ID 				{ $$ = new Var($1); }
| value OPADD value { $$ = new Operator(ADD, $1, $3);}
| value OPSUB value { $$ = new Operator(SUB, $1, $3);}
| value OPMUL value { $$ = new Operator(MUL, $1, $3);}
| value OPDIV value { $$ = new Operator(DIV, $1, $3);}
;

pos: LPAR value COMMA value RPAR { $$ = new Position($2, $4); }
;

%%
