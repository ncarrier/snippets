#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "test.h"

static void foo(const char *str)
{
	const struct test *res;
	size_t len;

	len = strlen(str);

	res = test_struct_in_set(str, len);
	if (res != NULL)
		printf("%s is in set and %s.u = %d\n", str, str, res->u);
	else
		printf("%s isn't in set\n", str);
}

int main(void)
{
	foo("pim");
	foo("pam");
	foo("poum");
	foo("toto");
	foo("wizz");
	foo("");

	return EXIT_SUCCESS;
}
