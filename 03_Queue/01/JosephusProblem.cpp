#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k) 
{    
    queue<int> josephus;
    for(int i = 1 ; i <= n ; i++)
        josephus.push(i);

    while(josephus.size() > 1)
    {
        for(int i = 0 ; i < k-1 ; i++)
        {
            josephus.push(josephus.front());
            josephus.pop();
        }
        josephus.pop();
    }
    return josephus.front();
}

int main()
{
    cout << solution(5, 2);

    return 0;
}