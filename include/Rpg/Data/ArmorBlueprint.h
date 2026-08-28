#pragma once

#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

struct ArmorBlueprint
{
  std::int32_t baseDefense {};
  std::int32_t effectiveDefense {};

  std::optional<StatusModifierComponent> modifier;
};

} // namespace Rpg
