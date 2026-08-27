#pragma once

#include <algorithm>
#include <cstdint>

namespace Rpg
{

class HealthComponent
{
public:
  HealthComponent(std::int32_t current = kMinHealth,
                  std::int32_t effective = kMinHealth,
                  std::int32_t base = kMinHealth)
      : m_current {current},
        m_effective {effective},
        m_base {base}
  {
    clamp();
  }

  static constexpr std::int32_t kMinHealth {0};
  static constexpr std::int32_t kMaxHealth {9999};

  std::int32_t current() const {  return m_current; }
  std::int32_t base() const {  return m_base; }

  bool isAlive() const { return m_current > kMinHealth; }

  void clamp()
  {
    m_current = std::clamp(m_current, kMinHealth, m_base);
    m_effective = std::clamp(m_effective, kMinHealth, kMaxHealth);
    m_base = std::clamp(m_base, kMinHealth, kMaxHealth);
  }

  void increase(std::int32_t amount)
  {
    if (amount <= 0) return;

    m_effective += amount;
    clamp();
  }

  void decrease(std::int32_t amount)
  {
    if (amount <= 0) return;

    m_effective -= amount;
    clamp();
  }

  void heal(std::int32_t amount)
  {
    if (amount <= 0) return;

    m_current += amount;
    clamp();
  }

  void takeDamage(std::int32_t amount)
  {
    if (amount <= 0) return;

    m_current -= amount;
    clamp();
  }

  void fullHeal()
  {
    m_current = m_effective;
  }

  void reset()
  {
    m_effective = m_base;
  }

private:
  std::int32_t m_current {};
  std::int32_t m_effective {};
  std::int32_t m_base {};
};

} // namespace Rpg
