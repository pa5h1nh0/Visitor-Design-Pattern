#pragma once

#include "utils.hpp"

class Area
{
private:
  double result {};

public:
  Area() = default;
  ~Area() = default;

  Area(const Area&) = delete;  // Copy ctor
  Area(Area&&) = delete;  // Move ctor
  Area& operator=(const Area&) = delete;  // Copy assignment operator
  Area& operator=(Area&&) = delete;  // Move assignment operator

  void apply(const Circle& circle) noexcept;
  void apply(const Square& square) noexcept;
  void apply(const Rectangle& rectangle) noexcept;

  [[nodiscard]] auto get() const { return result; }
};

// this is to validate at compile-time the 'AppliesToShapes' concept applied on
// 'Area' instead of using "inheritance", in order of enforcing an
// "interface contract"
static_assert(vp::AppliesToShapes<Area>);