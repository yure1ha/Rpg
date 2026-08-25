#pragma once

#include <algorithm>
#include <functional>
#include <vector>

namespace Rpg
{

template <typename T>
class ContainerComponent
{
public:
  const std::vector<T>& items() const { return m_items; }

  bool contains(const T& item)
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
