g++ base64_encode.cpp base64_decode.cpp -c -std=c++11 -I. -lstdc++
ar rsv libbase64.a base64_encode.o base64_decode.o
rm -f base64_encode.o > /dev/null
rm -f base64_decode.o > /dev/null
