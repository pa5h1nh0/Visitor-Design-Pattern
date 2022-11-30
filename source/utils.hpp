#pragma once

#include <utility>
#include <variant>

class Area;
class Perimeter;
class Circle;
class Square;
class Rectangle;

namespace vp
{

using algo_variant = std::variant<Area, Perimeter>;
using shape_variant = std::variant<Circle, Square, Rectangle>;

// clang-format off
template<typename T>
concept AppliesAlgo = requires(T v, algo_variant& a)
{
  { v.apply(a) } -> std::same_as<void>;
};

template<typename T>
concept AppliesToShapes =
    requires(T v, const Circle& c, const Square& s, const Rectangle& r)
{
  { v.apply(c) } noexcept->std::same_as<void>;
  { v.apply(s) } noexcept->std::same_as<void>;
  { v.apply(r) } noexcept->std::same_as<void>;
};
// clang-format on

}  // namespace vp