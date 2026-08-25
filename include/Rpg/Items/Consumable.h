#pragma once

#include "Rpg/Components/Attributes/StackComponent.h"
#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <optional>

namespace Rpg
{

class Consumable
{
public:
  explicit Consumable(IdComponent id) : m_id {id}
  {
  }

  IdComponent id() const { return m_id; }
  StackComponent sortKey() const { return m_stack; }

  StackComponent stack() const { return m_stack; }
  std::optional<StatusModifierComponent> modifier() const { return m_modifier; }

private:
  IdComponent m_id;

  StackComponent m_stack;
  std::optional<StatusModifierComponent> m_modifier;
};

} // namespace Rpg
