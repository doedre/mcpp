import core.refl;

#include <string_view>
//#include <iostream>

using namespace core;

struct foo { };

int func(int x, float y) { return 1; }

auto lambda = [](int x, double y) { return 1; };

int main()
{
  static_assert(refl::name_of(refl::type_of<void>) == "void");
  static_assert(refl::name_of(refl::type_of<int>) == "int");
  static_assert(refl::name_of(refl::type_of<const int>) == "const int");
  static_assert(refl::name_of(refl::type_of<foo>) == "foo");
  static_assert(refl::name_of(refl::type_of<decltype(func)>) == "int (int, float)");
  //static_assert(refl::name_of(refl::type_of<decltype(lambda)>) == "lambda");

  /*
  //static_assert(refl::name_of(refl::type_of<int>) == "int");
  std::cerr << refl::name_of(refl::type_of<int>) << std::endl;
  std::cerr << refl::name_of(refl::type_of<std::string_view>) << std::endl;
  return 1;
  */
}

