#include <iostream>
#include <string>
#include <base64.hpp>
#include <gtest/gtest.h>

TEST(TestCase6_Manami_Tanaka_Multibyte_UTF8_mod2, WithRefrence) {
  const std::string src("田中 真奈美 (まなみん)");
  const std::string dst("55Sw5LitIOecn+WliOe+jiAo44G+44Gq44G/44KTKQ==");
  
  std::string dst_e = Base64::encode(src);
  
  ASSERT_EQ(dst_e, dst);
  
  std::string dst_d = Base64::decode(dst_e);
  
  ASSERT_EQ(dst_d, src);
}

TEST(TestCase6_Manami_Tanaka_Multibyte_UTF8_mod2, WithPointer) {
  const std::string *src = new std::string("田中 真奈美 (まなみん)");
  const std::string *dst = new std::string("55Sw5LitIOecn+WliOe+jiAo44G+44Gq44G/44KTKQ==");
  
  std::string *dst_e = new std::string();
  std::string *dst_d = new std::string();
  
  Base64::encode(src, dst_e);
  
  ASSERT_EQ(*dst_e, *dst);
  
  Base64::decode(reinterpret_cast<const std::string*>(dst_e), dst_d);
  
  ASSERT_EQ(*dst_d, *src);
  
  delete src;
  delete dst;
  
  delete dst_e;
  delete dst_d;
}
