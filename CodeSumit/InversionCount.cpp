/* Ý tưởng: Dựa trên thuật toán trộn. Trong quá trình trộn sẽ đếm được số lượng các cặp bị đảo ngược.
*/

#include<iostream>
using namespace std;
void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

long long int Merge(int array[], int first, int middle, int last);
long long int mergeSort(int array[], int first, int last);

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
		cout << mergeSort(arr, 0, length - 1) << endl;
	}
	return 0;
}

long long int Merge(int array[], int first, int middle, int last) {
	long long int count = 0;
	int size = last - first + 1;
	int *temp = new int[size];
	int first1, last1, first2, last2;
	int index = 0;

	first1 = first;
	last1 = middle;
	first2 = middle + 1;
	last2 = last;

	while ((first1 <= last1) && (first2 <= last2)) {
		if (array[first1] <= array[first2]) {
			temp[index] = array[first1];
			index++;
			first1++;
		}
		else {
			temp[index] = array[first2];
			count += (middle + 1 - first1);
			index++;
			first2++;
		}
	}

	if (first2 > last2) {
		while (first1 <= last1) {
			temp[index] = array[first1];
			index++;
			first1++;
		}
	}

	if (first1 > last1) {
		while (first2 <= last2) {
			temp[index] = array[first2];
			index++;
			first2++;
		}
	}
	int i = 0;
	for (index = first; index <= last; index++) {
		array[index] = temp[i];
		i++;
	}
	delete[]temp;
	return count;
}

long long int mergeSort(int array[], int first, int last) {
	//Dua tren mergeSort
	long long int count = 0;
	if (first < last) {
		int middle = int((first + last) / 2);
		count = mergeSort(array, first, middle);
		count += mergeSort(array, middle + 1, last);
		count += Merge(array, first, middle, last);
	}
	return count;
}