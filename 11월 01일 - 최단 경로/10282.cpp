#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 2e9;

vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
	vector<int> dist(v + 1, INF);
	priority_queue<ci, vector<ci>, greater<>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().first;
		int com = pq.top().second;
		pq.pop();

		if (cur > dist[com]) {
			continue;
		}

		for (int i = 0; i < graph[com].size(); i++) {
			int next_com = graph[com][i].first;
			int next_cur = cur + graph[com][i].second;

			if (next_cur < dist[next_com]) {
				dist[next_com] = next_cur;
				pq.push({ next_cur,next_com });
			}
		}
	}

	return dist;
}

int main() {
	int t, n, d, c, a, b, s;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> n >> d >> c;
		vector<vector<ci>> graph(n + 1, vector<ci>(0));

		for (int j = 0; j < d; j++) {
			cin >> a >> b >> s;
			graph[b].push_back({ a,s });
		}

		vector<int>dist = dijkstra(c, n, graph);

		int cnt = 0;
		int time = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INF) {
				continue;
			}
			else {
				cnt++;
				time = max(time, dist[i]);
			}
		}
		cout << cnt << " " << time << "\n";
	}
	return 0;
}
