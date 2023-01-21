//참고 : 우선순위 큐 강의자료, 라이브코딩 11279 코드

#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	priority_queue<int> presentNum;
	while (n--) {
		int c;
		cin >> c;
		presentNum.push(c);
	}

	bool isPresent = true;

	while (m--) {
		int w;
		cin >> w;

		if (presentNum.top() >= w) {
			presentNum.push(presentNum.top() - w);
			presentNum.pop();
		}
		else {
			isPresent = false;
		}
	}

	if (isPresent == false) {
		cout << 0;
	}
	else {
		cout << 1;
	}

	return 0;
}
