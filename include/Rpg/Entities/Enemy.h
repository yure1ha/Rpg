#pragma once

#include "Rpg/Components/IdComponent.h"

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
  explicit Enemy(IdComponent id) : m_id {id}
  {
  }

  IdComponent id() const { return m_id; }

private:
  IdComponent m_id;

  HealthComponent m_health;
  StrengthComponent m_strength;
  DefenseComponent m_defense;

  ContainerComponent<StatusModifierComponent> m_modifiers;
  EquipmentComponent m_equipment;
};

} // namespace Rpg
