#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

long long polynomial_hash(const string& str)
{
    const int p = 31;
    const long long m = 1000000007;
    long long hash_value = 0;

    for(char c : str) hash_value = (hash_value * p + c) % m;

    return hash_value;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
    unordered_set<long long> hash_set;

    for(const string& str : string_list)
    {
        long long hash = polynomial_hash(str);
        hash_set.insert(hash);
    }

    vector<bool> result;

    for(const string& query : query_list)
    {
        long long query_hash = polynomial_hash(query);
        result.push_back(hash_set.find(query_hash) != hash_set.end());
    }

    return result;
}

int main()
{
    vector<bool> result = solution({"apple", "banana", "cherry"}, {"banana", "kiwi", "melon", "apple"});

    for(bool r : result) cout << (r ? "true" : "false") << " ";
}