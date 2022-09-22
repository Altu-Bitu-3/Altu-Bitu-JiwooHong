#include<iostream>
#include<set>

using namespace std;

bool isCycle(set<string>& s, string str) {
	int cnt = str.length(); 

	while (cnt--) {
		// 같은 단어가 있는 경우
		if (s.find(str) != s.end()) {  
			return true; //true 반환
		}

		// 시계 방향대로, 앞 글자를 떼어서 뒤에 붙여줌.
		str = str + str[0]; //앞 글자 떼어서 뒤에 붙여줌
		str.erase(0, 1); //앞 글자는 삭제
	}
	return false; //같은 단어가 없다면 false 반환 
}

int main() {
	int n; //단어의 개수 N
	string str;
	set<string> word; // 단어 저장

	// 입력
	cin >> n; //단어의 개수 입력 
	while (n--) { //단어의 개수만큼 반복 
		cin >> str; //단어 입력 

		// 같은 단어 없으면 추가
		if (!isCycle(word, str)) { //word에 str에 입력된 단어가 없어 false가 반환되었을 경우 
			word.insert(str); //word에 입력된 단어를 추가, 있으면 추가하지 않음 
		}
	}

	// 출력
	cout << word.size(); //서로 다른 단어들만 word에 들어감 -> word의 사이즈 = 서로 다른 단어의 개수
}
