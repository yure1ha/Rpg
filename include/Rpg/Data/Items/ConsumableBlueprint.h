#pragma once

#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

struct ConsumableBlueprint
{
  std::optional<StatusModifierComponent> modifier;

  std::int32_t maxAmount {};
  std::int32_t currentAmount {};
};

} // namespace Rpg
