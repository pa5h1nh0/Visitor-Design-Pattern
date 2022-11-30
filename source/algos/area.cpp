#include <numbers>

#include "area.hpp"

#include "shapes/circle.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/square.hpp"

void Area::apply(const Circle& circle) noexcept
{
  result = std::numbers::pi * (circle.radius * circle.radius);
}

void Area::apply(const Square& square) noexcept
{
  result = square.length * square.length;
}

void Area::apply(const Rectangle& rectangle) noexcept
{
  result = rectangle.length * rectangle.width;
}