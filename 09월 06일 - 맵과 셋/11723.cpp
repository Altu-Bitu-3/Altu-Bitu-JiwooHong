#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x, M;
	string input;
	set<int> S;

	set<int> all;
	for (int i = 1; i <= 20; i++) {
		all.insert(i);
	}

	cin >> M;

	while (M--) {
		cin >> input;

		if (input == "add") {
			cin >> x;
			S.insert(x);
			continue;
		}

		if (input == "remove") {
			cin >> x;
			S.erase(x);
			continue;
		}

		if (input == "check") {
			cin >> x;
			if (S.find(x) != S.end()) {
				cout << ("1\n");
			}
			else {
				cout << ("0\n");
			}
			continue;
		}

		if (input == "toggle") {
			cin >> x;
			if (S.find(x) != S.end()) {
				S.erase(x);
			}
			else {
				S.insert(x);
			}
			continue;
		}

		if (input == "all") {
			S = all;
			continue;
		}

		if (input == "empty") {
			S.clear();
		}
	}

	return 0;
}
