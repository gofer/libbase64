LD = g++
LDFLAGS += -L../
CXXFLAGS += -std=c++11 -I../include

.SUFFIXES: .cpp .hpp
.PHONY: all test clean distclean

all: encode.out decode.out

encode.out: encode.o
	$(LD) $(LDFLAGS) -o $@ $^ -lbase64

decode.out: decode.o
	$(LD) $(LDFLAGS) -o $@ $^ -lbase64

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f *.o

distclean:
	make clean && rm -f {encode,decode}.out
