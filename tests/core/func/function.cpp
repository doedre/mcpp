import core.func;

auto main() -> int
{
  core::func::function<int()> f;
  f.func = [](){ return 0; };
  return f.func();
}

