warning-flags := \
		-Wall \
		-Wextra \
		-Wformat=2 \
		-Wunused-variable \
		-Wold-style-definition \
		-Wstrict-prototypes \
		-Wno-unused-parameter \
		-Wmissing-declarations \
		-Wmissing-prototypes \
		-Wpointer-arith \
		-Werror

optim-flags := -O0 -g3

bin := list

$(bin):$(bin).c
	gcc $^ -o $@ $(warning-flags) $(optim-flags)

clean:
	rm -f $(bin)

.PHONY: clean
