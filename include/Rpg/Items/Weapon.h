#pragma once

#include "Rpg/Data/Items/WeaponBlueprint.h"
#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/StackComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

#include <cstdint>
#include <optional>

namespace Rpg
{

class Weapon
{
public:
  explicit Weapon(IdComponent id, const WeaponBlueprint& bp)
      : m_id       {id},
        m_stack    {bp.maxStack, bp.currentStack},
        m_strength {bp.baseStrength, bp.effectiveStrength},
        m_modifier {bp.modifier}
  {
  }

  IdComponent id() const       { return m_id; }
  std::int32_t sortKey() const { return m_strength.effective(); }
  StackComponent stack() const { return m_stack; }
  StrengthComponent strength() const { return m_strength; }
  OptStatusModifier modifier() const { return m_modifier; }

private:
  IdComponent       m_id;
  StackComponent    m_stack;
  StrengthComponent m_strength;
  OptStatusModifier m_modifier;
};

} // namespace Rpg
