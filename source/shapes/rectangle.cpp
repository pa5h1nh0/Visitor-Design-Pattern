#include <utility>

#include "rectangle.hpp"

#include "algos/area.hpp"
#include "algos/perimeter.hpp"

void Rectangle::apply(vp::algo_variant& algo)
{
  std::visit([&rect = std::as_const(*this)](auto& algorithm)
             { algorithm.apply(rect); },
             algo);
}