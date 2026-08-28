#include "Rpg/Data/CharacterBlueprint.h"
#include "Rpg/Data/EnemyBlueprint.h"

#include "Rpg/Entities/Character.h"
#include "Rpg/Entities/Enemy.h"

#include "Rpg/Components/IdComponent.h"

#include <iostream>
#include <string_view>

template <typename T>
void printEntity(std::string_view name, T entity)
{
  std::cout << "[" << name << "]"
          << "[ID] "      << entity.id().id << " "
          << "[HP] "      << entity.health().current() << "/" << entity.health().effective() << " "
          << "[Base HP] " << entity.health().base() << " "
          << "[STR] "     << entity.strength().effective() << "/" << entity.strength().base() << " "
          << "[DEF] "     << entity.defense().effective() << "/" << entity.defense().base() << '\n';
}

int main()
{
  Rpg::CharacterBlueprint protagonist;
  protagonist.baseHealth        = 50;
  protagonist.effectiveHealth   = 60;
  protagonist.currentHealth     = 25;

  protagonist.baseStrength      = 10;
  protagonist.effectiveStrength = 15;

  protagonist.baseDefense       = 10;
  protagonist.effectiveDefense  = 15;

  Rpg::EnemyBlueprint antagonist;
  antagonist.baseHealth         = 40;
  antagonist.effectiveHealth    = 50;
  antagonist.currentHealth      = 20;

  antagonist.baseStrength       = 5;
  antagonist.effectiveStrength  = 10;

  antagonist.baseDefense        = 5;
  antagonist.effectiveDefense   = 10;

  Rpg::Character yureiha {Rpg::IdComponent {1}, protagonist};
  Rpg::Enemy ahieruy {Rpg::IdComponent {2}, antagonist};

  printEntity("Yureiha", yureiha);
  printEntity("Ahieruy", ahieruy);

  ahieruy.health().takeDamage(ahieruy.defense().effective() - yureiha.strength().effective());
  printEntity("Ahieruy", ahieruy);

  yureiha.strength().reset();
  yureiha.defense().reset();
  ahieruy.strength().reset();
  ahieruy.defense().reset();

  yureiha.health().takeDamage(yureiha.defense().effective() - ahieruy.strength().effective());
  printEntity("Yureiha", yureiha);

  yureiha.health().heal(100);
  printEntity("Yureiha", yureiha);

  ahieruy.health().takeDamage(100);
  printEntity("Ahieruy", ahieruy);

  return 0;
}
