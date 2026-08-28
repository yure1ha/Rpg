#pragma once

#include "Rpg/Components/IdComponent.h"

#include "Attributes/StackComponent.h"

#include <algorithm>
#include <cstdint>

namespace Rpg
{

class StatusModifierComponent
{
public:
  StatusModifierComponent(IdComponent id,
                          StackComponent stack,
                          std::int32_t flatModifier = kMinFlatModifier,
                          float multiplier = kMinMultiplier)
      : m_id           {id},
        m_stack        {stack},
        m_flatModifier {flatModifier},
        m_multiplier   {multiplier}
  {
    clamp();
  }

  static constexpr std::int32_t kMinFlatModifier {1};
  static constexpr std::int32_t kMaxFlatModifier {99};
  static constexpr float        kMinMultiplier {0.05f};
  static constexpr float        kMaxMultiplier {3.0f};

  IdComponent id() const { return m_id; }
  std::int32_t flatModifier() const { return m_flatModifier; }
  float multiplier() const { return m_multiplier; }

  bool isActive() const { return m_stack.current() > 0; }

  void clamp()
  {
    m_flatModifier = std::clamp(m_flatModifier, kMinFlatModifier, kMaxFlatModifier);
    m_multiplier = std::clamp(m_multiplier, kMinMultiplier, kMaxMultiplier);
  }

  void increaseStack(std::int32_t count)
  {
    if (count <= 0) return;

    m_stack.increase(count);
    clamp();
  }

  void decreaseStack(std::int32_t count)
  {
    if (count <= 0) return;

    m_stack.decrease(count);
    clamp();
  }

private:
  IdComponent m_id;

  StackComponent m_stack;

  std::int32_t m_flatModifier {};
  float m_multiplier {};
};

} // namespace Rpg
