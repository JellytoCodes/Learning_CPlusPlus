#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool match(const char open, const char close)
{
    return  (open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}');
}

bool isValid(const string& s, int start)
{
    const int n = (int)s.size();
    stack<char> st;

    for(int k = 0 ; k < n ; ++k)
    {
        char c = s[(start + k) % n];
        
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else
        {
            if(st.empty() || !match(st.top(), c)) return false;
            st.pop();
        }
    }
    return st.empty();
}

int solution(string str)
{
    const int n = (int)str.size();
    int cnt = 0;
    
    for(int start = 0 ; start < n ; ++start)
        if(isValid(str, start)) ++cnt;

    return cnt;
}

int main()
{
    clock_t start, end;
    start = clock();
    cout << solution("[](){}") << "\n";
    end = clock();

    printf("Time : %f \n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}