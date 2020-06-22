// AlgorithmHW3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define MAX 8
#define LEN 50
using namespace std;

char route[LEN];//이동경로를 담을 배열
char DRT[5] = { '?','U','D','R','L' }; //방향을 기록하는 배열
int DRTN[4] = { 0,0,0,0 };
bool visited[MAX][MAX];
int result = 0; //최종출력, 경로 갯수

//범위를 벗어났는지 판단하는 함수
bool OutofRange(int row, int col,int cnt) { 	
	if (row == 6 && col == 0 && cnt < LEN-2) return false;
	
	if ((row == 6 || row == 0) &&(col != 0) && (col != 6) ) {
		if ((!visited[row][col - 1]) && (!visited[row][col + 1])) return false;
	}
	if ((col == 6 || col == 0) && (row != 0) && (row != 6)) {
		if ((!visited[row+1][col]) && (!visited[row-1][col])) return false;
	}

	if (row < 0) return false;
	if (row > 6) return false;
	if (col < 0) return false;
	if (col > 6)return false;
	return true;
}

//d 방향으로의 이동이 가능한지 판단하는 함수
bool isValid(char d,int row,int col,int cnt) {
	switch (d)
	{
	case 'U':
		if (!visited[row - 1][col]) return false;
		if (!OutofRange(row - 1, col, cnt)) return false;
		break;
	case 'D':
		if (!visited[row - 1][col]) return false;
		if (!OutofRange(row + 1, col, cnt)) return false;
		break;
	case 'R':
		if (!visited[row - 1][col]) return false;
		if (!OutofRange(row , col + 1, cnt)) return false;
		break;
	case 'L':
		if (!visited[row - 1][col]) return false;
		if (!OutofRange(row , col - 1, cnt)) return false;
		break;
	}
	return true;
}


void backtracking(int cnt, int row, int col) {
	if (cnt == LEN - 1) {
		result += 1;
		printf("Result : %d!!!!!!!!!!!!!!\n\n\n\n\n\n\n", result);
		return;
	}
	else if (cnt > LEN - 1) return;

		if (route[cnt] != '?') {//경로가 정해져있을때
			if (isValid(route[cnt], row, col,cnt)) {
				//printf("Before cnt %d)row : %2d col : %2d\n", cnt, row, col);
				switch (route[cnt])
				{
				case 'U':
					cout << "U" << endl;
					cout << "row : " << row << " col :" << col << " cnt : " << cnt << endl;
					visited[row - 1][col] = 1;
					DRTN[0] += 1;
					backtracking(cnt + 1, row - 1, col);
					visited[row - 1][col] = 0;
					break;
				case 'D':
					cout << "D" << endl;
					cout << "row : " << row << " col :" << col << " cnt : " << cnt << endl;
					visited[row + 1][col] = 1;
					DRTN[1] += 1;
					backtracking(cnt + 1, row + 1, col);
					visited[row + 1][col] = 0;
					break;
				case 'R':
					cout << "R" << endl;
					cout << "row : " << row << " col :" << col << " cnt : " << cnt << endl;
					visited[row][col + 1] = 1;
					DRTN[2] += 1;
					backtracking(cnt + 1, row, col + 1);
					visited[row][col + 1] = 0;
					break;
				case 'L':
					cout << "L" << endl;
					cout << "row : " << row << " col :" << col << " cnt : " << cnt << endl;
					visited[row][col - 1] = 1;
					DRTN[3] += 1;
					backtracking(cnt + 1, row, col - 1);
					visited[row][col - 1] = 0;
					break;
				}
				return;
			}
			else {
				return;
			}
		}
		else{//가능한 방향
			for (int i = 1; i < 5;i++) {
				if (isValid(DRT[i], row, col,cnt)) {
					switch (DRT[i])
					{
					case 'U':
						cout << "U" << endl;
						cout << "row : " << row << " col :" << col << " cnt : " << cnt << endl;
						visited[row - 1][col] = 1;
						DRTN[0] += 1;
						backtracking(cnt + 1, row - 1, col);
						visited[row - 1][col] = 0;
						break;
					case 'D':
						cout << "D" << endl;
						cout << "row : " << row << " col :" << col << " cnt : " << cnt << endl;
						visited[row + 1][col] = 1;
						DRTN[1] += 1;
						backtracking(cnt + 1, row + 1, col);
						visited[row + 1][col] = 0;
						break;
					case 'R':
						cout << "R" << endl;
						cout << "row : " << row << " col :" << col << " cnt : " << cnt << endl;
						visited[row][col + 1] = 1;
						DRTN[2] += 1;
						backtracking(cnt + 1, row, col + 1);
						visited[row][col + 1] = 0;
						break;
					case 'L':
						cout << "L" << endl;
						cout << "row : " << row << " col :" << col << " cnt : " << cnt << endl;
						visited[row][col - 1] = 1;
						DRTN[3] += 1;
						backtracking(cnt + 1, row, col - 1);
						visited[row][col - 1] = 0;
						break;
					}
				}
			}
			
				
		}
	
	return;
}


int main()
{
	//문자열 입력 받기
	for (int i = 0;i < LEN - 2;i++) {
		cin >> route[i];
	}
	if (route[0] == 'U' || route[0] == 'L') {
		cout << 0;
		return 0;
	}
	if (route[47] == 'U' || route[47] == 'R') {
		cout << 0;
		return 0;
	}
	visited[0][0] = 1;
	backtracking(0, 0, 0);
	cout << endl<<"끝"<<endl<< result;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
