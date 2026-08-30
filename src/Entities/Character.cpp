#include "Rpg/Entities/Character.h"

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Data/Entities/CharacterBlueprint.h"

#include "Rpg/Items/Weapon.h"
#include "Rpg/Items/Armor.h"

#include <optional>

namespace Rpg
{

Character::Character(IdComponent id, const CharacterBlueprint& bp)
      : m_id          {id},
        m_health      {bp.currentHealth, bp.effectiveHealth, bp.baseHealth},
        m_strength    {bp.effectiveStrength, bp.baseStrength},
        m_defense     {bp.effectiveDefense, bp.baseDefense},
        m_modifiers   {bp.modifiers},
        m_consumables {bp.consumables},
        m_weapons     {bp.weapons},
        m_armor       {bp.armor},
        m_equipment   {bp.equippedWeapon, bp.equippedArmor}
{
}

void Character::equipWeapon(Weapon weapon)
{
  if (!m_weapons.contains(weapon)) return;

  unequipWeapon();

  m_weapons.remove(weapon);
  m_equipment.weapon = weapon;

  if (weapon.modifier().has_value())
  {
    m_modifiers.add(*weapon.modifier());
  }
}

void Character::unequipWeapon()
{
  if (!m_equipment.weapon.has_value()) return;

  if (m_equipment.weapon->modifier().has_value())
  {
    m_modifiers.remove(*m_equipment.weapon->modifier());
  }

  m_weapons.add(*m_equipment.weapon);
  m_equipment.weapon.reset();
}

void Character::equipArmor(Armor armor)
{
  if (!m_armor.contains(armor)) return;

  unequipArmor();

  m_armor.remove(armor);
  m_equipment.armor = armor;

  if (armor.modifier().has_value())
  {
    m_modifiers.add(*armor.modifier());
  }
}

void Character::unequipArmor()
{
  if (!m_equipment.armor.has_value()) return;

  if (m_equipment.armor->modifier().has_value())
  {
    m_modifiers.remove(*m_equipment.armor->modifier());
  }

  m_armor.add(*m_equipment.armor);
  m_equipment.armor.reset();
}

void Character::useConsumable(Consumable consumable)
{
  if (!m_consumables.contains(consumable)) return;

  m_consumables.remove(consumable);

  if (consumable.modifier().has_value())
  {
    m_modifiers.add(*consumable.modifier());
  }
}

} // namespace Rpg
