%{

#include "parseur.tab.hh"

%}

%%

baisser { return DOWN; }
lever   { return UP; }

deplacer { return MOVE; }
ligne    { return LINE; }
rect     { return RECTANGLE; }

couleur        { return COLOR; }
[a-fA-F0-9]{6} { return COLOR_VAL; }

var { return VAR; }

"+" { return OPADD; }
"-" { return OPSUB; }
"*" { return OPMUL; }
"/" { return OPDIV; }

boucle { return LOOP; }
fin    { return END; }

"<-" { return AFFECT; }

";" { return SC; }

"(" { return LPAR; }
")" { return RPAR; }
"," { return COMMA; }

[0-9]+                { yylval.value = atoi(yytext); return NUM; }
[a-zA-Z][a-zA-Z0-9_]* { strcpy(yylval.ident, yytext); return ID; }

.|\n {}

%%
