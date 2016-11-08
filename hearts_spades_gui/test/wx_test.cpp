#include "catch.h"
#include "wx/string.h"
#include <stdio.h>

TEST_CASE("wx string") {
	wxString s;
	s = wxString::FromAscii("hello");
	//printf("%s", s.c_str()); //this is what the docs shay should work, it doesn't
	//std::cout << s.c_str() << std::endl; //this also doesn't work
  //REQUIRE(strcmp(s.c_str(), "Hello wx") == true);
  //REQUIRE(s->length() == 8);
  //REQUIRE(s->length() != 9);
}
