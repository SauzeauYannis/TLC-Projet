#include "entete.hh"

Entete::Entete(Expression *taille, std::string name; bool affiche) :
	taille(taille), name(name), affiche(affiche)
{
}

Entete::~Entete(){
	delete(taille);
}

void Entete::visit(Visitor& visitor) const {
	return visitor.visitEntete(this);

}


