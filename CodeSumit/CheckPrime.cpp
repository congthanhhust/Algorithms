#include <iostream>
using namespace std;
#define max 100

bool isPrime(int arr[], int number) {
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) return false;
	}
	return true;
}

bool isPrime2(int arr[], int number) {
	if (number == 2 || number == 3) return true;
	if (number % 2 == 0 || number % 3 == 0) return false;
	for (int i = 5; i * i <= number; i += 6) {
		if (number % i == 0 || number % (i + 2) == 0) return false;
	}
	return true;
}

void printAllPrimes(int number) {
	bool *marked = new bool[number];
	for (int i = 0; i < number; i++) {
		marked[i] = false;
	}
	for (int i = 2; i < number; i++) {
		if (!marked[i]) {
			cout << i << " ";
			for (int j = i; j < number; j += i) {
				marked[j] = true;
			}
		}
	}
}

int main() {
	printAllPrimes(10000);
}
