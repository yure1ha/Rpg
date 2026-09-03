#include "Helpers.h"

#include "Rpg/Factories/IdFactory.h"
#include "Rpg/Factories/EntityFactory.h"
#include "Rpg/Factories/ItemFactory.h"

#include "Rpg/Components/StatusModifierComponent.h"
#include "Rpg/Components/StackComponent.h"
#include "Rpg/Data/StatusModifierType.h"

#include "Rpg/Data/Items/ConsumableBlueprint.h"
#include "Rpg/Data/Items/WeaponBlueprint.h"
#include "Rpg/Data/Items/ArmorBlueprint.h"

#include "Rpg/Items/Consumable.h"
#include "Rpg/Items/Weapon.h"
#include "Rpg/Items/Armor.h"

#include "Rpg/Data/Entities/CharacterBlueprint.h"
#include "Rpg/Data/Entities/EnemyBlueprint.h"

#include "Rpg/Entities/Character.h"
#include "Rpg/Entities/Enemy.h"

#include "Rpg/Systems/StatusModifierSystem.h"
#include "Rpg/Systems/CombatSystem.h"

namespace Rpg::Tests
{

void runCombatTests()
{
  IdFactory idFactory;

  StatusModifierComponent healthUp {
    idFactory.allocate(1000),
    StatusModifierType::Health,
    StackComponent {99, 1},
    10
  };

  StatusModifierComponent healthDown {
    idFactory.allocate(1001),
    StatusModifierType::Health,
    StackComponent {99, 1},
    -10
  };

  StatusModifierComponent strengthUp {
    idFactory.allocate(1002),
    StatusModifierType::Strength,
    StackComponent {99, 1},
    10
  };

  StatusModifierComponent strengthDown {
    idFactory.allocate(1003),
    StatusModifierType::Strength,
    StackComponent {99, 1},
    -10
  };

  StatusModifierComponent defenseUp {
    idFactory.allocate(1004),
    StatusModifierType::Defense,
    StackComponent {99, 1},
    10
  };

  StatusModifierComponent defenseDown {
    idFactory.allocate(1005),
    StatusModifierType::Defense,
    StackComponent {99, 1},
    -10
  };

  ConsumableBlueprint consumableBp {
    .modifier     = healthUp,
    .typeId       = 100,
    .maxStack     = 99,
    .currentStack = 10,
  };

  WeaponBlueprint weaponBp {
    .modifier          = strengthUp,
    .typeId            = 101,
    .maxStack          = 1,
    .currentStack      = 1,
    .baseStrength      = 5,
    .effectiveStrength = 5,
  };

  ArmorBlueprint armorBp {
    .modifier          = defenseUp,
    .typeId            = 102,
    .maxStack         = 1,
    .currentStack     = 1,
    .baseDefense      = 5,
    .effectiveDefense = 5
  };

  ItemFactory itemFactory {idFactory};
  auto consumable {itemFactory.create<Consumable>(consumableBp)};
  auto weapon {itemFactory.create<Weapon>(weaponBp)};
  auto armor {itemFactory.create<Armor>(armorBp)};

  CharacterBlueprint protagonistBp {
    .typeId            = 1,

    .baseHealth        = 100,
    .effectiveHealth   = 100,
    .currentHealth     = 100,

    .baseStrength      = 20,
    .effectiveStrength = 20,

    .baseDefense       = 20,
    .effectiveDefense  = 20
  };

  EnemyBlueprint antagonistBp {
    .typeId            = 2,

    .baseHealth        = 100,
    .effectiveHealth   = 100,
    .currentHealth     = 100,

    .baseStrength      = 50,
    .effectiveStrength = 50,

    .baseDefense       = 30,
    .effectiveDefense  = 30
  };

  EntityFactory entityFactory {idFactory};
  auto protagonist {entityFactory.create<Character>(protagonistBp)};
  auto antagonist {entityFactory.create<Enemy>(antagonistBp)};

  printEntity(protagonist);
  printEntity(antagonist);

  protagonist.weapons().add(weapon);
  protagonist.armor().add(armor);
  protagonist.equipWeapon(weapon);
  protagonist.equipArmor(armor);
  StatusModifierSystem::updateModifiers(protagonist.modifiers(), protagonist.strength());
  StatusModifierSystem::updateModifiers(protagonist.modifiers(), protagonist.defense());
  printEntity(protagonist);

  CombatSystem::applyDamage(antagonist, protagonist);
  printEntity(protagonist);

  antagonist.modifiers().add(defenseDown);
  StatusModifierSystem::updateModifiers(antagonist.modifiers(), antagonist.defense());
  CombatSystem::applyDamage(protagonist, antagonist);
  printEntity(antagonist);

  CombatSystem::applyDamage(antagonist, protagonist);
  printEntity(protagonist);

  protagonist.health().heal(100);
  printEntity(protagonist);

  antagonist.health().takeDamage(100);
  printEntity(antagonist);

  protagonist.consumables().add(consumable);
  protagonist.useConsumable(consumable);
  StatusModifierSystem::updateModifiers(protagonist.modifiers(), protagonist.health());
  printEntity(protagonist);

  protagonist.health().reset();
  protagonist.strength().reset();
  protagonist.defense().reset();
  printEntity(protagonist);
}

} // namespace Rpg::Tests
