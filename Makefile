TARGET = lib/libbase64.a lib/libbase64.so

.PHONY: all test clean distclean

all: $(TARGET)

lib/libbase64.a:
	mkdir -p lib
	make -f Makefile.static
	make -f Makefile.static test
	make -f Makefile.static clean

lib/libbase64.so: lib/libbase64.a
	mkdir -p lib
	make -f Makefile.shared
	make -f Makefile.shared test
	make -f Makefile.shared clean

shared: lib/libbase64.so

static: lib/libbase64.a

clean:
	make -f Makefile.static clean
	make -f Makefile.shared clean

distclean:
	make -f Makefile.static distclean
	make -f Makefile.shared distclean
