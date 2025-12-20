#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int cnt = 0;

    vector<stack<int>> lanes(board[0].size());

    for(int i = board.size() -1 ; i >= 0 ; --i)
    {
        for(int j = 0 ; j < board[0].size() ; ++j)
        {
            if(board[i][j]) lanes[j].push(board[i][j]);
        }
    }

    stack<int> bucket;
    
    for(int m : moves)
    {
        if(lanes[m-1].size())
        {
            int doll = lanes[m-1].top();
            lanes[m - 1].pop();

            if(bucket.size() && bucket.top() == doll)
            {
                bucket.pop();
                cnt += 2;
            }
            else
            {
                bucket.push(doll);
            }
        }
    }

    return cnt;
}

int main()
{
    int result = solution(
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 3},
            {0, 2, 5, 0, 1},
            {4, 2, 4, 4, 2},
            {3, 5, 1, 3, 1}
        },
        {1, 5, 3, 5, 1, 2, 1, 4}
    );

    cout << result << "\n";
    return 0;
}