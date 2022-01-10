#include "pen.hh"

Pen::Pen(bool is_down) : is_down(is_down) {
  std::cout << "Je construit le pen" << std::endl;
}

Pen::~Pen() {

}

void Pen::visit(Visitor& visitor) const {
  return visitor.visitPen(this);
}
