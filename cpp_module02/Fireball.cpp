#include "Fireball.hpp"
#include "ASpell.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball(void) {}

ASpell *Fireball::clone(void) const { return (new Fireball(*this)); }