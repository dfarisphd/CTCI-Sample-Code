//==============================================================================
// C++ 0X ONLY
//
// /opt/local/bin/g++-mp-4.7 -std=c++0x test-memoize.cxx -o test-memoize
// ./test-memoize 
// 6765
// 1855967520
//==============================================================================

#include <functional>
#include <iostream>
#include <tuple>
#include <map>

//==============================================================================

template <typename ReturnType, typename... Args>
std::function<ReturnType (Args...)> memoize(std::function<ReturnType (Args...)> func) {
  std::map<std::tuple<Args...>, ReturnType> cache;
  return ([=](Args... args) mutable {
          std::tuple<Args...> t(args...);
          if (cache.find(t) == cache.end())
             cache[t] = func(args...);
          return cache[t];
  });
}

std::function<int (int)> f;
int fib(int n) {
  if  (n < 2) return n;
  return f(n-1) + f(n-2);
}

std::function<int (int, int)> b;
int binomial(int n, int k) {
  if (k == 0 || n == k) return 1;
  return b(n-1, k) + b(n-1, k-1);
}


//==============================================================================

int main(void) {
  f = memoize(std::function<int (int)>(fib));
  std::cout << f(20) << std::endl;
  b = memoize(std::function<int (int, int)>(binomial));
  std::cout << b(34,15) << std::endl;
}

//==============================================================================
