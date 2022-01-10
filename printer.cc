#include "printer.hh"

#include <iostream>

void Printer::visitPen(const Pen *p) {
    if (p->getIsDown()) {
        if (is_down) {
            std::cout << "Le stylo est deja baisser" << std::endl;;
        } else {
            is_down = true;
            std::cout << "Le stylo se baisse" << std::endl;;
        }
    } else {
        if (!is_down) {
            std::cout << "Le stylo est deja lever" << std::endl;;
        } else {
            is_down = false;
            std::cout << "Le stylo se leve" << std::endl;;
        }
    }
}

void Printer::visitCode(const Code *c) {
    CodeItem *t = c->getFirst();
    while (t != NULL) {
        t->getInst()->visit(*this);
        t = t->getNext();
    }
}

void Printer::visitDeclaration(const Declaration *d) {
    vars[d->getVar()] = 0;    
    for( const auto& n : vars) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
    std::cout << "On declare une nouvelle variable nomme " << d->getVar() << std::endl;
}

void Printer::visitAffectation(const Affectation *a) {

// coment récupéré la valeur d'une expression ?
	if(vars.contains(a->getVar())){
		a->getExpr()->visit(*this);
		vars[a->getVar()] = (int)bufferNUM;
    
		std::cout << "La variable " <<a->getVar() << " vaut "<< bufferNUM << std::endl;
	}
}

void Printer::visitLoop(const Loop *l) {
	if(vars.contains->getIncr()){
		l->getMin()->visit(*this);
		double min = bufferNUM;
		l->getMax()->visit(*this);
		double max = bufferNUM;
		for(double i=min; i<= max; i++){
			vars[l->getIncr()] = i;	
    			std::cout << l->getIncr() << " =  " << i << std::endl;
		}
	}
}

void Printer::visitTravel(const Travel *m) {
		
       	std::cout << "TODO" << std::endl;
}

void Printer::visitColor(const Color *c) {
    std::cout << "TODO" << std::endl;
}

void Printer::visitValue(const Value *v) {
   	bufferNUM = v->getValue();
       	std::cout << "Valeur : " << v->getValue() << std::endl;
}

void Printer::visitOperator(const Operator *o) {
	o->getLeft()->visit(*this);
	double left = bufferNUM;
	o->getRight()->visit(*this);
	double right = bufferNUM;
	switch(o->getSymbol()){
		case ADD: bufferNUM = left + right; break;
		case SUB: bufferNUM = left - right; break;
		case MUL: bufferNUM = left * right; break;
		case DIV: bufferNUM = left / right; break;
		default :
	}
	std::cout << "Operation = " << bufferNUM  << std::endl;
}

void Printer::visitPosition(const Position *p) {
	p->getX()->visit(*this);
     	double x = bufferNUM;
	p->getY()->visit(*this);
	double y = bufferNUM;	
	bufferPosition = std::pair<double, double>(x, y);
	std::cout << "Position[x,y] = [" << x << "," << y << "]" << std::endl;
}

void Printer::visitVar(const Var *v){
    std::cout << "TODO" << std::endl;
}
