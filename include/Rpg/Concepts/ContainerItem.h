#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/StackComponent.h"

#include <concepts>

namespace Rpg::Concepts
{

template <typename T>
concept ContainerItem = requires(const T& item)
{
  { item.id() }      -> std::same_as<IdComponent>;
  { item.stack() }   -> std::same_as<StackComponent>;
  { item.sortKey() } -> std::totally_ordered;
};

} // namespace Rpg::Concepts
