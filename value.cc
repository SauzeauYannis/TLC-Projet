#include "value.hh"

Value::Value(double value) : value(value){
}

Value::~Value(){}

void Value::visit(Visitor& visitor) const{
	return visitor.visitValue(this);
}
