# Base64 Encode/Decode Library for C++
[![BuldStatus](https://travis-ci.org/gofer/libbase64.svg?branch=dev-ver2)](https://travis-ci.org/gofer/libbase64)

## What's this
This is Base64 encode/decode library for C++.

## Attention
This code uses C++11 features.

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
In detail, please shows base64_test.cpp.
That code is compiled on following commands.

    g++ base64_test.cpp -I. -L. -lbase64 -std=c++11 -o test.out

## Licence
This codes are licensed by New BSD License.
