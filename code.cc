#include "code.hh"

CodeItem::CodeItem(Instruction *i, CodeItem *next)
  : i(i), next(next)
{
}

CodeItem::~CodeItem() {
  delete i;
  if(next != NULL)
    delete next;
}

void CodeItem::add(Instruction *i) {
  if(next == NULL)
    next = new CodeItem(i);
  else
    next->add(i);  
}

Code::Code(Instruction *inst)
  : first(NULL)
{
  std::cout << "Je construit le code" << std::endl;
  if(inst != NULL)
    first = new CodeItem(inst);
}

Code::~Code() {
  if(first != NULL)
    delete first;
}

void Code::visit(Visitor& visitor) const {
  std::cout << "Je visite le code" << std::endl;
  visitor.visitCode(this);
}

void Code::add(Instruction *i) {
  std::cout << "J'ajoute le code" << std::endl;
  if (first == NULL)
    first = new CodeItem(i,first);
  else
    first->add(i);
}