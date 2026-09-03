#pragma once

#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

struct ConsumableBlueprint
{
  std::optional<StatusModifierComponent> modifier;
  std::int32_t typeId {};
  std::int32_t maxStack {};
  std::int32_t currentStack {};
};

} // namespace Rpg
