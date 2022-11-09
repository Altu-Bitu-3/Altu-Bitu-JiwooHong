#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n, m;
vector<long long>t;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long T;
		cin >> T;
		t.push_back(T);
	}
	
	sort(t.begin(), t.end());

	long long low = 1;
	long long high = t.back() * m;
	long long short_time = 0;

	while (low <= high) {
		long long cnt = 0;
		long long mid = (high + low) / 2;

		for (int i = 0; i < n; i++) {
			cnt += mid / t[i];
			if (cnt > m) break;
		}

		if (cnt >= m) {
			if (short_time > mid || short_time == 0) short_time = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	
	cout << short_time;

	return 0;
}
