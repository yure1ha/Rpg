#pragma once

#include "Rpg/Data/Items/WeaponBlueprint.h"
#include "Rpg/Components/IdComponent.h"

#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

class Weapon
{
public:
  using StatusModifier = std::optional<StatusModifierComponent>;

  explicit Weapon(IdComponent id, const WeaponBlueprint& bp)
      : m_id       {id},
        m_strength {bp.baseStrength, bp.effectiveStrength},
        m_modifier {bp.modifier}
  {
  }

  IdComponent id() const             { return m_id; }
  std::int32_t sortKey() const       { return m_strength.effective(); }
  StrengthComponent strength() const { return m_strength; }
  StatusModifier modifier() const    { return m_modifier; }

private:
  IdComponent       m_id;
  StrengthComponent m_strength;
  StatusModifier    m_modifier;
};

} // namespace Rpg
