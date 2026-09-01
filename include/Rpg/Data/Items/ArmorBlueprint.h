#pragma once

#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

struct ArmorBlueprint
{
  std::optional<StatusModifierComponent> modifier;
  std::int32_t maxStack {};
  std::int32_t currentStack {};
  std::int32_t baseDefense {};
  std::int32_t effectiveDefense {};
};

} // namespace Rpg
