#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>

namespace Rpg
{

class StackComponent
{
public:
  StackComponent(std::int32_t currentAmount = kMinAmount,
                 std::int32_t maxAmount = kMaxAmount)
      : m_currentAmount {currentAmount},
        m_maxAmount {maxAmount}
  {
    assert(isValid());
  }

  static constexpr std::int32_t kMinAmount {0};
  static constexpr std::int32_t kMaxAmount {999};

  std::int32_t currentQuantity() const { return m_currentAmount; }
  std::int32_t maxQuantity() const { return m_maxAmount; }

  void clamp()
  {
    m_currentAmount = std::clamp(m_currentAmount, kMinAmount, kMaxAmount);
  }

  void add(std::int32_t amount)
  {
    assert(amount > 0);
    m_currentAmount += amount;
    clamp();
    assert(isValid());
  }

  void remove(std::int32_t amount)
  {
    assert(amount > 0);
    m_currentAmount -= amount;
    clamp();
    assert(isValid());
  }

private:
  std::int32_t m_currentAmount {};
  std::int32_t m_maxAmount {};

  bool isValid() const
  {
    return m_currentAmount >= kMinAmount
        && m_currentAmount <= kMaxAmount
        && m_maxAmount     >= kMinAmount
        && m_maxAmount     <= kMaxAmount;
  }
};

} // namespace Rpg
