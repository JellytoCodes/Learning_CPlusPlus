#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<char> st;

	int left = 0;
	int right = 0;

	for(auto ch : s)
	{
		if(ch == '(') st.push(ch);
		else if(ch == ')')
		{
			if(st.empty())	return false;
			else			st.pop();
		}
	}
	return st.empty();
}

int main()
{
	cout << solution("(())()") << "\n";
	cout << solution("((())()") << "\n";
	
	return 0;
}