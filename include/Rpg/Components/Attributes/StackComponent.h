#pragma once

#include <algorithm>
#include <cstdint>

namespace Rpg
{

class StackComponent
{
public:
  StackComponent(std::int32_t max, std::int32_t current)
      : m_max {max}, m_current {current}
  {
    clamp();
  }

  static constexpr std::int32_t kMinAmount {0};
  static constexpr std::int32_t kMaxAmount {999};

  std::int32_t current() const { return m_current; }
  std::int32_t max() const { return m_max; }

  void clamp()
  {
    m_max = std::clamp(m_max, kMinAmount, kMaxAmount);
    m_current = std::clamp(m_current, kMinAmount, kMaxAmount);
  }

  void increase(std::int32_t amount)
  {
    if (amount <= 0) return;

    m_current += amount;
    clamp();
  }

  void decrease(std::int32_t amount)
  {
    if (amount <= 0) return;

    m_current -= amount;
    clamp();
  }

private:
  std::int32_t m_max {};
  std::int32_t m_current {};
};

} // namespace Rpg
