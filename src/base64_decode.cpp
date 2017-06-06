#include <base64.hpp>

namespace Base64 {
  int _get_char(char ch) {
    if('A' <= ch && ch <= 'Z') return (ch - 'A');      else
    if('a' <= ch && ch <= 'z') return 26 + (ch - 'a'); else
    if('0' <= ch && ch <= '9') return 52 + (ch - '0'); else
    if(ch == '+') return 62; else
    if(ch == '/') return 63; else
    if(ch == '=') return 0;
    return -1;
  }
  
  std::string _decode_split(std::string in) {
    in.resize(4, 0);
    
    uint32_t n = _get_char(in[0]) << 18 | 
                 _get_char(in[1]) << 12 | 
                 _get_char(in[2]) << 6  | 
                 _get_char(in[3]);
    
    char s[4];
    s[0] = (n & 0x00FF0000) >> 16;
    s[1] = (n & 0x0000FF00) >> 8;
    s[2] = (n & 0x000000FF) >> 0;
    s[3] = '\0';
    
    return std::string(s);
  }
  
  int decode(const std::string* src, std::string* dst) {
    for (uint64_t i = 0; i < src->length(); i += 4)
    {
      dst->append( _decode_split(src->substr(i, 4)) );
    }
    return 0;
  }
  
  std::string decode(const std::string& src) {
    std::string dst;
    for (uint64_t i = 0; i < src.length(); i += 4)
    {
      dst.append( _decode_split(src.substr(i, 4)) );
    }
    return dst;
  }
};
