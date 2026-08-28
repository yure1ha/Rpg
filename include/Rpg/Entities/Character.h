#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Data/CharacterBlueprint.h"

#include "Rpg/Components/Attributes/HealthComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/Attributes/DefenseComponent.h"

#include "Rpg/Components/StatusModifierComponent.h"

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
  using ModifierContainer = ContainerComponent<StatusModifierComponent>;
  using ConsumableContainer = ContainerComponent<Consumable>;
  using WeaponContainer = ContainerComponent<Weapon>;
  using ArmorContainer = ContainerComponent<Armor>;

  Character(IdComponent id, const CharacterBlueprint& bp);

  IdComponent id() const { return m_id; }

  void equipWeapon(Weapon weapon);
  void unequipWeapon();
  void equipArmor(Armor armor);
  void unequipArmor();

  void useConsumable(Consumable consumable);

  HealthComponent& health() { return m_health; }
  StrengthComponent& strength() { return m_strength; }
  DefenseComponent& defense() { return m_defense; }

private:
  IdComponent m_id;

  HealthComponent m_health;
  StrengthComponent m_strength;
  DefenseComponent m_defense;

  ModifierContainer m_modifiers;

  ConsumableContainer m_consumables;
  WeaponContainer m_weapons;
  ArmorContainer m_armor;

  EquipmentComponent m_equipment;
};

} // namespace Rpg
