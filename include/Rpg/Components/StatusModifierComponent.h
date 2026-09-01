#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/StackComponent.h"
#include "Rpg/Data/StatusModifierType.h"

#include <algorithm>
#include <cstdint>
#include <optional>

namespace Rpg
{

class StatusModifierComponent
{
public:
  StatusModifierComponent(IdComponent id,
                          StatusModifierType type,
                          StackComponent stack,
                          std::int32_t value)
      : m_id    {id},
        m_type  {type},
        m_stack {stack},
        m_value {value}
  {
    clamp();
  }

  static constexpr std::int32_t kMinModifier {-99};
  static constexpr std::int32_t kMaxModifier {99};

  IdComponent id() const           { return m_id; }
  StatusModifierType type() const  { return m_type; }
  StackComponent stack() const     { return m_stack; }
  std::int32_t sortKey() const     { return m_value; }
  std::int32_t value() const       { return m_value; }
  std::int32_t total() const       { return m_value * m_stack.current(); }

  bool isActive() const { return m_stack.current() > 0; }

private:
  void clamp()
  {
    m_value = std::clamp(m_value, kMinModifier, kMaxModifier);
  }

  IdComponent        m_id;
  StatusModifierType m_type {};
  StackComponent     m_stack;
  std::int32_t       m_value {};
};

using OptStatusModifier = std::optional<StatusModifierComponent>;

} // namespace Rpg
