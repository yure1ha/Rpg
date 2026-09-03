#pragma once

#include "Rpg/Factories/IdFactory.h"

namespace Rpg
{

class ItemFactory
{
public:
  ItemFactory(IdFactory& idFactory) : m_idFactory {idFactory}
  {
  }

  template <typename Item, typename Blueprint>
  Item create(const Blueprint& bp) const
  {
    return Item {m_idFactory.allocate(bp.typeId), bp};
  }

private:
  IdFactory& m_idFactory;
};

} // namespace Rpg
