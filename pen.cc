#include "pen.hh"

Pen::Pen(bool is_down) : is_down(is_down) {

}

Pen::~Pen() {

}

void Pen::visit(Visitor& visitor) const {
  return visitor.visitPen(this);
}
