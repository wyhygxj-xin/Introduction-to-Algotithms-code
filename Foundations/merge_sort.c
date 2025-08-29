#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int p, int q, int r) {
	int nl = q - p + 1;
	int nr = r - q;

	int *L = (int *) malloc (nl * sizeof(int));
	int *R = (int *) malloc (nr * sizeof(int));

	int i = 0;
	int j = 0;
	for (i=0; i<nl; i++) {
		L[i] = A[p+i];
	}

	for (j=0; j<nr; j++) {
		R[j] = A[q+j+1];
	}

	i = 0;
	j = 0;
	int k = p;

	while (i<nl && j < nr) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < nl) {
		A[k] = L[i];
		k++;
		i++;
	}

	while (j < nr) {
		A[k] = R[j];
		k++;
		j++;
	}
}

void merge_sort(int A[], int p, int r) {
	if (p >= r) {
		return;
	}

	int q = (p + r) / 2;

	merge_sort(A, p, q);
	merge_sort(A, q+1, r);

	merge(A, p, q, r);
}

void print_array(int A[], int n) {
	int i = 0;
	for(i=1; i<n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main(void) {
	int A [] = {0, 2, 4, 6, 7, 1, 2, 3, 5};
	merge_sort(A, 1, 8);
	print_array(A, 9);

	return 0;
}


