# Base64 Encode/Decode Library for C++
[![BuldStatus](https://travis-ci.org/gofer/libbase64.svg?branch=dev-ver2)](https://travis-ci.org/gofer/libbase64)

## What's this
This is Base64 encode/decode library for C++.

## Attention
This code uses C++11 features.

## How to Build
If you have `make` command, type

    make

to build this library.

## How to use

### With pointer
Encode function is in namespace Base64. This function always return 0.

    int Base64::encode(const std::string* src, std::string* dst);

Decode function is in namespace Base64. This function always return 0.

    int Base64::decode(const std::string* src, std::string* dst);
  
### With reference
Encode function is in namespace Base64.

    std::string Base64::encode(const std::string& src);

Decode function is in namespace Base64.

    std::string Base64::decode(const std::string& src);

### Examples
An example code is here.

```c++
#include <iostream>
#include <base64.hpp>

int main()
{
  std::string src = "hogefoobar";
  
  std::string dst = Base64::encode(src);
  
  std::cout << src << ": " << dst << std::endl;
  
  return 0;
}
```

That code is compiled on following commands.

    g++ -Iinclude -L. base64_test.cpp -lbase64 -std=c++11 -o base64_test.out

In detail, see sample directory.

## Licence
This codes are licensed by New BSD License.
