#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n; //����

	cin >> n;

	vector<int> A(n);
	vector<int> B(n);
	vector<int> Copy(n); //B�� �迭�� ������ �迭�� ��迭�Ͽ� ���

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