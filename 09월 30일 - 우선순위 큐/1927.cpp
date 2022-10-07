#include<iostream>
#include<queue>

using namespace std;

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    priority_queue<int, vector<int>, greater<int>> pq; //최소 힙 구현(오름차순)

    //입력
    cin >> n; //연산의 개수 입력
    while (n--) {
        cin >> x; //정수 x 입력

        if (x) { //x가 자연수인 경우
            pq.push(x); //배열에 x 추가
            continue;
        }

        //x가 0인 경우
        if (!pq.empty()) { //배열이 비어있지 않으면
            cout << pq.top() << '\n'; //배열에서 가장 작은 값을 출력
            pq.pop(); //그 값을 배열에서 제거
        }
        else { //배열이 비어있으면 0 출력
            cout << 0 << '\n';
        }
    }
    return 0;

}
