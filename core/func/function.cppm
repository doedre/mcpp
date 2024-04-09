module;

#include <functional>
#include <memory>
#include <utility>

export module core.func:function;

export namespace core::func {
  template<typename>
  class function;

  template<typename R, typename... ArgTypes>
  class function<R(ArgTypes...)> {
    public:
      template<typename FunctionObject>
      function(FunctionObject fobj) :
          m_callable { std::make_unique<callable<FunctionObject>>(std::move(fobj)) }
      { }

      R operator()(ArgTypes... args) {
        return m_callable->call(args...);
      }

    private:
      struct callable_interface {
        virtual R call(ArgTypes... args) = 0;
        virtual ~callable_interface() = default;
      };

      template<typename Callable>
      struct callable : callable_interface {
        callable(Callable callable) :
            m_callable { std::move(callable) }
        { }

        R call(ArgTypes... args) override {
          return std::invoke(std::forward<Callable>(m_callable), std::forward<ArgTypes>(args)...);
        }

        Callable m_callable;
      };

      std::unique_ptr<callable_interface> m_callable;
  };
}

