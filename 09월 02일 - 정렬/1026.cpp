#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n; //길이

	cin >> n;

	vector<int> A(n);
	vector<int> B(n);
	vector<int> Copy(n); //B의 배열을 복사한 배열을 재배열하여 사용

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		Copy[i] = B[i];
	}

	sort(A.begin(), A.end());
	sort(Copy.begin(), Copy.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] * Copy[i];
	}

	cout << sum;

	return 0;
}