#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/Attributes/HealthComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/Attributes/DefenseComponent.h"

#include "Rpg/Components/ActiveModifiersComponent.h"

#include "Rpg/Items/Consumable.h"
#include "Rpg/Items/Weapon.h"
#include "Rpg/Items/Armor.h"

#include "Rpg/Components/Containers/ContainerComponent.h"
#include "Rpg/Components/Containers/EquipmentComponent.h"

namespace Rpg
{

class Character
{
public:
  explicit Character(IdComponent id) : m_id {id}
  {
  }

  IdComponent id() const { return m_id; }

  void equipWeapon(Weapon weapon);
  void unequipWeapon();
  void equipArmor(Armor armor);
  void unequipArmor();

private:
  IdComponent m_id;

  HealthComponent m_health;
  StrengthComponent m_strength;
  DefenseComponent m_defense;

  ActiveModifiersComponent m_modifiers;

  ContainerComponent<Consumable> m_consumables;
  ContainerComponent<Weapon> m_weapons;
  ContainerComponent<Armor> m_armor;

  EquipmentComponent m_equipment;
};

} // namespace Rpg
