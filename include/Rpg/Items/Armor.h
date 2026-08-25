#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/Attributes/DefenseComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <optional>

namespace Rpg
{

class Armor
{
public:
  explicit Armor(IdComponent id) : m_id {id}
  {
  }

  IdComponent id() const { return m_id; }
  DefenseComponent sortKey() const { return m_defense; }

  DefenseComponent defense() const { return m_defense; }
  std::optional<StatusModifierComponent> modifier() const { return m_modifier; }

private:
  IdComponent m_id;

  DefenseComponent m_defense;
  std::optional<StatusModifierComponent> m_modifier;
};

} // namespace Rpg
