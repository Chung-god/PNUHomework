#include<iostream>

using namespace std;

int map[9][9] = {
	{2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 0, 0, 0, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2}
};

void visit(int x, int y);

int success;
int start_x, start_y;
int end_x, end_y;


int main()
{
	start_x = 1;
	start_y = 1; // 시작지점
	end_x = 7;
	end_y = 1;  // 최종도착지점

	success = 0;

	printf("미로 찾기\n");

	visit(1, 1);
}

void visit(int x, int y)
{
	map[x][y] = 1;      // 지나간 위치를 표시
	printf("(%d,%d) ", x, y);
	printf("Find End\n");

	if (x == end_x && y == end_y)   // 최종 도착지점
		success += 1;

	if (success == 0 && map[x][y + 1] == 0)
		visit(x, y + 1);
	if (success == 0 && map[x + 1][y] == 0)
		visit(x + 1, y);
	if (success == 0 && map[x][y - 1] == 0)
		visit(x, y - 1);
	if (success == 0 && map[x - 1][y] == 0)
		visit(x - 1, y);

	map[x][y] = 0; //회귀  
}

