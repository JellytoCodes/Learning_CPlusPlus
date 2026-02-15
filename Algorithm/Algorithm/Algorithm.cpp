#include <iostream>
#include <thread>
#include <Windows.h>
#include <vector>
using namespace std;

// TRIANGLE_PATH
// - (0, 0)부터 시작해서 아래 or 아래우측으로 이동 가능
// - 만나는 숫자를 모두 더함
// - 더한 숫자가 최대가 되는 경로의 합

int N;
vector<vector<int>> board;
vector<vector<int>> cache;
vector<vector<int>> nextX;

int Path(int x, int y)
{
	// 기저 사항
	if (x == N)
		return 0;

	// 캐시 확인
	int& ret = cache[x][y];
	if (ret != -1)
		return ret;

	// 경로 기록
	{
		int nextBottom = Path(x + 1, y);
		int nextBottomRight = Path(x + 1, y + 1);
		if (nextBottom > nextBottomRight)
			nextX[x][y] = x;
		else
			nextX[x][y] = x + 1;
	}

	// 적용
	return ret = board[x][y] + max(Path(x + 1, y), Path(x + 1, y + 1));
}

int main()
{
	board = vector<vector<int>>
	{
		{6},
		{1, 2},
		{3, 7, 4},
		{9, 4, 1, 7},
		{2, 7, 5, 9, 4}
	};

	N = board.size();
	cache = vector<vector<int>>(N, vector<int>(N, -1));
	nextX = vector<vector<int>>(N, vector<int>(N));

	int ret = Path(0, 0);
	cout << ret << endl;

	// 경로 만들기
	int x = 0;
	int y = 0;

	while (x < N)
	{
		cout << board[x][y] << " -> ";

		y = nextX[x][y];
		x++;
	}
}