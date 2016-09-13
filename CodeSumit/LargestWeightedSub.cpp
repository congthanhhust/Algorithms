#include<iostream>
#include<cstdio>
using namespace std;

long LargestWeight(int a[], int length) {
	int* s = new int[length];
	long max = a[0];
	s[0] = a[0];
	for (int i = 1; i < length; i++) {
		if (s[i - 1] > 0) s[i] = s[i - 1] + a[i];
		else s[i] = a[i];
		if (s[i] > max) max = s[i];
	}
	delete[]s;
	return max;
}

int main() {
	//Init
	int length;
	scanf("%d", &length);

	int *A = new int[length];
	for (int i = 0; i < length; i++) {
		scanf("%d", &A[i]);
	}
	printf("%d \n", LargestWeight(A, length));
	delete[] A;
	return 0;
}