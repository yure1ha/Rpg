#pragma once

#include <algorithm>
#include <cstdint>

namespace Rpg
{

class DefenseComponent
{
public:
  DefenseComponent(std::int32_t base, std::int32_t effective)
      : m_base {base}, m_effective {effective}
  {
    clamp();
  };

  static constexpr std::int32_t kMinDefense {1};
  static constexpr std::int32_t kMaxDefense {99};

  std::int32_t base() const { return m_base; }
  std::int32_t effective() const { return m_effective; }

  void clamp()
  {
    m_base = std::clamp(m_base, kMinDefense, kMaxDefense);
    m_effective = std::clamp(m_effective, kMinDefense, kMaxDefense);
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
  std::int32_t m_base {};
  std::int32_t m_effective {};
};

} // namespace Rpg
