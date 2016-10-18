#include "catch.h"
#include <boost/array.hpp> 

TEST_CASE("boost array") {
  boost::array<int, 4> nums = {1,2,3,4};
  REQUIRE(nums.size() == 4);
  REQUIRE(nums.size() != 5);
}
