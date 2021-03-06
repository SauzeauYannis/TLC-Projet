#include "printer.hh"

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace cimg_library;

void Printer::visitPen(const Pen *p) {
    if (p->getIsDown()) {
        if (is_down) {
            std::cout << "Le stylo est deja baisse" << std::endl;;
        } else {
            is_down = true;
            std::cout << "Le stylo se baisse" << std::endl;;
        }
    } else {
        if (!is_down) {
            std::cout << "Le stylo est deja leve" << std::endl;;
        } else {
            is_down = false;
            std::cout << "Le stylo se leve" << std::endl;;
        }
    }
}

void Printer::visitProgram(const Program *p) {
	std::cout << "Debut du programme" << std::endl;
	p->getCode()->visit(*this);
    char* cstr = new char[name.length()+1];
    std::strcpy (cstr, name.c_str());
	img.save_bmp(cstr);
    if (display) {
        CImgDisplay disp;
        disp.display(img);
        while (!disp.is_closed()) {
            if (disp.key() == cimg::keyQ) disp.close();
            disp.wait();
        }
    }
    std::cout << "Fin du programme" << std::endl;
}

void Printer::visitEntete(const Entete *e) {
    e->getTaille()->visit(*this);
	img = CImg<unsigned char>(bufferPosition.first, bufferPosition.second, Z_SIZE, NB_CAN); 
	e->getColor()->visit(*this);
    img.fill(color[0], color[1], color[2]);
    color[0] = 0; color[1] = 0; color[2] = 0;
    name = e->getName();
    name = "Exemple/" + name.substr(1, name.size() - 2) + ".bmp";
    display = e->getAffiche();
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
        std::cout << "On declare une nouvelle variable nommee " << d->getVar() << std::endl;
    } else {
        std::cerr << "[ERREUR] La variable " << d->getVar() << " est deja declare" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Printer::visitAffectation(const Affectation *a) {
    if (vars.find(a->getVar()) != vars.end() && std::find(protectedVar.begin(), protectedVar.end(), a->getVar()) == protectedVar.end() ) {
        a->getExpr()->visit(*this);
        vars[a->getVar()] = buffer_expr;
        std::cout << "On met la valeur " << vars[a->getVar()] << " dans la variable " << a->getVar() << std::endl;
    } else {
        std::cerr << "[ERREUR] La variable " << a->getVar() << " n'existe pas" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Printer::visitLoop(const Loop *l) {
    if (vars.find(l->getIncr()) == vars.end()) {
        l->getMin()->visit(*this);
        double min = buffer_expr;
        l->getMax()->visit(*this);
        double max = buffer_expr;
        if (std::find(protectedVar.begin(), protectedVar.end(), l->getIncr()) == protectedVar.end()) {
            protectedVar.push_back(l->getIncr());	    
            for (double i = min; i <= max; i++) {
                vars[l->getIncr()] = i;	
                std::cout << l->getIncr() << " = " << i << std::endl;
                if (l->getBody() != NULL) l->getBody()->visit(*this);
            }
            vars.erase(l->getIncr());
            protectedVar.pop_back();
        }
    } else {
        std::cerr << "[ERREUR] La variable " << l->getIncr() << " est en lecture seule et ne peut donc pas ??tre affectee" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Printer::visitTravel(const Travel *t) {
	std::pair<double, double> previousPosition = bufferPosition;
	t->getPosition()->visit(*this);
	if (is_down)
		img.draw_line(previousPosition.first, previousPosition.second, bufferPosition.first, bufferPosition.second, color);
    std::cout << "On bouge en (" << bufferPosition.first << ", " << bufferPosition.second << ")" << std::endl;
}

void Printer::visitColor(const Color *c) {
    std::string colorHex = c->getColor().substr(1);
    char* cstr = new char[colorHex.length()+1];
    std::strcpy (cstr, colorHex.c_str());
    sscanf(cstr, "%02hhx%02hhx%02hhx", &color[0], &color[1], &color[2]);
    std::cout << "On change la couleur en rgb(" << (int)color[0] << ", " << (int)color[1] << ", " << (int)color[2] << ")" << std::endl;
    delete[] cstr;
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
        default: { // N'arrive normalement jamais ici
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
	std::cout << "Position = (" << bufferPosition.first << ", " << bufferPosition.second << ")" << std::endl;
}

void Printer::visitVar(const Var *v){
    if (vars.find(v->getIdent()) != vars.end()) {
   	    buffer_expr = vars[v->getIdent()];
        std::cout << "Var " << v->getIdent() << " egal a " << buffer_expr << std::endl;
    } else {
        std::cerr << "[ERREUR] La variable " << v->getIdent() << " n'existe pas" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Printer::visitRectangle(const Rectangle *r) {
	r->getStart()->visit(*this);
    std::pair<double, double> start = bufferPosition;
	r->getOpposed()->visit(*this);
	std::pair<double, double> opposed = bufferPosition;
    is_down = true;
    img.draw_rectangle(start.first, start.second, opposed.first, opposed.second, color);
	std::cout << "Rectangle : (" << start.first << ", " << start.second <<") "<<
		"(" << start.first << ", " << opposed.second <<") " <<
	 	"(" << opposed.first << ", " << opposed.second <<") " <<
		"(" << opposed.first << ", " << start.second <<")" << std::endl;
}
