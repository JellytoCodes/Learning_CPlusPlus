#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> v)
{
    sort(v.begin(), v.end(), less<int>());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;    
}

int main()
{
    vector<int> v = solution({4, 2, 2, 1, 3, 4});

    for(auto element : v)
    {
        cout << element << " ";
    }
    cout << "\n";
}
