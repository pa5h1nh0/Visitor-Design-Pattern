#pragma once

#include "utils.hpp"

class Perimeter
{
private:
  double result {};

public:
  Perimeter() = default;
  ~Perimeter() = default;

  Perimeter(const Perimeter&) = delete;  // Copy ctor
  Perimeter(Perimeter&&) = delete;  // Move ctor
  Perimeter& operator=(const Perimeter&) = delete;  // Copy assignment operator
  Perimeter& operator=(Perimeter&&) = delete;  // Move assignment operator

  void apply(const Circle& circle) noexcept;
  void apply(const Square& square) noexcept;
  void apply(const Rectangle& rectangle) noexcept;

  [[nodiscard]] auto get() const { return result; }
};

// this is to validate at compile-time the 'AppliesToShapes' concept applied on
// 'Perimeter' instead of using "inheritance", in order of enforcing an
// "interface contract"
static_assert(vp::AppliesToShapes<Perimeter>);