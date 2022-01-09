#ifndef _CODE_H
#define _CODE_H

#include "instruction.hh"

class CodeItem {
  Instruction *i;
  CodeItem *next;
public:
  CodeItem(Instruction *i, CodeItem *next = NULL);
  ~CodeItem();

  inline const Instruction* getInst() const { return i; }
  inline bool hasNext() const { return (next != NULL); }
  inline CodeItem* getNext() const { return next; }

  void add(Instruction *i);
};

class Code : public Instruction {
  CodeItem *first;
public:
  Code(Instruction *first = NULL);
  ~Code();
  
  inline CodeItem* getFirst() const { return first; }

  void visit(Visitor& visitor) const;

  void add(Instruction *i);
};

#endif
