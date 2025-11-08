#include "Monster.hpp"
#include <iomanip>
#include <cmath>

using namespace std;

Monster::Monster(const string name, unsigned int level, const double hp, Type t1, Type t2):
  m_name(name),
  m_level(level),
  m_hp(hp),
  m_type1(t1),
  m_type2(t2) {}

Monster::~Monster() {}

void Monster::print_monster(ostream & os) const {
  os << m_name << "(lvl. " << m_level << "): " << fixed << setprecision(0) << m_hp << "hp" << endl;
}

void Monster::take_damage(const double damage) {
  double delta = m_hp - damage;
  if (delta <= 0) {
    m_hp = 0;
  } else {
    m_hp = delta;
  }
}