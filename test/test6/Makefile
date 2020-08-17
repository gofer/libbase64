TARGET = test.out

SRCS=test.cpp
OBJS=$(addsuffix .o,$(basename $(SRCS)))

LD = g++
LDFLAGS += -L../../lib $(shell pkg-config --libs gtest gtest_main)
CXXFLAGS += -std=c++11 -I../../include $(shell pkg-config --cflags gtest gtest_main)
LIBS=-lbase64

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test: $(TARGET)
	GTEST_COLOR=1 ./$(TARGET)

clean:
	rm -f *.o

distclean:
	make clean && rm -f $(TARGET)
