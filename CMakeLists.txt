cmake_minimum_required(VERSION 4.2)
project(Rpg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Rpg
        # Components
        include/Rpg/Components/IdComponent.h
        include/Rpg/Components/StatusModifierComponent.h
        include/Rpg/Components/Attributes/HealthComponent.h
        include/Rpg/Components/Attributes/DefenseComponent.h
        include/Rpg/Components/Attributes/StrengthComponent.h
        include/Rpg/Components/StackComponent.h
        include/Rpg/Components/Containers/ContainerComponent.h
        include/Rpg/Components/Containers/EquipmentComponent.h

        # Concepts
        include/Rpg/Concepts/AttributeComponent.h
        include/Rpg/Concepts/InventoryItem.h

        # Data
        include/Rpg/Data/Entities/CharacterBlueprint.h
        include/Rpg/Data/Entities/EnemyBlueprint.h
        include/Rpg/Data/Items/ConsumableBlueprint.h
        include/Rpg/Data/Items/WeaponBlueprint.h
        include/Rpg/Data/Items/ArmorBlueprint.h
        include/Rpg/Data/StatusModifierType.h

        # Entities
        include/Rpg/Entities/Character.h
        include/Rpg/Entities/Enemy.h
        src/Entities/Character.cpp

        # Items
        include/Rpg/Items/Consumable.h
        include/Rpg/Items/Weapon.h
        include/Rpg/Items/Armor.h

        # Systems
        include/Rpg/Systems/StatusModifierSystem.h
        include/Rpg/Systems/CombatSystem.h
        src/Systems/CombatSystem.cpp
)

target_include_directories(Rpg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE Rpg)
