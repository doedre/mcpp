#include <cassert>

import core.func;

using namespace core;

int add()
{
  return 10;
}

struct A {
  static auto static_method() -> int { return 30; }
  auto method() -> int { return 40; }
  auto const_method() const -> int { return 50; }
};

auto main() -> int
{
  A a { };
  func::function<int()> fp { add };
  func::function<int()> flambda { [](){ return 20; } };
  func::function<int()> fsm { A::static_method };
  func::function<int(A&)> fm { &A::method };
  func::function<int(const A&)> fcm { &A::const_method };

  assert(fp() == 10);
  assert(flambda() == 20);
  assert(fsm() == 30);
  assert(fm(a) == 40);
  assert(fcm(a) == 50);

  return 0;
}

