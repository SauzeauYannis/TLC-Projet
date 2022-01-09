#include "printer.hh"

#include <iostream>

void Printer::visitPen(const Pen *p) {
    if (p->getIsDown()) {
        is_down = true;
        std::cout << "Le stylo se baisse" << std::endl;;
    } else {
        is_down = false;
        std::cout << "Le style se leve" << std::endl;;
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
    std::cout << "TODO" << std::endl;
}

void Printer::visitAffectation(const Affectation *a) {
    std::cout << "TODO" << std::endl;
}

void Printer::visitLoop(const Loop *l) {
    std::cout << "TODO" << std::endl;
}

void Printer::visitMove(const Move *m) {
    std::cout << "TODO" << std::endl;
}

void Printer::visitColor(const Color *c) {
    std::cout << "TODO" << std::endl;
}

void Printer::visitValue(const Value *v) {
    std::cout << "TODO" << std::endl;
}

void Printer::visitOperator(const Operator *o) {
    std::cout << "TODO" << std::endl;
}

void Printer::visitPosition(const Position *p) {
    std::cout << "TODO" << std::endl;
}