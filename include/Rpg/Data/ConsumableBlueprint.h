#pragma once

#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

struct ConsumableBlueprint
{
  std::int32_t maxAmount {};
  std::int32_t currentAmount {};

  std::optional<StatusModifierComponent> modifier;
};

} // namespace Rpg
