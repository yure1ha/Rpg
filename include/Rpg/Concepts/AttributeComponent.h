#pragma once

#include <concepts>
#include <cstdint>

namespace Rpg::Concepts
{

template <typename T>
concept AttributeComponent = requires(T& attribute, std::int32_t amount)
{
  { attribute.base() }      -> std::convertible_to<std::int32_t>;
  { attribute.effective() } -> std::convertible_to<std::int32_t>;
  { attribute.increase(amount) };
  { attribute.decrease(amount) };
  { attribute.reset() };
};

} // namespace Rpg::Concepts
