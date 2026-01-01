#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string str)
{
    stack<char> st;

    for(int i = 0 ; i < str.size() ; ++i)
    {
        if(st.empty() || st.top() != str[i]) st.push(str[i]);
        else st.pop();
    }
    return st.empty();
}

int main()
{
    cout << solution("baabaa") << "\n";
    cout << solution("cdcdcd") << "\n";

    return 0;
}