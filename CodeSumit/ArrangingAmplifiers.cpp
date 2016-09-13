#include<iostream>
using namespace std;

void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void combSort(int a[], int n) {
	int gap = n;
	bool swaped = true;

	while (gap != 1 || swaped == true) {
		gap = gap * 10 / 13;
		if (gap < 1) gap = 1;
		swaped = false;

		for (int i = 0; i < n - gap; i++) {
			if (a[i] < a[i + gap]) {
				swap(a, i, i + gap);
				swaped = true;
			}
		}
	}
}

void Arranging(int a[], int length);

int main() {
	int testcase;
	int length;
	cin >> testcase;
	while (testcase--) {
		cin >> length;
		int *arr = new int[length];
		for (int i = 0; i < length; i++) {
			cin >> arr[i];
		}
		Arranging(arr, length);
		cout << endl;
	}
	return 0;
}

void Arranging(int a[], int length) {
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int *b = new int[length];
	for (int i = 0; i < length; i++) {
		if (a[i] == 1) {
			count1++;
			continue;
		}
		if (a[i] == 2) {
			count2++;
			continue;
		}
		if (a[i] == 3) {
			count3++;
			continue;
		}
		b[count4++] = a[i];
	}

	for (int i = 0; i < count1; i++) {
		cout << 1 << " ";
	}
	int sz = count4;
	if (sz > 0) {
		combSort(b, sz);
		for (int i = 0; i < sz; i++) {
			cout << b[i] << " ";
		}
		for (int i = 0; i < count3; i++) cout << 3 << " ";
		for (int i = 0; i < count2; i++) cout << 2 << " ";
	}
	else {
		for (int i = 0; i < count2; i++) cout << 2 << " ";
		for (int i = 0; i < count3; i++) cout << 3 << " ";
	}
	delete[]b;
}

