#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> v)
{
    set<int> s;
    for(int i = 0 ; i < v.size() ; ++i)
    {
        for(int j = i + 1 ; j < v.size() ; ++j)
        {
            s.insert(v[i] + v[j]);
        }
    }

    vector<int> returnVec(s.begin(), s.end());
    return returnVec;
}

int main()
{
    vector<int> vec = solution({2, 1, 3, 4, 1});
    vector<int> vec2 = solution({5, 0, 2, 7});

    for(auto element : vec) cout << element << " ";
    cout << "\n";

    for(auto element : vec2) cout << element << " ";
    cout << "\n";
}