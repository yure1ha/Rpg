#pragma once

#include "Rpg/Data/Items/ConsumableBlueprint.h"
#include "Rpg/Components/IdComponent.h"

#include "Rpg/Components/StackComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

class Consumable
{
public:
  explicit Consumable(IdComponent id, const ConsumableBlueprint& bp)
      : m_id       {id},
        m_stack    {bp.maxStack, bp.currentStack},
        m_modifier {bp.modifier}
  {
  }

  IdComponent id() const       { return m_id; }
  std::int32_t sortKey() const { return m_stack.current(); }
  StackComponent stack() const { return m_stack; }

  OptStatusModifier modifier() const { return m_modifier; }

private:
  IdComponent       m_id;
  StackComponent    m_stack;
  OptStatusModifier m_modifier;
};

} // namespace Rpg
