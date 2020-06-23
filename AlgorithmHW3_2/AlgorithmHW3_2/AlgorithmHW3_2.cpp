#include<iostream>

using namespace std;

int map[9][9] = {
	{2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 0, 0, 0, 2, 0, 0, 0, 2},
	{2, 0, 0, 0, 2, 0, 0, 0, 2},
	{2, 0, 0, 0, 2, 2, 2, 2, 2},
	{2, 2, 2, 2, 2, 0, 0, 2, 2},
	{2, 0, 0, 0, 2, 2, 0, 2, 2},
	{2, 0, 0, 0, 2, 0, 0, 0, 2},
	{2, 0, 0, 0, 2, 0, 0, 0, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2}
};


void visit(int x, int y,int cnt);

int success = 0;


int main()
{
	printf("미로 찾기\n");

	visit(1, 1,0);
	cout << success << endl;
}

void visit(int x, int y,int cnt)
{
	map[x][y] = 2;      // 지나간 위치를 표시
	printf("(%d,%d) ", x, y);

	if (x == 3 && y == 1 && cnt == 8 ) {//카운터는 전체 수 - 1
		// 최종 도착지점
		success += 1;
		cout << "찾음!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
		map[x][y] = 0;
		return;
	}
	if (map[x][y + 1] == 0)//R
		visit(x, y + 1,cnt+1);
	else {
		if (map[x - 1][y + 1] == 0 && map[x + 1][y + 1] == 0) return;
	}
	if (map[x + 1][y] == 0)//D
		visit(x + 1, y,cnt+1);
	else {
		if (map[x + 1][y - 1] == 0 && map[x + 1][y + 1] == 0) return;
	}
	if (map[x][y - 1] == 0)
		visit(x, y - 1,cnt+1);
	else {
		if (map[x + 1][y - 1] == 0 && map[x - 1][y - 1] == 0) return;
	}
	if (map[x - 1][y] == 0)
		visit(x - 1, y,cnt+1);
	else {
		if (map[x - 1][y - 1] == 0 && map[x - 1][y + 1] == 0) return;
	}

	map[x][y] = 0; //회귀  
}

