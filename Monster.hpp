#include <string>

// represents the types that a Monster may have
enum class Type {
  BUG, DARK, DRAGON, ELECTRIC, FAIRY, FIGHTING, FIRE, FLYING, GHOST,
  GRASS, GROUND, ICE, NORMAL, POISON, PSYCHIC, ROCK, STEEL, WATER,
  TYPE_COUNT
};

// represents the six stats that every Monster must have
// Health Points (hp)
// Attack (atk)
// Special Attack (spatk)
// Defense (def)
// Special Defense (spdef)
// Speed (speed)
struct Stats {
  unsigned int hp;
  unsigned int atk;
  unsigned int spatk;
  unsigned int def;
  unsigned int spdef;
  unsigned int speed;
};

// represents a monster that can battle
class Monster {
public:
  Monster(const std::string name, unsigned int m_level, const double hp, Type t1, Type t2);
  ~Monster();
  // print this monster's information
  void print_monster(std::ostream& os) const;
  // deal the given amount of damage to this monster
  // INVARIANT: monster's hp will never be below 0.
  void take_damage(const double damage);

private:
  std::string m_name;
  unsigned int m_level;
  double m_hp;
  Type m_type1;
  Type m_type2;
};