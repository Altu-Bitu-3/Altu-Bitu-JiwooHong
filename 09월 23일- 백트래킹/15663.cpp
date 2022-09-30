//라이브코딩 15649번 문제 풀이 참고 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int n, m;
vector<int> num(SIZE);
bool check[SIZE];
int ans[SIZE];


void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int temp = 0;

	for (int i = 0; i < num.size(); i++) {
		if (!check[i]&&temp!=num[i]) {
			temp = num[i];
			ans[cnt] = num[i];
			check[i] = true;
			backtracking(cnt + 1);
			check[i] = false;
		}

	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());
	backtracking(0);

	return 0;
}
