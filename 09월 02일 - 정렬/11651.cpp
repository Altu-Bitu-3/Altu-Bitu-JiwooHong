#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coordinate {
	int x, y;
};

bool cmp(const coordinate& a, const coordinate& b) {
	if (a.y != b.y) { //y좌표가 증가하는 순으로
		return a.y < b.y; 
	}
	return a.x < b.x; //y좌표가 같으면 x좌표가 증가하는 순서로
}


int main() {
	int n; //점의 개수
	cin >> n;
	vector<coordinate> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr.begin(), arr.end(), cmp);

	//출력
	for (int i = 0; i < n; i++) {
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}
	return 0;
}