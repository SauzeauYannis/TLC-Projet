#include "travel.hh"
Travel::Travel(Expression *pos): pos(pos){

}

Travel::~Travel(){
	delete(pos);
}

void Travel::visit(Visitor& visitor) const{
	return visitor.visitTravel(this);
}
