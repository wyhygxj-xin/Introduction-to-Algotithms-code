#include <stdio.h>

void insertion_sort_increase (int A[], int n)
{
	for (int i=2; i<=n; i++) {
		int key = A[i];
		int j = i - 1;
		while (j>0 && A[j]>key) {
			A[j+1] = A[j];
			j = j - 1;
		}
		A[j+1] = key;
	}
}

void insertion_sort_decrease (int A[], int n)
{
	for (int i=2; i<=n; i++) {
		int key = A[i];
		int j = i - 1;
		while (j>0 && A[j]<key) {
			A[j+1] = A[j];
			j = j - 1;
		}
		A[j+1] = key;
	}
}

void print_array(int A[], int n) 
{
	for(int i=1; i<=n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main(void) 
{
	int A[6] = {5, 3,4,1,2,5};
	insertion_sort_increase(A, 5);
	print_array(A, 5);
	insertion_sort_decrease(A, 5);
	print_array(A, 5);

	return 0;
}


