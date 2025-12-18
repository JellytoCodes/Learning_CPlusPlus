#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

int main()
{
    // unordered의 사용 목적은 해시/버킷/rehash/평균 O(1) vs 최악 O(n), 순회 순서 비결정성.
    unordered_set<int> uset;
    unordered_map<string, int> umap;

    vector<int> v = {1, 1, 3, 7, 5, 9, 2, 6, 2, 4, 8};

    for(auto& element : v)
    {
        uset.insert(element);
    }

    for(auto element : uset)
    {
        cout << element << " ";
    }
    cout << "\n\n";

    // map과 동일 단, 정렬 없음
    umap.insert(make_pair("Banana", 7));
    umap.insert(make_pair("Kiwi", 6));
    umap.insert(make_pair("Apple", 9));
    umap["Cherry"] = 2;

    for(auto& pair : umap)
    {
        cout << pair.first << " : " << pair.second << "\n";
    }
    cout << "\n";

    return 0;
}