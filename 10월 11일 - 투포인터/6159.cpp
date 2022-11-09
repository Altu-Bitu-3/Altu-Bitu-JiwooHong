#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	
	vector<int>size(n);
	for (int i = 0; i < n; i++) {
		cin >> size[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (size[i] + size[j] <= s) cnt++;
		}		
	}

	cout << cnt;

	return 0;
}
