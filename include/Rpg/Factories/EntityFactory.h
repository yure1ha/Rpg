#pragma once

#include "Rpg/Factories/IdFactory.h"

namespace Rpg
{

class EntityFactory
{
public:
  EntityFactory(IdFactory& idFactory) : m_idFactory {idFactory}
  {
  }

  template<typename Entity, typename EntityBlueprint>
  Entity create(const EntityBlueprint& bp) const
  {
    return Entity {m_idFactory.allocate(bp.typeId), bp};
  }

private:
  IdFactory& m_idFactory;
};

} // namespace Rpg
