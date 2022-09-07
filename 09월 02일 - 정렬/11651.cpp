#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coordinate {
	int x, y;
};

bool cmp(const coordinate& a, const coordinate& b) {
	if (a.y != b.y) { //y��ǥ�� �����ϴ� ������
		return a.y < b.y; 
	}
	return a.x < b.x; //y��ǥ�� ������ x��ǥ�� �����ϴ� ������
}


int main() {
	int n; //���� ����
	cin >> n;
	vector<coordinate> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr.begin(), arr.end(), cmp);

	//���
	for (int i = 0; i < n; i++) {
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}
	return 0;
}