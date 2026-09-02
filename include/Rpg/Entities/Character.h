#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Data/Entities/CharacterBlueprint.h"

#include "Rpg/Components/Attributes/DefenseComponent.h"
#include "Rpg/Components/Attributes/HealthComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"

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
  using StatusModifiers     = ContainerComponent<StatusModifierComponent>;
  using ConsumableInventory = ContainerComponent<Consumable>;
  using WeaponInventory     = ContainerComponent<Weapon>;
  using ArmorInventory      = ContainerComponent<Armor>;

  Character(IdComponent id, const CharacterBlueprint& bp);

  IdComponent id() const { return m_id; }

  HealthComponent& health()     { return m_health; }
  StrengthComponent& strength() { return m_strength; }
  DefenseComponent& defense()   { return m_defense; }

  const HealthComponent& health() const     { return m_health; }
  const StrengthComponent& strength() const { return m_strength; }
  const DefenseComponent& defense() const   { return m_defense; }

  StatusModifiers& modifiers()             { return m_modifiers; }
  const StatusModifiers& modifiers() const { return m_modifiers; }

  ConsumableInventory& consumables() { return m_consumables; }
  WeaponInventory& weapons()         { return m_weapons; }
  ArmorInventory& armor()            { return m_armor; }

  const ConsumableInventory& consumables() const { return m_consumables; }
  const WeaponInventory& weapons() const         { return m_weapons; }
  const ArmorInventory& armor() const            { return m_armor; }

  void equipWeapon(Weapon weapon);
  void unequipWeapon();
  void equipArmor(Armor armor);
  void unequipArmor();

  void useConsumable(Consumable consumable);

private:
  IdComponent         m_id;

  HealthComponent     m_health;
  StrengthComponent   m_strength;
  DefenseComponent    m_defense;

  StatusModifiers     m_modifiers;

  ConsumableInventory m_consumables;
  WeaponInventory     m_weapons;
  ArmorInventory      m_armor;

  EquipmentComponent  m_equipment;
};

} // namespace Rpg
