#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> lhs, vector<vector<int>> rhs)
{
    vector<vector<int>> answer;

    answer.assign(lhs.size(), vector<int>(rhs[1].size(), 0));

    for(int m = 0 ; m < lhs.size() ; ++m)
    {
        for(int n = 0 ; n < rhs[0].size(); ++n)
        {
            for(int k = 0 ; k < rhs.size() ; ++k)
            {
                answer[m][n] += lhs[m][k] * rhs[k][n];
            }
        }
    }

    return answer;
}

int main()
{  
    vector<vector<int>> v1 = 
    {
        {1, 4},
        {3, 2},
        {4, 1}
    };
    vector<vector<int>> v2 = 
    {
        {3, 3},
        {3, 3}
    };

    vector<vector<int>> answer = solution(v1, v2);

    for(auto It = answer.begin() ; It != answer.end() ; ++It)
    {
        for(auto& element : *It)
        {
            cout << element << " ";
        }
        cout << "\n";
    }

    return 0;
}