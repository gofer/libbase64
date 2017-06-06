TEST_DIRS = test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12

.PHONY: all test distclean

all:
	@for dir in $(TEST_DIRS); do cd $${dir}; make; cd ..; done

test:
	@for dir in $(TEST_DIRS); do cd $${dir}; make test; cd ..; done

clean:
	@for dir in $(TEST_DIRS); do cd $${dir}; make clean; cd ..; done

distclean:
	@for dir in $(TEST_DIRS); do cd $${dir}; make distclean; cd ..; done
