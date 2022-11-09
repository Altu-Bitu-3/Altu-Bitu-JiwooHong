#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string str;
	stack <char> a;
	stack <char> b;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '<') {
				if (!b.empty()) {
					a.push(b.top());
					b.pop();
				}
			}
			else if (str[j] == '>') {
				if (!a.empty()) {
					b.push(a.top());
					a.pop();
				}
			}
			else if (str[j] == '-') {
				if (!b.empty()) {
					b.pop();
				}
			}
			else {
				b.push(str[j]);
			}
		}

		while (!a.empty()) {
			b.push(a.top());
			a.pop();
		}

		string temp;
		while (!b.empty()) {
			temp += b.top();
			b.pop();
		}

		reverse(temp.begin(), temp.end());
		cout << temp << "\n";
	}

	return 0;
}
