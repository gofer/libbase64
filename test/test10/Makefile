STATIC_TARGET = test.static.out
SHARED_TARGET = test.shared.out
TARGET = $(STATIC_TARGET) $(SHARED_TARGET)

SRCS=test.cpp
OBJS=$(addsuffix .o,$(basename $(SRCS)))

LD = g++
LDFLAGS += -L../../lib $(shell pkg-config --libs gtest gtest_main)
CXXFLAGS += -std=c++11 -I../../include $(shell pkg-config --cflags gtest gtest_main)
LIBS=-lbase64

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

static: $(STATIC_TARGET)

shared: $(SHARED_TARGET)

$(STATIC_TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ ../../lib/libbase64.a

$(SHARED_TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test: $(TARGET)
	make test-static
	make test-shared

test-static: $(STATIC_TARGET)
	GTEST_COLOR=1 ./test.static.out

test-shared: $(SHARED_TARGET)
	LD_LIBRARY_PATH=../../lib:${LD_LIBRARY_PATH} GTEST_COLOR=1 ./test.shared.out

clean:
	rm -f *.o

distclean:
	make clean && rm -f $(TARGET)
