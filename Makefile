include Makefile.in

TARGET = $(TARGET_STATIC) $(TARGET_SHARED)

.PHONY: all test clean distclean

all:
	make shared
	make static

static: lib/libbase64.a

shared: lib/libbase64.so

lib/libbase64.a:
	@if [ ! -d lib ]; then mkdir -p lib; fi
	make -f Makefile.static

lib/libbase64.so:
	@if [ ! -d lib ]; then mkdir -p lib; fi
	make -f Makefile.shared

test: $(TARGET)
	make test-static
	make test-shared

test-static: lib/libbase64.a
	make -f Makefile.static test

test-shared: lib/libbase64.so
	make -f Makefile.shared test

clean:
	make -f Makefile.static clean
	make -f Makefile.shared clean

distclean:
	make -f Makefile.static distclean
	make -f Makefile.shared distclean
	rm -rf lib
