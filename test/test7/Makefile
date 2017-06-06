TARGET = test.out

SRCS=test.cpp
OBJS=$(addsuffix .o,$(basename $(SRCS)))

LD = g++
LDFLAGS += -L../../
CXXFLAGS += -std=c++11 -I../../include

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -lbase64

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o

distclean:
	make clean && rm -f $(TARGET)
