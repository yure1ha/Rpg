#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Data/WeaponBlueprint.h"

#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <optional>

namespace Rpg
{

class Weapon
{
public:
  explicit Weapon(IdComponent id, const WeaponBlueprint& bp)
      : m_id       {id},
        m_strength {bp.baseStrength, bp.effectiveStrength},
        m_modifier {bp.modifier}
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
