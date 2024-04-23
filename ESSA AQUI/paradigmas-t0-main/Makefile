examples = \
	lsearch \
	intarray \
	genarray

examples/%: examples/%.o src/%.o
	$(CC) $(CFLAGS) -o $(@) $(^)

all_tests=$(wildcard features/*.cpp)

RUN_IN_UBUNTU ?= 0

CFLAGS = -I src
CXXFLAGS = -std=c++14 -I src -D GITHUB_WORKFLOW=$(RUN_IN_UBUNTU)

ifeq ($(RUN_IN_UBUNTU),1)
LDFLAGS = -lCatch2WithMain
else
LDFLAGS = -lCatch2 -lCatch2Main
endif

TARGETS = $(addprefix examples/, $(examples))
TESTS = $(patsubst %.cpp,%,$(all_tests))

targets: $(TARGETS) $(TESTS)

all: targets test memtest

test:
	@features/utils/bdd_test.sh $(TESTS)

memtest:
	@features/utils/memtest.sh $(TESTS)

clean:
	$(RM) $(TESTS) features/*.o{,pp} examples/*.o src/*.o{,pp}

FORCE:

.PHONY: all clean tests memtest

include Makefile.rules

examples/lsearch: examples/lsearch.o src/util.o
	$(CC) -o $(@) $(^)
