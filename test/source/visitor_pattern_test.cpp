#include <cinttypes>
#include <cmath>

#include "acutest.h"
#include "algos/area.hpp"
#include "algos/perimeter.hpp"
#include "shapes/circle.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/square.hpp"

// clang-format off
struct
{
  const char* description;
  const double expected_area;
  const double expected_perimeter;
  vp::shape_variant shape_v;
} test_data[] = {
  {
    .description = "Circle-radius10",
    .expected_area = 314.16,
    .expected_perimeter = 62.83,
    .shape_v = Circle(10, "circle-r10")
  },
  {
    .description = "Square-length10",
    .expected_area = 100,
    .expected_perimeter = 40,
    .shape_v = Square(10, "square-l10")
  },
  {
    .description = "Rectangle-length10-width2",
    .expected_area = 20,
    .expected_perimeter = 24,
    .shape_v = Rectangle(10, 2, "rectangle-l10-w2")
  },
  {
    .description = "Circle-radius50",
    .expected_area = 7853.98,
    .expected_perimeter = 314.16,
    .shape_v = Circle(50, "circle-r50")
  },
  {
    .description = "Square-length7",
    .expected_area = 49,
    .expected_perimeter = 28,
    .shape_v = Square(7, "square-l7")
  },
  {
    .description = "Rectangle-length97-width2",
    .expected_area = 194,
    .expected_perimeter = 198,
    .shape_v = Rectangle(97, 2, "rectangle-l10-w2")
  },
  {
    .description = "Circle-radius53",
    .expected_area = 8824.73,
    .expected_perimeter = 333.01,
    .shape_v = Circle(53, "circle-r53")
  },
  {
    .description = "Square-length74",
    .expected_area = 5476,
    .expected_perimeter = 296,
    .shape_v = Square(74, "square-l74")
  },
  {
    .description = "Rectangle-length8-width66",
    .expected_area = 528,
    .expected_perimeter = 148,
    .shape_v = Rectangle(8, 66, "rectangle-l8-w66")
  },
  {
    .description = "Circle-radius47",
    .expected_area = 6939.78,
    .expected_perimeter = 295.31,
    .shape_v = Circle(47, "circle-r47")
  },
  {
    .description = "Square-length12",
    .expected_area = 144,
    .expected_perimeter = 48,
    .shape_v = Square(12, "square-l12")
  },
  {
    .description = "Rectangle-length63-width29",
    .expected_area = 1827,
    .expected_perimeter = 184,
    .shape_v = Rectangle(63, 29, "rectangle-l63-w29")
  }
};
// clang-format on

[[nodiscard]] bool DoublesAreSame(const double a, const double b)
{
  static constexpr double EPSILON {0.01};
  return std::fabs(a - b) < EPSILON;
}

void test_visitor(void)
{
  vp::algo_variant area_v {std::in_place_type<Area>},
      perimeter_v {std::in_place_type<Perimeter>};

  printf("\n");
  for (auto& test_item : test_data) {
    printf("Checking [%s]\n", test_item.description);
    TEST_CASE(test_item.description);

    std::visit(
        [&area_v, &perimeter_v](auto& shape)
        {
          shape.apply(area_v);
          shape.apply(perimeter_v);
        },
        test_item.shape_v);

    const auto area_result = std::get<Area>(area_v).get();
    const auto perimeter_result = std::get<Perimeter>(perimeter_v).get();

    TEST_CHECK(DoublesAreSame(test_item.expected_area, area_result));
    TEST_MSG("expected area: %.2f", test_item.expected_area);
    TEST_MSG("produced area: %.2f", area_result);

    TEST_CHECK(DoublesAreSame(test_item.expected_perimeter, perimeter_result));
    TEST_MSG("expected perimeter: %.2f", test_item.expected_perimeter);
    TEST_MSG("produced perimeter: %.2f", perimeter_result);
  }
}

TEST_LIST = {
    {"visitor", test_visitor},
    {NULL, NULL}  // zeroed record marking the end of the list
};
