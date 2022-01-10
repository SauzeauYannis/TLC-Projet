#include "affectation.hh"

Affectation::Affectation(std::string var, Expression *expr) :
var(var), expr(expr){
	
}

Affectation::~Affectation(){
	delete expr;
}

void Affectation::visit(Visitor& visitor) const{
	return visitor.visitAffectation(this);
}

