warning-flags := -Wall -Wextra -Wmissing-prototypes \
		 -Wstrict-prototypes -Wmissing-declarations

main:test.c main.c
	gcc $^ -o $@ $(warning-flags) -O0 -g3

test.c:test.gperf
	gperf $^ --output-file=$@ --multiple-iterations=100

clean:
	rm -f main test.c

.PHONY: clean
