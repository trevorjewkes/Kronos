#include "catch.h"
#include "wx/string.h"

TEST_CASE("wx string") {
  wxString s("Hello wx");
  REQUIRE(s == "Hello wx");
  REQUIRE(s.length() == 8);
  REQUIRE(s.length() != 9);
}
