#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
//입력
	//스위치 개수
	int sw_num, std_num;
	cin >> sw_num; 

	//스위치 상태
	vector<int> sw_state(sw_num+1,0);
	for (int i = 1; i <= sw_num; i++) {
		cin >> sw_state[i];
	}

	//학생 수
	cin >> std_num;

	//학생 성별, 숫자 
	vector<pair<int, int>>std_state(std_num, { 0,0 });
	for (int i = 0; i < std_num; i++) {
		cin >> std_state[i].first >> std_state[i].second;
	}

//비교
	for (int i = 0; i < std_num; i++) {
		if (std_state[i].first == 1) { //남학생
			for (int j = 1; j <= sw_num; j++) {
				if (j % std_state[i].second == 0) sw_state[j] = !sw_state[j]; //배수 -> 스위치 상태 변경
			}
		}

		else { //여학생
			int left = std_state[i].second;
			int right = std_state[i].second;
			while (1 < left && right < sw_num && sw_state[left-1] == sw_state[right+1]) {
				left--;
				right++;
			}
			for (int j = left; j <= right; j++) {
				sw_state[j] = !sw_state[j];
			}
		}
	}

	for (int i = 1; i <= sw_num; i++) {
		cout << sw_state[i] << " ";
		if (i % 20 == 0) {
			cout << "\n";
		}
		
	}

	return 0;
}
