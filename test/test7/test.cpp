#include <iostream>
#include <string>
#include <base64.hpp>
#include <gtest/gtest.h>

TEST(TestCase7_Risa_Taneda_Multibyte_UTF8_mod0, WithRefrence) {
  const std::string src("種田梨沙");
  const std::string dst("56iu55Sw5qKo5rKZ");
  
  std::string dst_e = Base64::encode(src);
  
  assert(dst_e == dst);
  
  std::string dst_d = Base64::decode(dst_e);
  
  assert(dst_d == src);
}

TEST(TestCase7_Risa_Taneda_Multibyte_UTF8_mod0, WithPointer) {
  const std::string *src = new std::string("種田梨沙");
  const std::string *dst = new std::string("56iu55Sw5qKo5rKZ");
  
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
}
