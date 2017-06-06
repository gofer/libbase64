TEST_DIRS = test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12

.PHONY: all test distclean

all:
	@for dir in $(TEST_DIRS); do pushd $${dir}; make; popd; done

test:
	@for dir in $(TEST_DIRS); do pushd $${dir}; make test; popd; done

clean:
	@for dir in $(TEST_DIRS); do pushd $${dir}; make clean; popd; done

distclean:
	@for dir in $(TEST_DIRS); do pushd $${dir}; make distclean; popd; done
