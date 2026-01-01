#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // int v[]와 동일
    vector<int> v;

    int rows = 3;
    int cols = 4;

    int val = 9;
    // int v2[][]와 동일
    vector<vector<int>> v2(rows, vector<int>(cols, val));

    vector<vector<int>> v3 = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "v2 : ";
    // 반복자로 v2 내 원소(vector<int>)를 순회
    for(auto it = v2.begin() ; it != v2.end() ; ++it)
    {
        // 반복자가 소유한 원소(int)를 출력하고 v의 맨 뒤에 저장 (O(1)으로 빠름)
        for(auto n : *it)
        {
            v.push_back(n);
            cout << n << " ";
        }
    }
    cout << "\n";

    cout << "v3 : ";
    for(auto it = v3.begin() ; it != v3.end() ; ++it)
    {
        for(auto n : *it)
        {
            // v의 n-1번째 원소에 n을 저장 (O(N)으로 느림)
            if((n % 2) == 0) v.insert((v.begin() + n)-1, n);
            cout << n << " ";
        }
    }
    cout << "\n";

    cout << "v1 : ";
    for(int i = 0 ; i < v.size() ;)
    {
        if((v[i] % 2) == 1)
        {
            v.erase(v.begin() + i);
            continue;
        }
        else
        {
            cout << v[i] << " ";
            i++;
        }
    }
    cout << "\n";

    return 0;
}