#include <iostream>
#include <string>
#include <base64.hpp>
#include <gtest/gtest.h>

TEST(TestCase10_Yoko_Inokuma_Including_Null_mod2, WithRefrence) {
  const std::string src("\0Yoko\0Inokuma", 13);
  const std::string dst("AFlva28ASW5va3VtYQ==");
  
  std::string dst_e = Base64::encode(src);
  
  ASSERT_EQ(dst_e, dst);
  
  std::string dst_d = Base64::decode(dst_e);
  
  ASSERT_EQ(dst_d, src);
}

TEST(TestCase10_Yoko_Inokuma_Including_Null_mod2, WithPointer) {
  const std::string *src = new std::string("\0Yoko\0Inokuma", 13);
  const std::string *dst = new std::string("AFlva28ASW5va3VtYQ==");
  
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
