warning-flags := -Wall -Wextra -Wmissing-prototypes \
		 -Wstrict-prototypes -Wmissing-declarations

main: main.c
	gcc $^ -o $@ $(warning-flags) -O0 -g3

clean:
	rm -f main

.PHONY: clean
