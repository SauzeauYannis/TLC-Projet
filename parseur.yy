%{

#include <iostream>
#include "printer.hh"

Instruction *fullinstruction = NULL;

extern int yylex();
void yyerror(const char* s) {
	std::cerr << "ERREUR: " << s << std::endl;	
}

%}

%define parse.error verbose

%code requires {
	#include "printer.hh"
}

%union {
	char ident[255];
	char name[255];
	char color[7];
	double value;
  	Instruction* inst;
  	Expression* expr;
}

%token SIZE NAME DISPLAY
%token MOVE LINE RECTANGLE
%token COLOR
%token OPADD OPSUB OPMUL OPDIV
%token VAR
%token LOOP END
%token AFFECT
%token SC
%token LPAR RPAR COMMA

%token<ident> ID
%token<name> NAME_W
%token<value> NUM
%token<color> COLOR_VAL
%token<inst> DOWN UP

%type<inst> program header code instruction declaration affectation loop move color
%type<expr> pos value

%left OPADD OPSUB
%left OPMUL OPDIV

%start program

%%

program: header code { 
    Code *c = new Code($1);
    c->add($2);
    fullinstruction =  new Program(c);
}
;

header: SIZE pos SC NAME NAME_W SC {
	$$ = new Entete($2, $5, false);
}
| SIZE pos SC NAME NAME_W SC DISPLAY SC {
	$$ = new Entete($2, $5, true);
}
| { $$ = new Entete(new Position(new Value(800), new Value(600)), "\"dessin\"", false); }
;

code: code instruction SC {
	Code *c = new Code($1);
	c->add($2);
	$$ = c;
}
| { $$ = NULL; }
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
	$$ = new Affectation($1, $3);	  
}
;

loop: LOOP ID value value SC code END LOOP { $$ = new Loop($2, $3, $4, $6); }
;

move: MOVE pos 		{ $$ = new Travel($2); }
| RECTANGLE pos pos { $$ = new Rectangle($2, $3); }
| LINE pos pos 		{
	Pen *p = new Pen(false);
	Travel *t = new Travel($2);
	Pen *p2 = new Pen(true);
	Travel *t2 = new Travel($3);
	Code *code = new Code(p);
	code->add(t);
	code->add(p2);
	code->add(t2);
	$$ = code;
}
;

color: COLOR COLOR_VAL { $$ = new Color($2); }
;

value: NUM 			{ $$ = new Value($1); }
| ID 				{ $$ = new Var($1); }
| value OPADD value { $$ = new Operator(ADD, $1, $3); }
| value OPSUB value { $$ = new Operator(SUB, $1, $3); }
| value OPMUL value { $$ = new Operator(MUL, $1, $3); }
| value OPDIV value { $$ = new Operator(DIV, $1, $3); }
;

pos: LPAR value COMMA value RPAR { $$ = new Position($2, $4); }
;

%%
