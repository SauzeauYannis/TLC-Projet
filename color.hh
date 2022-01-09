#ifndef _COLOR_H
#define _COLOR_H

#include "instruction.hh"

class Color : public Instruction {
	string color;
 public:
	Color(string color);
	~Color();

	inline string getColor() const {return color;}

	void visit(Visitor& visitor) const;
};

#endif
