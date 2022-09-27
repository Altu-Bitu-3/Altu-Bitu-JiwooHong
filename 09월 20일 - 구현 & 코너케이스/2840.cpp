#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, char> ci; 

/*
    - 배열을 ?로 초기화 해주고, 입력대로 처리한다
    - 문제의 경우, 화살표를 고정시키고 바퀴를 돌리는데,
    - 풀 때에는 바퀴를 고정시키고, 화살표를 이동시키는 방식으로 풀었다. (출력시 방향을 바꿔야함)
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
*/

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int index, int n, vector<char>& wheel) {
    string ans = "";

    for (int i = n; i > 0; i--) { 
        ans += wheel[(i + index) % n]; //화살표가 가리키는 문자부터 시계방향으로 바퀴에 적어놓은 알파벳을 출력
    }

    return ans;
}

string makeWheel(int n, vector<ci>& record) {
    vector<char> wheel(n, '?');           //?로 초기화 -> 어떤 글자인지 결정하지 못하면 ? 출력 
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int index = 0; //화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) { //기록된 바퀴 회전 수 만큼 
        int rot = record[i].first; // 기록된 화살표가 가리키는 글자 바뀐 횟수
        int ch = record[i].second; //회전을 멈추었을 때 가리키던 글자

        index = (index + rot) % n; //화살표 이동

        if (wheel[index] == ch) { //화살표가 가리키는 인덱스에 있는 칸의 글자와 기록된 회전을 멈추었을 때 가리키던 글자가 같을 때
            continue; //계속 탐색
        }

        // 주의사항 체크
        // 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch;
        is_available[ch - 'A'] = true; // 2번 조건을 체크하기 위함
    }

    return arrowStartWheel(index, n, wheel); 
}

int main() {
    //입력
    int n, k;
    cin >> n >> k; //바퀴의 칸 수 N, 바퀴를 돌리는 횟수 K

    vector<ci> record(k, { 0, 0 }); //바퀴 회전 기록
    for (int i = 0; i < k; i++) { //바퀴를 돌리는 횟수 K번 동안 
        cin >> record[i].first >> record[i].second; // 바퀴 회전 시 화살표가 가리키는 글자 바뀐 횟수와 회전을 멈추었을 때 가리키던 글자 입력 
    }

    //출력
    cout << makeWheel(n, record); 
}
