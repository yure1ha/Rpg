#pragma once

#include "Rpg/Data/Items/ArmorBlueprint.h"
#include "Rpg/Components/IdComponent.h"

#include "Rpg/Components/Attributes/DefenseComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

class Armor
{
public:
  using StatusModifier = std::optional<StatusModifierComponent>;

  explicit Armor(IdComponent id, const ArmorBlueprint& bp)
      : m_id       {id},
        m_defense  {bp.baseDefense, bp.effectiveDefense},
        m_modifier {bp.modifier}
  {
  }

  IdComponent id() const           { return m_id; }
  std::int32_t sortKey() const     { return m_defense.effective(); }

  DefenseComponent defense() const { return m_defense; }
  StatusModifier modifier() const  { return m_modifier; }

private:
  IdComponent      m_id;
  DefenseComponent m_defense;
  StatusModifier   m_modifier;
};

} // namespace Rpg
