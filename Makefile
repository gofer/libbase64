TARGET = libbase64.a libbase64.so

SRCS = src/base64_encode.cpp src/base64_decode.cpp
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CXXFLAGS += -std=c++11 -Iinclude
ARFLAGS = rsv

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

libbase64.a: $(OBJS)
	$(AR) $(ARFLAGS) -o $@ $^

libbase64.so: $(OBJS)
	$(CXX) -shared -fPIC $(CXXFLAGS) -o $@ $^

.cpp.o:
	$(CXX) -fPIC $(CXXFLAGS) -o $@ -c $<

test: $(TARGET)
	cd test; LD_LIBRARY_PATH=$(shell pwd) make test GTEST_DIR=/usr/local/googletest/googletest-1.8.0

clean:
	pushd test && make clean && popd
	rm -f src/*.o

distclean:
	pushd test && make distclean && popd
	make clean && rm -f $(TARGET)
