#include <iostream>

using namespace std;

int r, b, tile;

int main() {
	cin >> r >> b;
	tile = r + b;

	for (int i = 1; i < tile; i++) {
		for (int j = i; j >= 3; j--) {
			int x, y;
			y = (i - 2) * (j - 2);
			x = i * j - y;

			if (x == r && y == b) {
				cout << i << ' ' << j;
				return 0;
			}
		}
		
	}

	return 0;
}
