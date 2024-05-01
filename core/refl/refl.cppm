module;

#include <string_view>
#include <source_location>

export module core.refl;

using namespace std::string_view_literals;

namespace core::refl::impl {
  template<typename... Ts>
  [[nodiscard]] consteval auto func_name() noexcept -> std::string_view
  {
    return std::source_location::current().function_name();
  }

  template<auto... Vs>
  [[nodiscard]] consteval auto func_name() noexcept -> std::string_view
  {
    return std::source_location::current().function_name();
  }

  template<typename T>
  struct name_info {
    static constexpr auto name { func_name<T>() };
    static constexpr auto begin { name.find("[Ts = <") + "[Ts = <"sv.size() };
    static constexpr auto end { name.size() - 2 };

    static_assert(begin <= end);
  };
}

export namespace core::refl {
  template<typename T>
  struct type_of {
    constexpr type_of() = default;
    constexpr type_of(T&) { }
  };

  template<>
  struct type_of<void> {
    constexpr type_of() = default;
  };

  template<typename T>
  type_of(T&) -> type_of<T>;

  template<typename T>
  constexpr type_of<T> type { };

  template<typename T>
  [[nodiscard]] constexpr auto name_of(type_of<T> t) noexcept -> std::string_view
  {
    const auto info = impl::name_info<T>();
    return { info.name.data() + info.begin, info.end - info.begin };
  }
} // namespace core::refl

