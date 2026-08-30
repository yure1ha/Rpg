#pragma once

#include <cstdint>

namespace Rpg
{

struct IdComponent
{
  std::int32_t instanceId {};

  bool operator==(const IdComponent& comp) const
  {
    return instanceId == comp.instanceId;
  }
};

} // namespace Rpg
