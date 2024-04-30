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
    std::size_t begin { name.find("[Ts = <") + "[Ts = <"sv.size() };
    std::size_t end { name.size() - 2 };
  };
}

export namespace core::refl {
  template<typename T>
  struct type { };

  template<typename T>
  constexpr type<T> type_of { };

  template<typename T>
  consteval auto name_of(type<T> t) noexcept -> std::string_view
  {
    const auto info = impl::name_info<T>();
    return { info.name.data() + info.begin, info.end - info.begin };
  }

  template<typename T>
  struct type_info {
    using type = T;

    std::string_view name { name_of(type_of<T>) };
  };
} // namespace core::refl

