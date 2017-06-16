TARGET = test.out

SRCS=test.cpp
OBJS=$(addsuffix .o,$(basename $(SRCS)))

LD = g++
LDFLAGS += -L../../ -L$(GTEST_DIR)/lib
CXXFLAGS += -std=c++11 -I../../include -I$(GTEST_DIR)/include

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -lbase64 -lgtest -lgtest_main -lpthread

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o

distclean:
	make clean && rm -f $(TARGET)
