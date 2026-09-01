#pragma once

#include <compare>
#include <cstdint>

namespace Rpg
{

struct IdComponent
{
  std::int32_t typeId {};
  std::int32_t instanceId {};

  auto operator<=>(const IdComponent&) const = default;
};

} // namespace Rpg
