#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int n, m;
	int c = 0;
	string input;
	map<string, bool> s;
	
	cin >> n >> m;

	while (n--) {
		cin >> input;
		s.insert({input,true });
	}

	while (m--) {
		cin >> input;
		if (s.find(input) != s.end()) {
			c++;
		}
	}

	cout << c;

	return 0;
}
