#include <iostream>
#include <string>
#include <base64.hpp>

void type1() {
	const std::string *src = new std::string("hogehogefoobar");
	std::string *dst_e = new std::string();
	std::string *dst_d = new std::string();
	
	Base64::encode(src, dst_e);
	
	std::cout << *dst_e << std::endl;
	
	Base64::decode(reinterpret_cast<const std::string*>(dst_e), dst_d);
	
	std::cout << *dst_d << std::endl;
	
	delete src;
	delete dst_e;
	delete dst_d;
}

void type2() {
	const std::string src("hogehogefoobar");
	std::string dst = Base64::encode(src);
	std::cout << dst << std::endl;
	std::cout << Base64::decode(dst) << std::endl;
}

int main(void) {
	type1();
	
	type2();
	
	return 0;
}
