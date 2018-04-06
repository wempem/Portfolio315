MAIN=src/main.cpp
SRCS := $(filter-out $(MAIN),$(wildcard src/*.cpp))
CFLAGS=-g -I src/ -O2
BIN=map-test
.PHONY: clean test all

all:
	g++ -o ${BIN} $(CFLAGS) ${SRCS} ${MAIN}

run: all
	./${BIN}

%test:
	cxxtestgen --runner=ErrorPrinter -o tests/test-runner.cpp tests/$@.cpp ${SRCS}
	g++ ${CFLAGS} tests/test-runner.cpp $(SRCS) -o test-runner
	./test-runner

valgrind: all
	valgrind ./${BIN}

clean:
	rm -rf ${BIN} tests/test-runner.cpp test-runner data/*data
