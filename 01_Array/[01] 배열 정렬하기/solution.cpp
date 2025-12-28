#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> solution(vector<int> v)
{
    sort(v.begin(), v.end());
    return v;
}

void bubbleSort(vector<int>& v)
{
    for(size_t i = 0 ; i < v.size() - 1 ; ++i)
    {
        for(size_t j = 0 ; j < v.size() - i - 1 ; ++j)
        {
            if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
}

int main()
{
    vector<int> v(30000);
    for(int i = 0 ; i < 30000 ; ++i) v[i] = i + 1;

    // 버블 정렬 = O(N2)
    vector<int> vecForBubbleSort = v;
    clock_t startBubbleSort = clock();
    bubbleSort(vecForBubbleSort);
    clock_t endBubbleSort = clock();
    double timeBubbleSort = double(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC;

    // sort() 함수 = O(NlogN)
    clock_t startStdSort = clock();
    vector<int> vecForStdSort = solution(v);
    clock_t endStdSort = clock();
    double timeStdSort = double(endStdSort - startStdSort) / CLOCKS_PER_SEC;
    
    // 알고리즘 시간 복잡도에 따른 정렬 시간의 차이가 얼마나 나는지 알 수 있음
    cout << "Bubble sort time : " << timeBubbleSort << "\n";
    cout << "STL sort time : " << timeStdSort << "\n";
}