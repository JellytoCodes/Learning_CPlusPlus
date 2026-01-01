#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mapping(vector<int> &hash, const vector<int> &arr, int target)
{
    for(int i = 0 ; i < arr.size() ; i++)
    {
        if(arr[i] > target) continue;
        hash[arr[i]] = 1;
    }
}

bool solution(vector<int> arr, int target)
{
    vector<int> hash(target + 1, 0);
    mapping(hash, arr, target);

    for(int i = 0 ; i < arr.size() ; i++)
    {
        int num = target - arr[i];

        if(arr[i] == num) continue;
        if(num < 0) continue;
        if(hash[num]) return true;
    }
    return false;
}

int main()
{
    cout << solution({1,2,3,4,8}, 6) << "\n";
    cout << solution({2,3,5,9}, 10) << "\n";

    return 0;
}