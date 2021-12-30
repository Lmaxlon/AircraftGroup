#include <iostream>

int main(){
#if __cplusplus == 201703L
  std::cout << "It's C++17" << std::endl;
#elif __cplusplus == 201402L
  std::cout << "It's C++14" << std::endl;
#elif __cplusplus == 201103L
  std::cout << "It's C++11" << std::endl;
#else
  std::cout << "It's C++" << std::endl;
#endif
}