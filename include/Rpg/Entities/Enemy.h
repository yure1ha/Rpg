#pragma once

#include "Rpg/Data/Entities/EnemyBlueprint.h"
#include "Rpg/Components/IdComponent.h"

#include "Rpg/Components/Attributes/DefenseComponent.h"
#include "Rpg/Components/Attributes/HealthComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"

#include "Rpg/Components/StatusModifierComponent.h"

#include "Rpg/Components/Containers/ContainerComponent.h"
#include "Rpg/Components/Containers/EquipmentComponent.h"

namespace Rpg
{

class Enemy
{
public:
  Enemy(IdComponent id, const EnemyBlueprint& bp)
      : m_id        {id},
        m_health    {bp.currentHealth, bp.effectiveHealth, bp.baseHealth},
        m_strength  {bp.effectiveStrength, bp.baseStrength},
        m_defense   {bp.effectiveDefense, bp.baseDefense},
        m_modifiers {bp.modifiers},
        m_equipment {bp.equippedWeapon, bp.equippedArmor}
  {
  }

  IdComponent id() const { return m_id; }

  HealthComponent& health() { return m_health; }
  StrengthComponent& strength() { return m_strength; }
  DefenseComponent& defense() { return m_defense; }

private:
  IdComponent m_id;

  HealthComponent m_health;
  StrengthComponent m_strength;
  DefenseComponent m_defense;

  ContainerComponent<StatusModifierComponent> m_modifiers;
  EquipmentComponent m_equipment;
};

} // namespace Rpg
