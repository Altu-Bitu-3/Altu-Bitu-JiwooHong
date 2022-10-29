#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	deque<int> d;
	
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}

	reverse(a.begin(), a.end());

	int cardNum = 1;

	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			d.push_back(cardNum);
		}

		else if (a[i] == 2) {
			int tmp = d[d.size() - 1];
			d.pop_back();
			d.push_back(cardNum);
			d.push_back(tmp);
		}

		else if (a[i] == 3) {
			d.push_front(cardNum);
		}
		cardNum++;
	}
	

	while (!d.empty()){
		cout << d[d.size() - 1] << ' ';
		d.pop_back();
	}
	
}
