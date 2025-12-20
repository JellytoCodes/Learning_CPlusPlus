#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());

    stack<int> st;

    int priceNum = prices.size();

    for(int i = 0 ; i < priceNum ; ++i)
    {
        while(!st.empty() && prices[st.top()] > prices[i])
        {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        answer[st.top()] = priceNum - st.top() - 1;
        st.pop();
    }
    return answer;
}

int main()
{
    vector<int> result = solution({1, 2, 3, 2, 3});

    for(auto element : result)
    {
        cout << element << " ";
    }
    cout << "\n";

    return 0;
}