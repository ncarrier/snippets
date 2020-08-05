#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

#include <search.h>
#include <error.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

int main(void)
{
	/* zeroing out the structure is crucial */
	struct hsearch_data htab = {0};
	int ret;
	struct entry data[] = {
			{
					.key = "plop",
					.data = "wizz"
			},
			{
					.key = "blop",
					.data = "fizz"
			},
			{
					.key = "hop",
					.data = "pizz"
			},
			{
					.key = "stop",
					.data = "tizz"
			},
			{
					.key = "gop",
					.data = "zizz"
			},
	};
	struct entry *result;
	unsigned int i;
	const char *key;

	/* create an hash table, the size is fixed at creation */
	ret = hcreate_r(sizeof(data), &htab); /* beware, non-zero is SUCCESS */
	if (ret == 0)
		error(EXIT_FAILURE, errno, "hcreate_r");

	/* populate the htable */
	for (i = 0; i < ARRAY_SIZE(data); i++) {
		ret = hsearch_r(data[i], ENTER, &result, &htab);
		if (ret == 0)
			error(EXIT_FAILURE, errno, "hsearch_r");
	}

	/* searching an existing key */
	key = "stop";
	/*
	 * note that the key member of struct entry is not const when it should,
	 * hence the ugly cast to (char *)
	 */
	ret = hsearch_r((struct entry){.key = (char *)key}, FIND, &result,
			&htab);
	if (ret == 0)
		error(EXIT_FAILURE, errno, "hsearch_r");
	printf("Entry for key \"%s\" found: \"%s\"\n", key,
			(char *)result->data);
	/* searching a non-existing key */
	key = "flop";
	ret = hsearch_r((struct entry){.key = (char *)key}, FIND, &result,
			&htab);
	if (ret == 0 && errno != ESRCH)
		error(EXIT_FAILURE, errno, "hsearch_r");
	printf("No entry found for key \"%s\": %p\n", key, result);

	/*
	 * check all the entries have correctly been inserted.
	 * note that iterating on the hash map is possible only the list of the
	 * keys has been maintained.
	 */
	for (i = 0; i < ARRAY_SIZE(data); i++) {
		ret = hsearch_r((struct entry){.key = data[i].key}, FIND,
				&result, &htab);
		if (ret == 0)
			error(EXIT_FAILURE, errno, "hsearch_r");
		assert(strcmp(data[i].data, result->data) == 0);
	}

	/* unfortunately, no entry removal is possible */

	hdestroy_r(&htab);

	return EXIT_SUCCESS;
}
