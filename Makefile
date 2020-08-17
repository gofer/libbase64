TARGET = libbase64.a libbase64.so

.PHONY: all test clean distclean

all: $(TARGET)

libbase64.a:
	make -f Makefile.static
	make -f Makefile.static test
	make -f Makefile.static clean

libbase64.so: libbase64.a
	make -f Makefile.shared
	make -f Makefile.shared test
	make -f Makefile.shared clean

clean:
	make -f Makefile.static clean
	make -f Makefile.shared clean

distclean:
	make -f Makefile.static distclean
	make -f Makefile.shared distclean
