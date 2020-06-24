#include<iostream>

using namespace std;


bool map[9][9] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1}
};


void visit(int x, int y, int cnt, int before);
int success = 0;


char route[50];
int main()
{
	for (int i = 0; i < 48; i++) {
		cin >> route[i];
	}
	visit(1, 1, 0, 0);
	cout << success << endl;
}

void visit(int x, int y, int cnt, int before)
{
	map[x][y] = 1;      // 지나간 위치를 표시

	if (x == 7 && y == 1) {//카운터는 전체 수 - 1
		if (cnt == 48) {
			// 최종 도착지점
			success += 1;
			map[x][y] = 0;
			return;
		}
		else {
			map[x][y] = 0;
			return;
		}
	}
	if (route[cnt] == '?' || route[cnt] == 'R') {
		if (map[x][y + 1] == 0) {
			visit(x, y + 1, cnt + 1, 1);
		}
		else if (map[x][y + 1] == 1 && before != 3) {
			if (map[x - 1][y] == 0 && map[x + 1][y] == 0) {
				map[x][y] = 0;
				return;
			}
		}
	}

	if (route[cnt] == '?' || route[cnt] == 'D') {
		if (map[x + 1][y] == 0) {
			visit(x + 1, y, cnt + 1, 2);
		}
		else if (map[x + 1][y] == 1 && before != 4) {
			if (map[x][y - 1] == 0 && map[x][y + 1] == 0) {
				map[x][y] = 0;
				return;
			}
		}
	}

	if (route[cnt] == '?' || route[cnt] == 'L') {
		if (map[x][y - 1] == 0) {
			visit(x, y - 1, cnt + 1, 3);
		}
		else if (map[x][y - 1] == 1 && before != 1) {
			if (map[x + 1][y] == 0 && map[x - 1][y] == 0) {
				map[x][y] = 0;
				return;
			}
		}
	}

	if (route[cnt] == '?' || route[cnt] == 'U') {
		if (map[x - 1][y] == 0) {
			visit(x - 1, y, cnt + 1, 4);
		}
		else if (map[x - 1][y] == 1 && before != 2) {
			if (map[x][y - 1] == 0 && map[x][y + 1] == 0) {
				map[x][y] = 0;
				return;
			}
		}
	}

	map[x][y] = 0; //회귀  
	return;
}

