#pragma once

#include "Rpg/Concepts/AttributeComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"
#include "Rpg/Components/Containers/ContainerComponent.h"

namespace Rpg::StatusModifierSystem
{

using StatusModifiers = ContainerComponent<StatusModifierComponent>;

template <Concepts::AttributeComponent T>
void applyModifier(const StatusModifierComponent& modifier, T& attr)
{
  if (!modifier.isActive() || modifier.type() != T::kModifierType) return;

  if (const auto total {modifier.total()}; total > 0)
  {
    attr.increase(total);
  }

  else if (total < 0)
  {
    attr.decrease(-total);
  }
}

template <Concepts::AttributeComponent T>
void updateModifiers(const StatusModifiers& modifiers, T& attr)
{
  for (const auto& modifier: modifiers)
  {
    applyModifier(modifier, attr);
  }
}

} // namespace Rpg::StatusModifierSystem
