#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Data/Entities/EnemyBlueprint.h"

#include "Rpg/Components/Attributes/HealthComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/Attributes/DefenseComponent.h"

#include "Rpg/Components/StatusModifierComponent.h"

#include "Rpg/Components/Containers/ContainerComponent.h"
#include "Rpg/Components/Containers/EquipmentComponent.h"

namespace Rpg
{

class Enemy
{
public:
  using ModifiersList = ContainerComponent<StatusModifierComponent>;

  Enemy(IdComponent id, const EnemyBlueprint& bp)
      : m_id        {id},
        m_health    {bp.baseHealth, bp.effectiveHealth, bp.currentHealth},
        m_strength  {bp.baseStrength, bp.effectiveStrength},
        m_defense   {bp.baseDefense, bp.effectiveDefense},
        m_modifiers {bp.modifiers},
        m_equipment {bp.equippedWeapon, bp.equippedArmor}
  {
  }

  IdComponent id() const { return m_id; }

  HealthComponent& health()     { return m_health; }
  StrengthComponent& strength() { return m_strength; }
  DefenseComponent& defense()   { return m_defense; }

  const HealthComponent& health() const       { return m_health; }
  const StrengthComponent& strength() const   { return m_strength; }
  const DefenseComponent& defense() const     { return m_defense; }

  ModifiersList& modifiers()             { return m_modifiers; }
  const ModifiersList& modifiers() const { return m_modifiers; }

private:
  IdComponent        m_id;

  HealthComponent    m_health;
  StrengthComponent  m_strength;
  DefenseComponent   m_defense;

  ModifiersList      m_modifiers;

  EquipmentComponent m_equipment;
};

} // namespace Rpg
