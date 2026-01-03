#include "Custom.h"

void PracticeVector();
void PracticeList();

int main()
{
	//PracticeVector();
    PracticeList();
}

void PracticeVector()
{
	vector<int> v;

    v.reserve(100);

    for (int i = 0 ; i < 100 ; i++)
    {
	    v.push_back(i);
        cout << v[i] << " : " << v.size() << " " << v.capacity() << "\n";
    }

    v.resize(10);
    cout << v.size() << " " << v.capacity() << "\n";

    v.clear();
    
    cout << v.size() << " " << v.capacity() << "\n";
}

void PracticeList()
{
    List<int> li;

    List<int>::iterator eraseIt;

    for (int i = 0 ; i < 10 ; i++)
    {
        if (i == 5)
        {
	        eraseIt= li.insert(li.end(), i);
        }
        else
        {
			li.push_back(i);    
        }
    }

    li.pop_back();

	// 리스트의 삽입/삭제가 빠른 것은 조건부이다.
	// 삭제가 빠른 경우는 지우고자하는 데이터를 이미 갖고 있는 경우 빠르게 삭제가 가능하다.
    li.erase(eraseIt);

    for (auto it = li.begin() ; it != li.end() ; ++it) cout << (*it) << "\n";
}
