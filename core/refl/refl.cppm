module;

#include <source_location>
#include <string_view>
#include <tuple>

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

  template<typename T, auto V>
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

  template<auto V>
  struct member_name_info {
    static constexpr auto name { func_name<V>() };
    static constexpr auto begin { name.find("[Vs = <") + "[Vs = <"sv.size() };
    static constexpr auto end { name.size() - 2 };

    static_assert(begin <= end);
  };

  template<typename T>
  extern const T extern_ { };

  template<typename T>
  struct ref {
    T& m_ref;
  };

  template<typename T>
  ref(T&) -> ref<T>;

  template<typename T, typename U = std::remove_cvref_t<T>>
  constexpr auto to_ptr_tuple(T&& v)
  {
    const auto& [l1, l2] = v;
    return std::make_tuple(&l1, &l2);
  }

  template<typename T>
  struct wrapper {
    explicit constexpr wrapper(const T& v) : value(v) { }
    T value;
    static wrapper<T> fake;
  };

  template<typename T, std::size_t N>
  consteval auto get_ptr() noexcept
  {
    return wrapper(std::get<N>(to_ptr_tuple(wrapper<T>::fake.value)));
  }
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

  template<typename T>
  [[nodiscard]] constexpr auto name_of_first_member(type_of<T> t) noexcept -> std::string_view
  {
    const auto info = impl::func_name<T, impl::get_ptr<T, 1>()>();
    return info;
  }
} // namespace core::refl

