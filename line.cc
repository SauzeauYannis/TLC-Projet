#include "line.hh"

Line::Line(Expression *start, Expression *end) :
	start(start), end(end)
{
}

Line::~Line(){
	delete(start);
	delete(end);
}

void Line::visit(Visitor& visitor) const{
	return visitor.visitLine(this);	
}
