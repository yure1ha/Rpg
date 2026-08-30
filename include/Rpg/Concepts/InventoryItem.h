#pragma once

#include <concepts>

namespace Rpg::Concepts
{

template <typename T>
concept InventoryItem = requires(const T& item)
{
  { item.id() }      -> std::equality_comparable;
  { item.sortKey() } -> std::totally_ordered;
};

} // namespace Rpg::Concepts
