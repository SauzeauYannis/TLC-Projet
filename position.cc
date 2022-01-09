#include "position.hh"

Position::Position(double x, double y): x(x), y(y){

}

Position::~Position(){}

void Position::visit(Visitor& visitor) const{
	return visitor.visitPosition(this);
}
