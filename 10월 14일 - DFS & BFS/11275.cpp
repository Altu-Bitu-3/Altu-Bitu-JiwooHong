#include <iostream>
#include <vector>

using namespace std;

int n;
int visit[1000001];
vector<int>tree[1000001];


void dfs(int node) {
	
	for (int i = 0; i < tree[node].size(); i++) {
		int next_node = tree[node][i];
		if (visit[next_node] == 0) {
			visit[next_node] = node;
			dfs(next_node);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int n_s, n_f;
		cin >> n_s >> n_f;
		tree[n_s].push_back(n_f);
		tree[n_f].push_back(n_s);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << visit[i] << "\n";
	}
	
	return 0;
}
