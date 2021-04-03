#include <bits/stdint-uintn.h>
#include <iostream>
#include <fstream>
#include <string>
#include <base64.hpp>
#include <gtest/gtest.h>

const std::string SrcImgFile = "image_src.png";
const std::string DstTxtFile = "image_dst.txt";

namespace TestHelper
{
  const std::string::size_type BufferSize = 1024;

  std::string file_read(const std::string &file_name, std::ios_base::openmode mode)
  {
    std::ifstream ifs(file_name, std::ios_base::in | mode);
    if (!ifs) { return ""; }

    std::string str;
    char *buf = new char[BufferSize];
    ifs.seekg(0);
    while (!(ifs.eof() || ifs.fail()))
    {
      std::streamsize read_size = ifs.readsome(buf, BufferSize);
      if (read_size == 0) { break; }
      str.append(buf, read_size);
    } 
    delete[] buf;
    return str;
  }

  int file_read(const std::string &file_name, std::ios_base::openmode mode, std::string *str)
  {
    std::ifstream ifs(file_name, std::ios_base::in | mode);
    if (!ifs) { return -1; }

    char *buf = new char[BufferSize];
    ifs.seekg(0);
    while (!(ifs.eof() || ifs.fail()))
    {
      std::streamsize read_size = ifs.readsome(buf, BufferSize);
      if (read_size == 0) { break; }
      str->append(buf, read_size);
    }
    delete[] buf;
    return 0;
  }
};

TEST(TestCase13_PNG_Image_Binary_File_Byte_String, WithRefrence) {
  std::string src = TestHelper::file_read(SrcImgFile, std::ios::binary);
  std::string dst = TestHelper::file_read(DstTxtFile, std::ios_base::openmode(0));

  std::string dst_e = Base64::encode(src);
  
  ASSERT_EQ(dst_e, dst);
  
  std::string dst_d = Base64::decode(dst_e);
  
  ASSERT_EQ(dst_d, src);
}

TEST(TestCase13_PNG_Image_Binary_File_Byte_String, WithPointer) {
  std::string *src = new std::string();
  std::string *dst = new std::string();
  TestHelper::file_read(SrcImgFile, std::ios::binary, src);
  TestHelper::file_read(DstTxtFile, std::ios_base::openmode(0), dst);
  
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
