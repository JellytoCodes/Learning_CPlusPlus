#include <iostream>
#include <stack>
#include <string>

using namespace std;

string solution(int val)
{
    stack<int> binary;
    while(val > 0)
    {
        binary.push(val % 2);
        val /= 2;
    }

    string result;
    while(!binary.empty())
    {
        result += to_string(binary.top());
        binary.pop();
    }
    
    return result;
}

int main()
{
    cout << solution(10) << "\n";
    cout << solution(27) << "\n";
    cout << solution(12345) << "\n";

    return 0;
}