cmake_minimum_required(VERSION 4.2)
project(Rpg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Rpg
        include/Rpg/Components/IdComponent.h
        include/Rpg/Components/Attributes/HealthComponent.h
        include/Rpg/Components/Attributes/DefenseComponent.h
        include/Rpg/Components/Attributes/StrengthComponent.h
        include/Rpg/Components/Attributes/StackComponent.h
        include/Rpg/Components/StatusModifierComponent.h
        include/Rpg/Components/Containers/ContainerComponent.h
        include/Rpg/Components/Containers/EquipmentComponent.h
        src/Entities/Character.cpp
        include/Rpg/Items/Consumable.h
        include/Rpg/Items/Weapon.h
        include/Rpg/Items/Armor.h
        include/Rpg/Entities/Character.h
        include/Rpg/Entities/Enemy.h
        include/Rpg/Data/EnemyBlueprint.h
        include/Rpg/Data/CharacterBlueprint.h
        include/Rpg/Data/ConsumableBlueprint.h
        include/Rpg/Data/WeaponBlueprint.h
        include/Rpg/Data/ArmorBlueprint.h
)

target_include_directories(Rpg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE Rpg)
