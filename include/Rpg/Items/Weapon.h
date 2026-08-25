#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <optional>

namespace Rpg
{

class Weapon
{
public:
  explicit Weapon(IdComponent id) : m_id {id}
  {
  }

  IdComponent id() const { return m_id; }
  StrengthComponent sortKey() const { return m_strength; }

  StrengthComponent strength() const { return m_strength; }
  std::optional<StatusModifierComponent> modifier() const { return m_modifier; }

private:
  IdComponent m_id;

  StrengthComponent m_strength;
  std::optional<StatusModifierComponent> m_modifier;
};

} // namespace Rpg
