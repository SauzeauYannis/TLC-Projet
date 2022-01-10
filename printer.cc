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
    if (vars.find(d->getVar()) == vars.end()) {
        vars[d->getVar()] = 0;    
        std::cout << "On declare une nouvelle variable nomme " << d->getVar() << std::endl;
    } else {
        std::cerr << "[ERREUR] La variable " << d->getVar() << " est deja declare" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Printer::visitAffectation(const Affectation *a) {
    if (vars.find(a->getVar()) != vars.end()) {
        a->getExpr()->visit(*this);
        vars[a->getVar()] = buffer_expr;
        std::cout << "On met la valeur " << vars[a->getVar()] << " dans la variable " << a->getVar() << std::endl;
    } else {
        std::cerr << "[ERREUR] La variable " << a->getVar() << " n'existe pas" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Printer::visitLoop(const Loop *l) {
    l->getMin()->visit(*this);
    double min = buffer_expr;
    l->getMax()->visit(*this);
    double max = buffer_expr;
    for(double i=min; i<= max; i++){
        vars[l->getIncr()] = i;	
            std::cout << l->getIncr() << " =  " << i << std::endl;
    }
}

void Printer::visitTravel(const Travel *m) {
	m->getPosition()->visit(*this);
}

void Printer::visitColor(const Color *c) {
    std::cout << "TODO" << std::endl;
}

void Printer::visitValue(const Value *v) {
   	buffer_expr = v->getValue();
    std::cout << "On recupere une valeur egale a " << v->getValue() << std::endl;
}

void Printer::visitOperator(const Operator *o) {
	o->getLeft()->visit(*this);
	double left = buffer_expr;
	o->getRight()->visit(*this);
	double right = buffer_expr;
	switch (o->getSymbol()) {
		case ADD: buffer_expr = left + right; break;
		case SUB: buffer_expr = left - right; break;
		case MUL: buffer_expr = left * right; break;
		case DIV: buffer_expr = left / right; break;
        default: {
            std::cerr << "[ERREUR] L'operateur " << o->getSymbol() << " n'existe pas" << std::endl;
            exit(EXIT_FAILURE);
        }
	}
	std::cout << "Operation = " << buffer_expr  << std::endl;
}

void Printer::visitPosition(const Position *p) {
	p->getX()->visit(*this);
    double x = buffer_expr;
	p->getY()->visit(*this);
	double y = buffer_expr;	
	bufferPosition = std::pair<double, double>(x, y);
	std::cout << "Position[x,y] = [" << x << "," << y << "]" << std::endl;
}

void Printer::visitVar(const Var *v){
   	buffer_expr = vars[v->getIdent()];
    std::cout << "Var " << v->getIdent() << " egal " << buffer_expr << std::endl;
}

void Printer::visitRectangle(const Rectangle *r){
	r->getStart()->visit(*this);
       	std::pair<double, double> start = bufferPosition;
	r->getOpposed()->visit(*this);
	std::pair<double, double> opposed = bufferPosition;	
       
	std::cout << "Rectangle : (" << start.first << "," << start.second <<") "<<
		"(" << start.first << "," << opposed.second <<") " <<
	 	"(" << opposed.first << "," << opposed.second <<") " <<
		"(" << opposed.first << "," << start.second <<")" << std::endl;
}

void Printer::visitLine(const Line *l) {
	l->getStart()->visit(*this);
	std::pair<double, double> start = bufferPosition;
	l->getEnd()->visit(*this);
	std::pair<double, double> end = bufferPosition;
	
	std::cout << "Line between (" <<start.first << "," << start.second << ") et (" <<
	       end.first << "," << end.second << ")" << std::endl;
}
