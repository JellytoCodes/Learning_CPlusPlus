#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> matchCnt(3);
    vector<int> fStudent = {1, 2, 3, 4, 5};
    vector<int> sStudent = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> tStudent = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for(int i = 0 ; i < answers.size() ; ++i)
    {
        if(answers[i] == fStudent[i % fStudent.size()]) matchCnt[0]++;
        if(answers[i] == sStudent[i % sStudent.size()]) matchCnt[1]++;
        if(answers[i] == tStudent[i % tStudent.size()]) matchCnt[2]++;
    }
    
    int max_score = *max_element(matchCnt.begin(), matchCnt.end());

    vector<int> ranks;
    for(int i = 0 ; i < 3 ; i++)
    {
        if(matchCnt[i] == max_score)
        {
            ranks.push_back(i+1);
        }
    }

    return ranks;
}

int main()
{
    vector<int> v = solution({1, 3, 2, 4, 2});
    
    for(int i = 0 ; i < v.size() ; ++i)
    {
        cout << v[i];
        if(i != v.size() - 1) cout << ", ";
    }
}