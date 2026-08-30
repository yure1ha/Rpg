#pragma once

#include "Rpg/Concepts/ContainerItem.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace Rpg
{

template <Concepts::ContainerItem T>
class ContainerComponent
{
public:
  explicit ContainerComponent(std::vector<T> items = {})
      : m_items {std::move(items)}
  {
  }

  const std::vector<T>& items() const { return m_items; }

  bool contains(const T& item) const
  {
    return std::ranges::any_of(m_items, [&item](const T& comp)
    {
      return item.id() == comp.id();
    });
  }

  void add(const T& item)
  {
    m_items.push_back(item);
  }

  void remove(const T& item)
  {
    std::erase_if(m_items, [&item](const T& comp)
    {
      return item.id() == comp.id();
    });
  }

  void sort()
  {
    std::ranges::stable_sort(m_items, std::greater {}, &T::sortKey);
  }

private:
  std::vector<T> m_items {};
};

} // namespace Rpg
