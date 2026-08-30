#pragma once

#include "Rpg/Concepts/AttributeComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

namespace Rpg::StatusModifierSystem
{

template <Concepts::AttributeComponent T>
void applyModifier(T& attr, const StatusModifierComponent& modifier)
{
  if (modifier.total() > 0)
  {
    attr.increase(modifier.total());
  }

  else if (modifier.total() < 0)
  {
    attr.decrease(-modifier.total());
  }
}

} // namespace Rpg::StatusModifierSystem
