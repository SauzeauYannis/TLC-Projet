%{
#include <assert.h>

#define DOWN 258;
#define UP 259;
#define MOVE 260;
#define COLOR 261;
#define RECTANGLE 262;
#define VAR 263;
#define OPADD 264;
#define OPSUB 265;
#define OPMUL 266;
#define OPDIV 267;
#define END_LOOP 268;
#define LOOP 269;
#define AFFECT 270;
#define SC 271;
#define LPAR 272;
#define RPAR 273;
#define INT 274;
#define ID 275;

%}

%%
down {return DOWN;}
up {return UP;}
move {return MOVE;}
color {return COLOR;}
rect {return RECTANGLE;}
var {return VAR;}
"+" {return OPADD;}
"-" {return OPSUB;}
"*" {return OPMUL;}
"/" {return OPDIV;}
end_loop {return END_LOOP;}
loop {return LOOP;}
"<-" {return AFFECT;}
";" {return SC;}
"(" {return LPAR;}
")" {return RPAR;}
[0-9]+ {return INT;}
[a-zA-Z][a-zA-Z0-9_]* {return ID;}


[\t\n] ;

. {return yytext[0];}
%%

