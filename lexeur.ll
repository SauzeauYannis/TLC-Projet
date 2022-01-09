%{

%}

%%
down {return DOWN}
up {return UP}
move {return MOVE}
color {return COLOR}
[0-9]+ {return INT}
rect {return RECTANGLE}
var {return var}
[a-zA-Z_][a-zA-Z0-9_]* {return ID}
"+" {return OPADD}
"-" {return OOPSUB}
"*" {return OPMUL}
"/" {return OPDIV}
loop {return LOOP}
end_loop {return END_LOOP}
"<-" {return AFFECT}
";" {return SC}
"(" {return LPAR}
")" {return RPAR}

%%

