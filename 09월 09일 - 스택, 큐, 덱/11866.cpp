#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	queue<int> q;

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		q.push(i+1);
	}

	cout << "<";
	while (n-- != 0) {
		for (int i = 0; i < k; i++) {
			if (i == k - 1) {
				cout << q.front();
				if (q.size()!=1) {
					cout << ", ";
				}
				else{
					cout << ">";
				}
			}
			else {
				q.push(q.front());
			}
			q.pop();
		}
	}

	return 0;
}
