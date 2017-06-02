#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void stepA(int data) { printf("%d: %s\n", data, __func__); }
static void stepB(int data) { printf("%d: %s\n", data, __func__); }
static void stepC(int data) { printf("%d: %s\n", data, __func__); }
static void (* const steps[])(int) = {stepA, stepB, stepC,};
static int fact(int n) { return n == 0 ? 1 : fact(n - 1) * n; }

static int compare_int(const void *pa, const void *pb)
{
	return *(const int *)pa - *(const int *)pb;
}

static void get_next_permutation(int tab[], size_t n)
{
	int tmp;
	unsigned i;
	unsigned j;
	unsigned k;

	/* to find the next permutation in the lexicographic order
	 *   source: question 4 (in french, sorry ^^) of
	 *   https://liris.cnrs.fr/~aparreau/Teaching/INF233/TP2-permutation.pdf
.	 */
	/* 1. find the biggest index i for which tab[i] < tab[i+1] */
	for (k = 0; k < n - 1; k++)
		if (tab[k] < tab[k + 1])
			i = k;

	/* 2. Find the index j of the smallest element, bigger than tab[i],
	 *   located after i */
	j = i + 1;
	for (k = i + 1; k < n; k++)
		if (tab[k] > tab[i] && tab[k] < tab[j])
			j = k;

	/* 3. Swap the elements of index i and j */
	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;

	/* 4. Sort the array in ascending order, after index i */
	qsort(tab + i + 1, n - (i + 1), sizeof(*tab), compare_int);
}

int main(void)
{
	int n = sizeof(steps) / sizeof(*steps);
	int j;
	int i;
	int permutation[n];
	int f = fact(n);

	/* first permutation is identity */
	for (i = 0; i < n; i++)
		permutation[i] = i;

	for (j = 0; j < f; j++) {
		for (i = 0; i < n; i++)
			steps[permutation[i]](i);
		if (j != f - 1)
			get_next_permutation(permutation, n);
	}

	return EXIT_SUCCESS;
}
