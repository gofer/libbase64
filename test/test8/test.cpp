#include <iostream>
#include <string>
#include <base64.hpp>
#include <gtest/gtest.h>

TEST(TestCase8_Failed_Test, WithRefrence) {
  const std::string src("hoge");
  const std::string dst("foo");
  
  std::string dst_e = Base64::encode(src);
  
  ASSERT_EQ(dst_e, dst);
  
  std::string dst_d = Base64::decode(dst_e);
  
  ASSERT_EQ(dst_d, src);
}

TEST(TestCase8_Failed_Test, WithPointer) {
  const std::string *src = new std::string("hoge");
  const std::string *dst = new std::string("foo");
  
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
