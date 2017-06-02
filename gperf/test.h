#ifndef _TEST_H
#define _TEST_H

struct test {
	const char *id;
	int u;
	const char *plop;
	float v;
};

const struct test *test_struct_in_set(register const char *str,
		register unsigned int len);

#define TEST_STR_MAX_LEN 0x400

char *test_to_str(const struct test *test, char buffer[TEST_STR_MAX_LEN]);

#endif /* _TEST_H */
