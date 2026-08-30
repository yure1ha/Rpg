#pragma once

#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

struct WeaponBlueprint
{
  std::optional<StatusModifierComponent> modifier;

  std::int32_t baseStrength {};
  std::int32_t effectiveStrength {};
};

} // namespace Rpg
