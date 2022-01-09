#ifndef _COLOR_H
#define _COLOR_H

#include "instruction.hh"

#include <iostream>

class Color : public Instruction {
	std::string color;
 public:
	Color(std::string color);
	~Color();

	inline std::string getColor() const {return color;}

	void visit(Visitor& visitor) const;
};

#endif
