#ifndef _PEN_H
#define _PEN_H

#include "instruction.hh"

class Pen : public Instruction {
	bool is_down;
 public:
	Pen(bool is_down);
	~Pen();

    inline const bool getIsDown() const { return is_down; }
		  
	void visit(Visitor& visitor) const;
};

#endif
