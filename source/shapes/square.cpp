#include <utility>

#include "square.hpp"

#include "algos/area.hpp"
#include "algos/perimeter.hpp"

void Square::apply(vp::algo_variant& algo)
{
  std::visit([&square = std::as_const(*this)](auto& algorithm)
             { algorithm.apply(square); },
             algo);
}