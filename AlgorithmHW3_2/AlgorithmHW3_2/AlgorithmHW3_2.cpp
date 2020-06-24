// AlgorithmHW3_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define MAX 8
#define N 48

using namespace std;
bool visited[MAX][MAX];

char DRT[5] = { 'U','D','R','L' };
char bWord;
char route[N];
char bRoute[N];
int result = 0;
int row, col;



//벽에 부딪혔을때 
bool option1() {
    if()
}

bool isValid(char W) {
    if (option1()) return true;
    return false;
}

void backtracking(int cnt) {
    if (cnt == N) {
        result += 1;
        return;
    }

    if (route[cnt] == '?') {
        for (int i = 0; i < 5; i++) {
            moving(DRT[i]);
            visited[row][col] = 1;
            backtracking(cnt+1);
        1   visited[][j] = 1;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (route[cnt] == DRT[i]) {

        }
    }

    
}

int main()
{
    int i = 0;
    for (int i = 0;i < N;i++) {
        cin >> route[i];
    }

    return 0;
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
