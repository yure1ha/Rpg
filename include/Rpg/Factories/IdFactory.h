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

  IdComponent create(std::int32_t typeId)
  {
    if (!m_freeIds.empty())
    {
      std::int32_t instanceId = m_freeIds.back();
      m_freeIds.pop_back();

      return IdComponent {.typeId = typeId, .instanceId = instanceId};
    }

    return IdComponent {.typeId = typeId, .instanceId = m_instanceId++};
  }

  void freeId(std::int32_t instanceId)
  {
    m_freeIds.push_back(instanceId);
  }

private:
  std::int32_t m_instanceId {kMinInstanceId};
  std::vector<std::int32_t> m_freeIds {};
};

} // namespace Rpg
