#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string A, B, result;
	string C;

	cin >> A >> B;

	if (A.size() > B.size()) {
		for (int i = 0; i < A.size() - B.size(); i++) {
			C += '0';
		}
		B = C + B;
	}
	else {
		for (int i = 0; i < B.size() - A.size(); i++) {
			C += '0';
		}
		A = C + A;
	}

	int plus = 0;
	int remain = 0;

	while (A.size() != 0 || B.size() != 0) {
		int A_last = A.back() - '0';
		int B_last = B.back() - '0';

		remain = (A_last + B_last + plus) % 10;
		plus = (A_last + B_last + plus) / 10;
		result = result + (char)(remain + '0');
		A.pop_back();
		B.pop_back();
	}

	if (plus) {
		result = result + (char)(plus + '0');
	}

	reverse(result.begin(), result.end());

	cout << result << endl;

	return 0;
}
