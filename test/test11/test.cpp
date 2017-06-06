#include <iostream>
#include <string>
#include <cassert>
#include <base64.hpp>

int main(void) {
  const std::string *src = new std::string("田中 真奈美 (まなみん)");
  const std::string *dst = new std::string("55Sw5LitIOecn+WliOe+jiAo44G+44Gq44G/44KTKQ==");
  
  std::string *dst_e = new std::string();
  std::string *dst_d = new std::string();
  
  Base64::encode(src, dst_e);
  
  assert(*dst_e == *dst);
  
  Base64::decode(reinterpret_cast<const std::string*>(dst_e), dst_d);
  
  assert(*dst_d == *src);
  
  delete src;
  delete dst;
  
  delete dst_e;
  delete dst_d;
  
  return 0;
}
