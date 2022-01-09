#include "color.hh"

Color::Color(std::string color) : color(color) {

}

Color::~Color(){}

void Color::visit(Visitor& visitor) const{
	return visitor.visitColor(this);
}
