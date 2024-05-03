import core.refl;

#include <string_view>
#include <iostream>

using namespace core;

struct foo {
  int a;
  int b;
};

int func(int x, float y) { return 1; }

void bar() { }

auto lambda = [](int x, double y) { return 1; };

int main()
{
  static_assert(refl::name_of(refl::type<void>) == "void");
  static_assert(refl::name_of(refl::type<int>) == "int");
  static_assert(refl::name_of(refl::type<const int>) == "const int");
  static_assert(refl::name_of(refl::type<foo>) == "foo");
  static_assert(refl::name_of(refl::type<decltype(func)>) == "int (int, float)");

  const int x = 10;
  const int* px = &x;
  static_assert(refl::name_of(refl::type_of(x)) == "const int");
  static_assert(refl::name_of(refl::type_of(px)) == "const int *");
  
  //static_assert(refl::name_of(refl::type_of<decltype(lambda)>) == "lambda");

  //std::cerr << refl::impl::func_name<refl::impl::ref{refl::impl::extern_<foo>}>() << std::endl;
  std::cerr << refl::name_of_first_member(refl::type<foo>) << std::endl;
  return 1;
  /*
  //static_assert(refl::name_of(refl::type_of<int>) == "int");
  std::cerr << refl::name_of(refl::type_of<int>) << std::endl;
  std::cerr << refl::name_of(refl::type_of<std::string_view>) << std::endl;
  return 1;
  */
}

