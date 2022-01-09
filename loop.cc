#include "loop.hh"

Loop::Loop(Instruction *instr) : body(instr){

}

Loop::~Loop(){
	delete(body);
}

void Loop::visit(Visitor& visitor) const{
	return visitor.visitLoop(this);
}
