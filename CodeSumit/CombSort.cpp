/* Ý tưởng: Tương tự thuật toán nổi bọt
 * So sánh và đổi chỗ 2 phần tử có vị trí cách nhau 1 khoảng gap (gap = n/1.3 và giảm dần) 
 * cho đến khi không còn trạng thái đổi chỗ hoặc gap =1
*/

#include<cstdio>
using namespace std;

void swapFloat(float a[], int i, int j) {
	float temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void combSortFloat(float a[], int n) {
	int gap = n;
	bool swaped = true;

	while (gap != 1 || swaped == true) {
		gap = gap * 10 / 13;
		if (gap < 1) gap = 1;

		swaped = false;
		for (int i = 0; i < n - gap; i++) {
			if (a[i] > a[i + gap]) {
				swapFloat(a, i, i + gap);
				swaped = true;
			}
		}
	}
}

int main() {
	int length;
	scanf("%d", &length);
	float *arr = new float[length];
	for (int i = 0; i < length; i++) {
		scanf("%f", &arr[i]);
	}
	combSortFloat(arr, length);
	for (int i = 0; i < length; i++) {
		printf("%.2f ", arr[i]);
	}
	return 0;
}