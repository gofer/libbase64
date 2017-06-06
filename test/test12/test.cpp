#include <iostream>
#include <string>
#include <cassert>
#include <base64.hpp>

int main(void) {
	const std::string src("田中 真奈美 (まなみん)");
  const std::string dst("55Sw5LitIOecn+WliOe+jiAo44G+44Gq44G/44KTKQ==");
  
	std::string dst_e = Base64::encode(src);
  
	assert(dst_e == dst);
  
  std::string dst_d = Base64::decode(dst_e);
	
  assert(dst_d == src);
	
	return 0;
}
