TARGET = libbase64.a

SRCS = src/base64_encode.cpp src/base64_decode.cpp
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CXXFLAGS += -std=c++11 -Iinclude
ARFLAGS = rsv

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

$(TARGET): $(OBJS)
  $(AR) $(ARFLAGS) -o $@ $^

.cpp.o:
  $(CXX) $(CXXFLAGS) -o $@ -c $<

test: $(TARGET)
  cd test; make test

clean:
  pushd test && make clean && popd
  rm -f *.o

distclean:
  pushd test && make distclean && popd
  make clean && rm -f $(TARGET)
