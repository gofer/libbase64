#include <iostream>
#include <string>
#include <cassert>
#include <base64.hpp>

int main(void) {
	const std::string src("hogehogefoobar");
  const std::string dst("aG9nZWhvZ2Vmb29iYXI=");
  
	std::string dst_e = Base64::encode(src);
  
	assert(dst_e == dst);
  
  std::string dst_d = Base64::decode(dst_e);
	
  assert(dst_d == src);
	
	return 0;
}
