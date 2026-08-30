#pragma once

#include <algorithm>
#include <cstdint>

namespace Rpg
{

class StrengthComponent
{
public:
  StrengthComponent(std::int32_t effective, std::int32_t base)
      : m_effective {effective}, m_base {base}
  {
    clamp();
  }

  static constexpr std::int32_t kMinStrength {1};
  static constexpr std::int32_t kMaxStrength {99};

  std::int32_t effective() const { return m_effective; }
  std::int32_t base() const      { return m_base; }

  void clamp()
  {
    m_effective = std::clamp(m_effective, kMinStrength, kMaxStrength);
    m_base      = std::clamp(m_base, kMinStrength, kMaxStrength);
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

  void reset()
  {
    m_effective = m_base;
  }

private:
  std::int32_t m_effective {};
  std::int32_t m_base {};
};

} // namespace Rpg
