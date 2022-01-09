#include "declaration.hh"

Declaration::Declaration(std::string var) : var(var) {
}

Declaration::~Declaration(){

}

void Declaration::visit(Visitor& visitor) const{
	return visitor.visitDeclaration(this);
}
