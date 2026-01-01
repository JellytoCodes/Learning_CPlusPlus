#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string solution(vector<string> card1, vector<string> card2, vector<string>goal)
{
    queue<string> qCard1, qCard2, qGoal;

    for(auto str : card1) qCard1.push(str);
    for(auto str : card2) qCard2.push(str);
    for(auto str : goal) qGoal.push(str);

    while(!qGoal.empty())
    {
        if(!qCard1.empty() && qCard1.front() == qGoal.front())
        {
            qCard1.pop();
            qGoal.pop();
        }
        else if(!qCard2.empty() && qCard2.front() == qGoal.front())
        {
            qCard2.pop();
            qGoal.pop();
        }
        else
        {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    cout << solution({"i", "drink", "water"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << "\n";
    cout << solution({"i", "water", "drink"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << "\n";

    return 0;
}