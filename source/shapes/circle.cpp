#include <utility>

#include "circle.hpp"

#include "algos/area.hpp"
#include "algos/perimeter.hpp"

void Circle::apply(vp::algo_variant& algo)
{
  std::visit([&circle = std::as_const(*this)](auto& algorithm)
             { algorithm.apply(circle); },
             algo);
}