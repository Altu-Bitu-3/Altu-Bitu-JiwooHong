//참고 자료 : 10/4 라이브코딩 1931번 해설

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;
priority_queue<int, vector<int>, greater<int>> pq;


//필요한 강의실 수를 리턴하는 함수 
int countClass(int n, vector<ci>& classes) {
    pq.push(classes[0].second);

    for (int i = 1; i < n; i++) {
        pq.push(classes[i].second);

        if (pq.top() <= classes[i].first) {
            pq.pop();
        }
    }
    return pq.size();
}


int main() {
    int n;
    cin >> n;

    vector<ci> classes(n, { 0, 0 });

    for (int i = 0; i < n; i++) {
        cin >> classes[i].first >> classes[i].second;
    }

    sort(classes.begin(), classes.end());

    cout << countClass(n, classes);
    return 0;
}
