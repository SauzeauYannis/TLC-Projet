#include "rectangle.hh"

Rectangle::Rectangle(Expression *start, Expression *opposed):
	start(start), opposed(opposed)
{
}

Rectangle::~Rectangle(){
	delete(start);
	delete(opposed);
}

void Rectangle::visit(Visitor& visitor) const{
	return visitor.visitRectangle(this);
}

