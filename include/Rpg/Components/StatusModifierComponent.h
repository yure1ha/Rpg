#pragma once

#include <cassert>
#include <cstdint>

#include "Attributes/StackComponent.h"
#include "Rpg/Components/IdComponent.h"

namespace Rpg
{

class StatusModifierComponent
{
public:
  StatusModifierComponent(IdComponent id,
                          std::int32_t flatModifier = kMinFlatModifier,
                          float multiplier = kMinMultiplier)
      : m_id {id},
        m_flatModifier {flatModifier},
        m_multiplier {multiplier}
  {
    assert(isValid());
  }

  static constexpr std::int32_t kMinFlatModifier {1};
  static constexpr std::int32_t kMaxFlatModifier {99};
  static constexpr float kMinMultiplier {1.0f};
  static constexpr float kMaxMultiplier {3.0f};

  IdComponent id() const { return m_id; }
  std::int32_t flatModifier() const { return m_flatModifier; }
  float multiplier() const { return m_multiplier; }

  bool operator==(const StatusModifierComponent& comp) const
  {
    return m_id == comp.m_id;
  }

private:
  IdComponent m_id;
  StackComponent m_stack;

  std::int32_t m_flatModifier {};
  float m_multiplier {};

  bool isValid() const
  {
    return m_flatModifier >= kMinFlatModifier
        && m_flatModifier <= kMaxFlatModifier
        && m_multiplier   >= kMinMultiplier
        && m_multiplier   <= kMaxMultiplier;
  }
};

} // namespace Rpg
