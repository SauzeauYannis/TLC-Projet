#include "position.hh"

Position::Position(Expression *x, Expression *y): x(x), y(y){

}

Position::~Position(){}

void Position::visit(Visitor& visitor) const{
	return visitor.visitPosition(this);
}
