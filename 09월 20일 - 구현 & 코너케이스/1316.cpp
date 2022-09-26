#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string str;
	int cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int alpha[26] = { 0, };
		int temp = 0;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			alpha[(int)str[j] - 97]++;

			if (alpha[(int)str[j] - 97] > 1 && str[j] != str[j - 1]) {
				temp = 1;
				break;
			}
		}
		if (temp == 0) {
			cnt++;
		}
			
	}

	cout << cnt;

	return 0;
}
