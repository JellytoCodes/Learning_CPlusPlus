#include <iostream>      // cout
#include <vector>        // vector
#include <map>           // map
#include <unordered_set>
#include <unordered_map> // unordered_map
#include <numeric>       // iota
#include <algorithm>     // shuffle
#include <random>        // mt19937
#include <chrono>        // chrono::steady_clock, duration
#include <cstdlib>       // rand

using namespace std;

void InsertionTime() {
    const int N = 10'000'000;

    vector<int> keys(N);
    iota(keys.begin(), keys.end(), 0);
    shuffle(keys.begin(), keys.end(), mt19937{123}); // 랜덤 키 순서

    map<int,int> om;
    unordered_map<int,int> um;
    //um.reserve(N);
    //um.max_load_factor(0.7f);

    auto t1 = chrono::steady_clock::now();
    for (int k : keys) om[k] = rand();
    auto t2 = chrono::steady_clock::now();
    cout << "map: " << chrono::duration<double>(t2 - t1).count() << "s\n";

    t1 = chrono::steady_clock::now();
    for (int k : keys) um[k] = rand();
    t2 = chrono::steady_clock::now();
    cout << "unordered_map: " << chrono::duration<double>(t2 - t1).count() << "s\n";
}

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

    umap.insert(make_pair("Banana", 7));
    umap.insert(make_pair("Kiwi", 6));
    umap.insert(make_pair("Apple", 9));
    umap["Cherry"] = 2;

    for(auto& pair : umap)
    {
        cout << pair.first << " : " << pair.second << "\n";
    }
    cout << "\n";

    // ordered, unordered 성능 비교
    InsertionTime();

    return 0;
}