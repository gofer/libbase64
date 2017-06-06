#include <iostream>
#include <string>
#include <cassert>
#include <base64.hpp>

int main(void) {
  const std::string src("東山 奈央 (とうやま なお)");
  const std::string dst("5p2x5bGxIOWliOWkriAo44Go44GG44KE44G+IOOBquOBiik=");
  
  std::string dst_e = Base64::encode(src);
  
  assert(dst_e == dst);
  
  std::string dst_d = Base64::decode(dst_e);
  
  assert(dst_d == src);
  
  return 0;
}
