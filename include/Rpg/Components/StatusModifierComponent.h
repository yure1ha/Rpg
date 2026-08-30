#pragma once

#include "Rpg/Components/IdComponent.h"

#include "StackComponent.h"

#include <algorithm>
#include <cstdint>

namespace Rpg
{

class StatusModifierComponent
{
public:
  StatusModifierComponent(IdComponent id,
                          StackComponent stack,
                          std::int32_t value)
      : m_id    {id},
        m_stack {stack},
        m_value {value}
  {
    clamp();
  }

  static constexpr std::int32_t kMinModifier {-99};
  static constexpr std::int32_t kMaxModifier {99};

  IdComponent id() const       { return m_id; }
  StackComponent stack() const { return m_stack; }
  std::int32_t sortKey() const { return m_value; }
  std::int32_t value() const   { return m_value; }
  std::int32_t total() const   { return m_value * m_stack.current(); }

  bool isActive() const { return m_stack.current() > 0; }

  void clamp()
  {
    m_value = std::clamp(m_value, kMinModifier, kMaxModifier);
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
  std::int32_t m_value {};
};

} // namespace Rpg
