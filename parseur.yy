%{
extern "C" int yylex();
void yyeror(const char* s);
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

loop: FOR ID value value SC code END_LOOP SC;

vert_move: MOVE VALUE SC
| RECTANGLE VALUE SC;

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


