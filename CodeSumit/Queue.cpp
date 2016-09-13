/* Ý tưởng: Sử dụng thuật toán combsort để sắp xếp mảng tăng dần
 * Lần lượt xét từ phần tử nhỏ nhất trong mảng đã xếp, kiểm tra xem phần tử đó đứng sau bao nhiêu người cao hơn đằng trước
 * để tìm đúng vị trí cho phần tử đó trong mảng mới.
*/

#include<iostream>
using namespace std;

struct people {
	int height;
	int index;
};

void swap(people a[], int i, int j);
void combSort(people a[], int n);

int main() {
	int length;
	int testcase;
	cin >> testcase;

	while (testcase--) {
		cin >> length;	//Number of array
						//Init value
		people *arr = new people[length];
		int *finalStand = new int[length];
		for (int i = 0; i < length; i++) finalStand[i] = 0;
		for (int i = 0; i < length; i++) cin >> arr[i].height;
		for (int i = 0; i < length; i++) cin >> arr[i].index;

		//Sort array of struct
		combSort(arr, length);

		for (int i = 0; i < length; i++) {
			int index = arr[i].index;
			for (int j = 0; j < length; j++) {
				if (finalStand[j] == 0 && index == 0) {
					finalStand[j] = arr[i].height;
					break;
				}
				if (finalStand[j] == 0) index--;
			}
		}

		for (int i = 0; i < length; i++) {
			cout << finalStand[i] << " ";
		}
	}

	return 0;
}

//Đổi chỗ
void swap(people a[], int i, int j) {
	people temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

//Sắp xếp
void combSort(people a[], int n) {
	int gap = n;
	bool swaped = true;

	while (gap != 1 || swaped == true) {
		gap = gap * 10 / 13;
		if (gap < 1) gap = 1;
		swaped = false;

		for (int i = 0; i < n - gap; i++) {
			if (a[i].height > a[i + gap].height) {
				swap(a, i, i + gap);
				swaped = true;
			}
		}
	}
}