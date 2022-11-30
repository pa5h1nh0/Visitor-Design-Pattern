#pragma once

#include <string>
#include <string_view>

#include "utils.hpp"

class Circle
{
public:
  const double radius;
  const std::string name;

  Circle(const double _radius, std::string_view _name)
      : radius {_radius}
      , name {_name}
  {
  }

  Circle() = delete;
  ~Circle() = default;

  Circle(const Circle&) = delete;  // Copy ctor
  Circle(Circle&&) = default;  // Move ctor
  Circle& operator=(const Circle&) = delete;  // Copy assignment operator
  Circle& operator=(Circle&&) = delete;  // Move assignment operator

  void apply(vp::algo_variant& algo);
};

// this is to validate at compile-time the 'AppliesAlgo' concept applied on
// 'Circle' instead of using "inheritance", in order of enforcing an
// "interface contract"
static_assert(vp::AppliesAlgo<Circle>);