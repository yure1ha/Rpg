#pragma once

#include "Rpg/Components/StatusModifierComponent.h"

#include "Rpg/Items/Weapon.h"
#include "Rpg/Items/Armor.h"

#include <cstdint>
#include <optional>
#include <vector>

namespace Rpg
{

struct EnemyBlueprint
{
  std::vector<StatusModifierComponent> modifiers {};

  std::optional<Weapon> equippedWeapon;
  std::optional<Armor> equippedArmor;

  std::int32_t baseHealth {};
  std::int32_t effectiveHealth {};
  std::int32_t currentHealth {};

  std::int32_t baseStrength {};
  std::int32_t effectiveStrength {};

  std::int32_t baseDefense {};
  std::int32_t effectiveDefense {};
};

} // namespace Rpg
