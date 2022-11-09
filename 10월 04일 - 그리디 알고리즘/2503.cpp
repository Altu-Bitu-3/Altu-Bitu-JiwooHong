#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool can[1000];

int main() {
	int n;
	cin >> n;

	int num, strk, ball;
	string tmp, number, compare;
	memset(can, true, sizeof(can));
	
	for (int i = 123; i <= 999; i++) {
		tmp = to_string(i);

		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) {
			can[i] = false;
			continue;
		}

		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) {
			can[i] = false;
			continue;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> num >> strk >> ball;
		
		for (int j = 123; j <= 999; j++) {
			int strk_cnt = 0;
			int ball_cnt = 0;
			number = to_string(num);
			compare = to_string(j);

			if (can[j]) {
				number = to_string(num);
				compare = to_string(j);

				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						if (a == b && number[a] == compare[b]) strk_cnt++;
						if (a != b && number[a] == compare[b]) ball_cnt++;
					}
				}
			}

			if (strk != strk_cnt || ball != ball_cnt) {
				can[j] = false;
			}

		}

	}

	int ans = 0;
	for (int i = 123; i <= 999; i++) {
		if (can[i] == true) ans++;
	}

	cout << ans;

	return 0;
}
