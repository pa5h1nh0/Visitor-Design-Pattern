#include <numbers>

#include "perimeter.hpp"

#include "shapes/circle.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/square.hpp"

void Perimeter::apply(const Circle& circle) noexcept
{
  result = 2 * std::numbers::pi * circle.radius;
}

void Perimeter::apply(const Square& square) noexcept
{
  result = 4 * square.length;
}

void Perimeter::apply(const Rectangle& rectangle) noexcept
{
  result = 2 * (rectangle.length + rectangle.width);
}