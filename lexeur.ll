%{

#include "parseur.tab.hh"

%}

%%

"/*"([^/]|\n)*"*/"|"//".*\n {}

taille            { return SIZE; }
nom               { return NAME; }
\"[a-zA-Z0-9_]+\" { strcpy(yylval.name, yytext); return NAME_W; }
affiche           { return DISPLAY; }

baisser { return DOWN; }
lever   { return UP; }

deplacer { return MOVE; }
ligne    { return LINE; }
rect     { return RECTANGLE; }

couleur         { return COLOR; }
#[a-fA-F0-9]{6} { strcpy(yylval.color, yytext); return COLOR_VAL; }

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

[0-9]+[.]?[0-9]*      { yylval.value = atof(yytext); return NUM; }
[a-zA-Z][a-zA-Z0-9_]* { strcpy(yylval.ident, yytext); return ID; }

.|\n {}

%%
