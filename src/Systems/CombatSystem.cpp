#include "Rpg/Systems/CombatSystem.h"

#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/Attributes/DefenseComponent.h"

#include "Rpg/Entities/Character.h"
#include "Rpg/Entities/Enemy.h"

#include <cstdint>

namespace Rpg::CombatSystem
{

std::int32_t calculateDamage(const StrengthComponent& str, const DefenseComponent& def)
{
  return str.effective() - def.effective();
}

void applyDamage(const Character& attacker, Enemy& defender)
{
  const auto damage {calculateDamage(attacker.strength(), defender.defense())};
  defender.health().takeDamage(damage);
}

void applyDamage(const Enemy& attacker, Character& defender)
{
  const auto damage {calculateDamage(attacker.strength(), defender.defense())};
  defender.health().takeDamage(damage);
}

} // namespace Rpg::CombatSystem
