#include<iostream>

using namespace std;

int map[9][9] = {
	{2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 0, 0, 0, 0, 2, 0, 0, 2},
	{2, 0, 0, 0, 0, 2, 0, 0, 2},
	{2, 0, 0, 0, 0, 2, 0, 0, 2},
	{2, 0, 0, 0, 0, 2, 0, 0, 2},
	{2, 2, 2, 2, 2, 2, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2}
};


void visit(int x, int y,int cnt);
//char route[50];
int success = 0;
int bw = -1;

char route[50] = "?????????????U??????????????????????????LD????D?";
int main()
{
	cout << route[6] << endl;
	printf("미로 찾기\n");

	visit(1, 1,0);
	cout << success << endl;
}

void visit(int x, int y,int cnt)
{
	cout << "cnt : " << cnt << endl;
	map[x][y] = 1;      // 지나간 위치를 표시
	printf("(%d,%d)\n ", x, y);

	if (x == 4 && y == 1 ) {//카운터는 전체 수 - 1
		if (cnt == 15) {
			// 최종 도착지점
			success += 1;
			cout << "찾음!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
			map[x][y] = 0;
			return;
		}
		else {
			cout << "수 부족 : " << cnt << endl;
			map[x][y] = 0;
			return;
		}
	}
	if (route[cnt] == '?' || route[cnt] == 'R') {
		if (map[x][y + 1] == 0) {
			cout << "R ";
			bw = 1;
			visit(x, y + 1, cnt + 1);
		}
		else if (map[x][y + 1] == 2) {
			if (map[x - 1][y] == 0 && map[x + 1][y] == 0) {
				printf("\ncnt : %d 현재위치(%d,%d)\n", cnt, x, y);
				cout << "\n오른쪽 벽 공간생김\n";
				map[x][y] = 0;
				return;
			}
		}
	}

	if (route[cnt] == '?' || route[cnt] == 'D') {
		if (map[x + 1][y] == 0) {
			cout << "D ";
			bw = 2;
			visit(x + 1, y, cnt + 1);
		}
		else if (map[x + 1][y] == 2) {
			if (map[x][y - 1] == 0 && map[x][y + 1] == 0) {
				printf("(%d,%d) (%d,%d)\n", x, y - 1, x, y + 1);
				printf("\ncnt : %d 현재위치(%d,%d)\n", cnt, x, y);
				cout << "\n아랫쪽 벽 공간\n";
				map[x][y] = 0;
				return;
			}
		}
	}

	if (route[cnt] == '?' || route[cnt] == 'L') {
		if (map[x][y - 1] == 0) {
			cout << "L ";
			bw = 3;
			visit(x, y - 1, cnt + 1);
		}
		else if (map[x][y - 1] == 2) {
			if (map[x + 1][y] == 0 && map[x - 1][y] == 0) {
				printf("\n(%d,%d) (%d,%d)\n", x + 1, y, x - 1, y);
				printf("\ncnt : %d 현재위치(%d,%d)\n", cnt, x, y);
				cout << "\n왼쪽 벽 공간생김\n";
				map[x][y] = 0;
				return;
			}
		}
	}

	if (route[cnt] == '?' || route[cnt] == 'U') {
		if (map[x - 1][y] == 0) {
			cout << "U ";
			bw = 4;
			visit(x - 1, y, cnt + 1);
		}
		else if (map[x - 1][y] == 2) {
			if (map[x][y - 1] == 0 && map[x][y + 1] == 0) {
				printf("\ncnt : %d 현재위치(%d,%d)\n", cnt, x, y);
				cout << "\n위쪽 벽 공간생김\n";
				map[x][y] = 0;
				return;
			}
		}
	}

	map[x][y] = 0; //회귀  
	return;
}

