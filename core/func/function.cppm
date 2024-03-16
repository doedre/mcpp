export module core.func:function;

export namespace core::func {
  template<typename>
  class function;

  template<typename R, typename... ArgTypes>
  struct function<R(ArgTypes...)> {
    R (*func)(ArgTypes...) ;
  };
}

