#pragma once

#include <string>
#include <string_view>

#include "utils.hpp"

class Square
{
public:
  const double length;
  const std::string name;

  Square(const double _length, std::string_view _name)
      : length {_length}
      , name {_name}
  {
  }

  Square() = delete;
  ~Square() = default;

  Square(const Square&) = delete;  // Copy ctor
  Square(Square&&) = default;  // Move ctor
  Square& operator=(const Square&) = delete;  // Copy assignment operator
  Square& operator=(Square&&) = delete;  // Move assignment operator

  void apply(vp::algo_variant& algo);
};

// this is to validate at compile-time the 'AppliesAlgo' concept applied on
// 'Square' instead of using "inheritance", in order of enforcing an
// "interface contract"
static_assert(vp::AppliesAlgo<Square>);