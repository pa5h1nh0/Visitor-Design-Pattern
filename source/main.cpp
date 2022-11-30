#include <algorithm>
#include <iostream>
#include <vector>

#include "algos/area.hpp"
#include "algos/perimeter.hpp"
#include "shapes/circle.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/square.hpp"

int main(void)
{
  // a collection of shape variants
  std::vector<vp::shape_variant> shapes;

  // a circle of radius=10
  shapes.emplace_back(std::in_place_type<Circle>, 10, "circle");
  // a square of length=10
  shapes.emplace_back(std::in_place_type<Square>, 10, "square");
  // a rectangle of length=10 and width=2
  shapes.emplace_back(std::in_place_type<Rectangle>, 10, 2, "rectangle");

  // algorithms to be applied on each shape
  vp::algo_variant area_v {std::in_place_type<Area>},
      perimeter_v {std::in_place_type<Perimeter>};

  try {
    std::ranges::for_each(
        shapes,
        [&area_v, &perimeter_v](auto& shape_v)
        {
          // for each 'shape' in 'shapes'..
          std::visit(
              [&area_v, &perimeter_v](auto& shape)
              {
                // apply 'Area' and 'Perimeter' algorithms on it
                shape.apply(area_v);
                shape.apply(perimeter_v);

                printf("shapes[name=%s]: ", shape.name.c_str());
              },
              shape_v);

          std::visit([](const auto& area)
                     { printf("area = %.2f, ", area.get()); },
                     area_v);
          std::visit([](const auto& perimeter)
                     { printf("perimeter = %.2f", perimeter.get()); },
                     perimeter_v);
          printf("\n");
        });
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  /* The reason I decided to apply the "visitor" pattern via C++17's
   * 'std::variant' instead of the "traditional" C++ polymorphism via
   * inheritance is because I wanted to show an alternative way of doing the
   * same thing, but with a special focus on a hopefully more "modern C++"
   * approach.
   *
   * IMPROVEMENT IDEAS:
   * ------------------
   * I could've also added a thread pool for applying 'Area' and 'Perimeter'
   * algos on several shapes at the same time (i.e., concurrently), but this
   * would unnecessarily overcomplicate things.
   * Anyway, I would've done it as follows:
   *   - using a shared lock-free queue
   *     (https://github.com/KjellKod/Moody-Camel-s-concurrentqueue) of
   *     (shape_variant, algo_variant) pair objects;
   *   - using a memory pool
   *     (https://www.boost.org/doc/libs/1_80_0/libs/pool/doc/html/boost/object_pool.html)
   *     for allocating 'shape_variant' objects;
   *   - managing the lifetime of an allocated 'shape_variant' object via
   *     'std::unique_ptr' with a custom deleter in order to properly free the
   *     allocated object by releasing it back to its memory pool instance
   *     created in the previous step;
   *   - allocating a thread pool of size N, where N is the nr of CPU cores
   *     on the running system;
   *   - each thread in the thread pool blocked on the lock-free queue to
   *     receive a (shape_variant, algo_variant) pair, applying the algorithm on
   *     the received shape (implicitly storing the result in the received
   *     algorithm instance);
   *   - finally, the main thread would simply need to iterate over each per
   *     shape algorithm instance to retrieve the results.
   */

  return 0;
}