#include "Helpers.h"

#include "Rpg/Factories/IdFactory.h"

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
    idFactory.create(1000),
    StatusModifierType::Health,
    StackComponent {99, 1},
    5
  };

  StatusModifierComponent healthDown {
    idFactory.create(1001),
    StatusModifierType::Health,
    StackComponent {99, 1},
    -5
  };

  StatusModifierComponent strengthUp {
    idFactory.create(1002),
    StatusModifierType::Strength,
    StackComponent {99, 1},
    5
  };

  StatusModifierComponent strengthDown {
    idFactory.create(1003),
    StatusModifierType::Strength,
    StackComponent {99, 1},
    -5
  };

  StatusModifierComponent defenseUp {
    idFactory.create(1004),
    StatusModifierType::Defense,
    StackComponent {99, 1},
    5
  };

  StatusModifierComponent defenseDown {
    idFactory.create(1005),
    StatusModifierType::Defense,
    StackComponent {99, 1},
    -5
  };

  ConsumableBlueprint goldenAppleBp {
    .modifier     = healthUp,
    .maxStack     = 99,
    .currentStack = 10,
  };

  WeaponBlueprint longswordBp {
    .modifier          = strengthUp,
    .maxStack          = 1,
    .currentStack      = 1,
    .baseStrength      = 10,
    .effectiveStrength = 10,
  };

  ArmorBlueprint chainmailBp {
    .modifier          = defenseUp,
    .maxStack         = 1,
    .currentStack     = 1,
    .baseDefense      = 10,
    .effectiveDefense = 10
  };

  Consumable goldenApple {idFactory.create(100), goldenAppleBp};
  Weapon longsword {idFactory.create(101), longswordBp};
  Armor chainmail {idFactory.create(102), chainmailBp};

  CharacterBlueprint protagonistBp {
    .baseHealth        = 100,
    .effectiveHealth   = 100,
    .currentHealth     = 100,

    .baseStrength      = 20,
    .effectiveStrength = 20,

    .baseDefense       = 20,
    .effectiveDefense  = 20
  };

  EnemyBlueprint antagonistBp {
    .baseHealth        = 100,
    .effectiveHealth   = 100,
    .currentHealth     = 100,

    .baseStrength      = 20,
    .effectiveStrength = 20,

    .baseDefense       = 20,
    .effectiveDefense  = 20
  };

  Character protagonist {idFactory.create(1), protagonistBp};
  Enemy antagonist {idFactory.create(2), antagonistBp};

  printEntity(protagonist);
  printEntity(antagonist);

  protagonist.weapons().add(longsword);
  protagonist.armor().add(chainmail);
  protagonist.equipWeapon(longsword);
  protagonist.equipArmor(chainmail);
  StatusModifierSystem::updateModifiers(protagonist.modifiers(), protagonist.strength());
  StatusModifierSystem::updateModifiers(protagonist.modifiers(), protagonist.defense());
  printEntity(protagonist);

  CombatSystem::applyDamage(antagonist, protagonist);
  printEntity(protagonist);

  antagonist.modifiers().add(defenseDown, 2);
  StatusModifierSystem::updateModifiers(antagonist.modifiers(), antagonist.defense());
  CombatSystem::applyDamage(protagonist, antagonist);
  printEntity(antagonist);
}

} // namespace Rpg::Tests
