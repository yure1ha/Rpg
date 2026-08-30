#pragma once

#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/Attributes/DefenseComponent.h"

#include "Rpg/Entities/Character.h"
#include "Rpg/Entities/Enemy.h"

namespace Rpg::CombatSystem
{

std::int32_t calculateDamage(const StrengthComponent& str, const DefenseComponent& def);
void applyDamage(const Character& attacker, Enemy& defender);
void applyDamage(const Enemy& attacker, Character& defender);

} // namespace Rpg::CombatSystem
