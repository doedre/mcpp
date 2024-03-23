#include <cassert>

import core.func;

using namespace core;

int add()
{
  return 10;
}

auto main() -> int
{
  func::function<int()> fp { add };
  func::function<int()> flambda { [](){ return 20; } };

  assert(fp() == 10);
  assert(flambda() == 20);

  return 0;
}

