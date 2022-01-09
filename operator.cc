#include "operator.hh"

Operator::Operator(OperatorSymbol sym, Expression *l, Expression *r) :
	symbol(sym), left(l), right(r){

}

Operator::~Operator(){
	delete(left);
	delete(right);
}

void Operator::visit(Visitor& visitor) const{
	return visitor.visitOperator(this);
}
