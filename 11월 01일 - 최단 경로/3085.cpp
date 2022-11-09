#include<iostream>
#include<algorithm>

using namespace std;

char candy[51][51];
int n, cnt, max_candy;

void check() {
	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 0; j < n; j++) {
			if (candy[i][j] == candy[i][j + 1]) {
				cnt++;
			}
			else {
				max_candy = max(max_candy, cnt);
				cnt = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 0; j < n; j++) {
			if (candy[j][i] == candy[j + 1][i]) {
				cnt++;
			}
			else {
				max_candy = max(max_candy, cnt);
				cnt = 1;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> candy[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			swap(candy[i][j], candy[i][j + 1]);
			check();
			swap(candy[i][j], candy[i][j + 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			swap(candy[j][i], candy[j + 1][i]);
			check();
			swap(candy[j][i], candy[j + 1][i]);
		}
	}
	cout << max_candy;
	return 0;
}
