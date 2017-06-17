TEST_DIRS = test1 test2 test3 test4 test5 test6 test7 test8

.PHONY: all test distclean

all:
	@for dir in $(TEST_DIRS); do cd $${dir}; make GTEST_DIR=$(GTEST_DIR); ret=$$?; if [ $${ret} -ne 0 ]; then exit $${ret}; fi; cd ..; done

test:
	@for dir in $(TEST_DIRS); do cd $${dir}; make test GTEST_DIR=$(GTEST_DIR); ret=$$?; if [ $${ret} -ne 0 ]; then exit $${ret}; fi; cd ..; done

clean:
	@for dir in $(TEST_DIRS); do cd $${dir}; make clean; cd ..; done

distclean:
	@for dir in $(TEST_DIRS); do cd $${dir}; make distclean; cd ..; done
