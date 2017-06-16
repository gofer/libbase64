#include <iostream>
#include <base64.hpp>

int main(int argc, const char **argv)
{
  std::string str;
  
  std::cin >> str;
  
  std::cout << Base64::decode(str) << std::endl;
  
  return 0;
}