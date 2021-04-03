#include <iostream>
#include <string>
#include <base64.hpp>
#include <gtest/gtest.h>

TEST(TestCase12_Yumi_Uchiyama_Multibyte_UTF8_Including_Null_mod1, WithRefrence) {
  const std::string src("\0内山\0夕実\0(みゆ)", 23);
  const std::string dst("AOWGheWxsQDlpJXlrp8AKOOBv+OChik=");
  
  std::string dst_e = Base64::encode(src);
  
  ASSERT_EQ(dst_e, dst);
  
  std::string dst_d = Base64::decode(dst_e);
  
  ASSERT_EQ(dst_d, src);
}

TEST(TestCase12_Yumi_Uchiyama_Multibyte_UTF8_Including_Null_mod0, WithPointer) {
  const std::string *src = new std::string("\0内山\0夕実\0(みゆ)", 23);
  const std::string *dst = new std::string("AOWGheWxsQDlpJXlrp8AKOOBv+OChik=");
  
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
