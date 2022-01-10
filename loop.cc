#include "loop.hh"

Loop::Loop(std::string incr, Expression* min, Expression* max, Instruction *instr) :
       incr(incr), min(min), max(max), body(instr)
{
}

Loop::~Loop(){
	delete(max);
	delete(min);
	delete(body);
}

void Loop::visit(Visitor& visitor) const{
	return visitor.visitLoop(this);
}
