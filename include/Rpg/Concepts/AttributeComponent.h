#pragma once

#include <concepts>
#include <cstdint>

namespace Rpg::Concepts
{

template <typename T>
concept AttributeComponent = requires(T& attr, std::int32_t amount)
{
  { attr.base() }      -> std::convertible_to<std::int32_t>;
  { attr.effective() } -> std::convertible_to<std::int32_t>;
  { attr.increase(amount) };
  { attr.decrease(amount) };
  { attr.reset() };
};

} // namespace Rpg::Concepts
