#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Data/ArmorBlueprint.h"

#include "Rpg/Components/Attributes/DefenseComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <optional>

namespace Rpg
{

class Armor
{
public:
  explicit Armor(IdComponent id, const ArmorBlueprint& bp)
      : m_id       {id},
        m_defense  {bp.baseDefense, bp.effectiveDefense},
        m_modifier {bp.modifier}
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
