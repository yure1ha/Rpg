#pragma once

#include <algorithm>
#include <cassert>
#include <cstdint>

namespace Rpg
{

class HealthComponent
{
public:
  HealthComponent(std::int32_t current = kMinHealth, std::int32_t base = kMinHealth)
      : m_current {current}, m_base {base}
  {
    clamp();
    assert(isValid());
  }

  static constexpr std::int32_t kMinHealth {0};
  static constexpr std::int32_t kMaxHealth {9999};

  std::int32_t current() const {  return m_current; }
  std::int32_t base() const {  return m_base; }

  bool isAlive() const { return m_current > kMinHealth; }

  void clamp()
  {
    m_base = std::clamp(m_base, kMinHealth, kMaxHealth);
    m_current = std::clamp(m_current, kMinHealth, m_base);
  }

  void heal(std::int32_t amount)
  {
    if (amount <= 0) return;

    m_current += amount;
    clamp();

    assert(isValid());
  }

  void takeDamage(std::int32_t amount)
  {
    if (amount <= 0) return;

    m_current -= amount;
    clamp();

    assert(isValid());
  }

  void reset()
  {
    m_current = m_base;
    assert(isValid());
  }

private:
  std::int32_t m_current {};
  std::int32_t m_base {};

  bool isValid() const
  {
    return m_current <= m_base
        && m_current >= kMinHealth
        && m_current <= kMaxHealth
        && m_base    >= kMinHealth
        && m_base    <= kMaxHealth;
  }
};

} // namespace Rpg
