#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n; //길이

	cin >> n;

	vector<int> A(n);
	vector<int> B(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] * B[i];
	}

	cout << sum;

	return 0;
} 
