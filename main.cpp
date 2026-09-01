#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"
#include "Rpg/Components/StackComponent.h"

#include "Rpg/Data/Entities/CharacterBlueprint.h"
#include "Rpg/Data/Entities/EnemyBlueprint.h"
#include "Rpg/Data/StatusModifierType.h"

#include "Rpg/Entities/Character.h"
#include "Rpg/Entities/Enemy.h"

#include "Rpg/Systems/StatusModifierSystem.h"
#include "Rpg/Systems/CombatSystem.h"

#include <iostream>

namespace
{

void printEntity(const Rpg::Character& yureiha)
{
  std::cout << "[" << "Yureiha" << "]"
          << "[ID] "      << yureiha.id().id << " "
          << "[HP] "      << yureiha.health().current() << "/" << yureiha.health().effective() << " "
          << "[Base HP] " << yureiha.health().base() << " "
          << "[STR] "     << yureiha.strength().effective() << "/" << yureiha.strength().base() << " "
          << "[DEF] "     << yureiha.defense().effective() << "/" << yureiha.defense().base() << '\n';
}

void printEntity(const Rpg::Enemy& ahieruy)
{
  std::cout << "[" << "Ahieruy" << "]"
          << "[ID] "      << ahieruy.id().id << " "
          << "[HP] "      << ahieruy.health().current() << "/" << ahieruy.health().effective() << " "
          << "[Base HP] " << ahieruy.health().base() << " "
          << "[STR] "     << ahieruy.strength().effective() << "/" << ahieruy.strength().base() << " "
          << "[DEF] "     << ahieruy.defense().effective() << "/" << ahieruy.defense().base() << '\n';
}

}

int main()
{
  using namespace Rpg;

  CharacterBlueprint protagonist {
    .baseHealth         = 50,
    .effectiveHealth    = 60,
    .currentHealth      = 25,

    .baseStrength       = 10,
    .effectiveStrength  = 15,

    .baseDefense        = 10,
    .effectiveDefense   = 15
  };

  EnemyBlueprint antagonist {
    .baseHealth         = 40,
    .effectiveHealth    = 50,
    .currentHealth      = 20,

    .baseStrength       = 5,
    .effectiveStrength  = 10,

    .baseDefense        = 5,
    .effectiveDefense   = 10
  };

  Character yureiha {IdComponent {1}, protagonist};
  Enemy ahieruy     {IdComponent {2}, antagonist};

  StatusModifierComponent strengthUp  {
    IdComponent {10},
    StatusModifierType::Strength,
    StackComponent {1, 99},
    10
  };
  StatusModifierComponent defenseDown {
    IdComponent {11},
    StatusModifierType::Defense,
    StackComponent {2, 99},
    -5
  };

  printEntity(yureiha);
  printEntity(ahieruy);

  CombatSystem::applyDamage(yureiha, ahieruy);
  printEntity(ahieruy);

  yureiha.strength().reset();
  yureiha.defense().reset();
  ahieruy.strength().reset();
  ahieruy.defense().reset();

  CombatSystem::applyDamage(ahieruy, yureiha);
  printEntity(yureiha);

  yureiha.modifiers().add(strengthUp);
  ahieruy.modifiers().add(defenseDown);

  StatusModifierSystem::updateModifiers(yureiha.modifiers(), yureiha.strength());
  StatusModifierSystem::updateModifiers(ahieruy.modifiers(), ahieruy.defense());

  printEntity(yureiha);
  printEntity(ahieruy);

  CombatSystem::applyDamage(yureiha, ahieruy);
  yureiha.health().heal(100);
  printEntity(yureiha);

  ahieruy.health().takeDamage(100);
  printEntity(ahieruy);

  return 0;
}
