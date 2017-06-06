#include <iostream>
#include <string>
#include <cassert>
#include <base64.hpp>

int main(void) {
  const std::string *src = new std::string("東山 奈央 (とうやま なお)");
  const std::string *dst = new std::string("5p2x5bGxIOWliOWkriAo44Go44GG44KE44G+IOOBquOBiik=");
  
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
