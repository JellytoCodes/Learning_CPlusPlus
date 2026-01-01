#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void STLCount(vector<int>& v);
void STLSort(vector<int>& v);
void STLCompareSort(vector<int>& v);
void STLNextPermutation(vector<int>& v);
void STLUnique(vector<int>& v);
void STLBinarySearch(vector<int>& v, int search);
void STLMinElement(vector<int>& v);
void STLMaxElement(vector<int>& v);

int main()
{
    vector<int> v = {1, 4, 3, 4, 5, 8, 4, 5, 2, 6, 7, 9};

    cout << "count \n";
    STLCount(v);
    cout << "\n";

    cout << "sort \n";
    STLSort(v);
    cout << "\n";

    cout << "compare sort \n";
    vector<int> v2 = {1, 4, 3, 4, 5, 8, 4, 5, 2, 6, 7, 9};
    STLCompareSort(v2);
    cout << "\n";

    cout << "unique \n";
    STLUnique(v2);
    cout << "\n";

    cout << "min/max element \n";
    STLMinElement(v2);
    STLMaxElement(v2);
    cout << "\n";

    cout << "next permutation \n";
    vector<int> v3 = {1, 2, 3};
    STLNextPermutation(v3);
    cout << "\n";

    cout << "binary search \n";
    STLBinarySearch(v3, 3);
    STLBinarySearch(v3, 7);

    return 0;
}

void STLCount(vector<int>& v)
{
    // 지정된 컨테이너 범위 내 특정 값의 개수
    int ret = count(v.begin(), v.end(), 4);
    cout << ret << endl;
}

void STLSort(vector<int>& v)
{
    // 오름차순 정렬
    sort(v.begin(), v.end());
    for(auto element : v)
    {
        cout << element << " ";
    }
    cout << "\n";

    // 내림차순 정렬
    sort(v.rbegin(), v.rend());
    for(auto element : v)
    {
        cout << element << " ";
    }
    cout << "\n";
}

void STLCompareSort(vector<int>& v)
{
    // 함수를 통한 정렬 방식 결정
    sort(v.begin(), v.end(), greater<int>());
    for(auto element : v)
    {
        cout << element << " ";
    }
    cout << "\n";
}

void STLNextPermutation(vector<int>& v)
{
    // 가능한 모든 순열을 생성 (O(N*N!))
    do
    {
        for(int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    } while(next_permutation(v.begin(), v.end()));
}

void STLUnique(vector<int>& v)
{
    // 중복되는 원소들을 뒤로 밀어내고 새로운 범위의 끝 반복자를 반환(O(N))
    auto newEnd = unique(v.begin(), v.end());

    for(auto it = v.begin() ; it != newEnd ; ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

void STLBinarySearch(vector<int>& v, int search)
{
    // 원소 검색 결과를 bool로 반환
    cout << binary_search(v.begin(), v.end(), search) << "\n";
}

void STLMinElement(vector<int>& v)
{
    auto minIt = min_element(v.begin(), v.end());

    cout << *minIt << "\n";
}

void STLMaxElement(vector<int>& v)
{
    auto maxIt = max_element(v.begin(), v.end());

    cout << *maxIt << "\n";
}