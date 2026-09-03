#pragma once

#include "Rpg/Components/IdComponent.h"

#include <cstdint>
#include <vector>

namespace Rpg
{

class IdFactory
{
public:
  static constexpr std::int32_t kMinInstanceId {1};

  IdComponent allocate(std::int32_t typeId)
  {
    if (!m_freeIds.empty())
    {
      const std::int32_t instanceId {m_freeIds.back()};
      m_freeIds.pop_back();

      return IdComponent {.typeId = typeId, .instanceId = instanceId};
    }

    return IdComponent {.typeId = typeId, .instanceId = m_instanceId++};
  }

  void free(std::int32_t instanceId)
  {
    m_freeIds.push_back(instanceId);
  }

private:
  std::vector<std::int32_t> m_freeIds {};
  std::int32_t m_instanceId {kMinInstanceId};
};

} // namespace Rpg
