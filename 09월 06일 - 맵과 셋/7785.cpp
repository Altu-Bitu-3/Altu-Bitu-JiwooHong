#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int n;
	string name, in;
	set<string>s;

	cin >> n;
	while (n--) {
		cin >> name >> in;
		if (in == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}

	set<int>::iterator iter;
	for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}
