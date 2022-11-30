#pragma once

#include <string>
#include <string_view>

#include "utils.hpp"

class Rectangle
{
public:
  const double length, width;
  const std::string name;

  Rectangle(const double _length, const double _width, std::string_view _name)
      : length {_length}
      , width {_width}
      , name {_name}
  {
  }

  Rectangle() = delete;
  ~Rectangle() = default;

  Rectangle(const Rectangle&) = delete;  // Copy ctor
  Rectangle(Rectangle&&) = default;  // Move ctor
  Rectangle& operator=(const Rectangle&) = delete;  // Copy assignment operator
  Rectangle& operator=(Rectangle&&) = delete;  // Move assignment operator

  void apply(vp::algo_variant& algo);
};

// this is to validate at compile-time the 'AppliesAlgo' concept applied on
// 'Rectangle' instead of using "inheritance", in order of enforcing an
// "interface contract"
static_assert(vp::AppliesAlgo<Rectangle>);