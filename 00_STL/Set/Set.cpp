#include <iostream>
#include <set>
#include <vector>

using namespace std;

void FindElement(const set<int>& s, const vector<int>& v);

int main()
{
    set<int> s = {1, 2, 2, 7, 4, 5, 1, 3};
    set<int> s2(s);
    vector<int> v = {3, 7, 9};

    // set은 중복을 허용하지 않으며, 원소를 자동 정렬
    for(auto it = s.begin() ; it != s.end() ; ++it)
    {
        cout << *it << " ";
    }
    cout << "\n" << "\n";

    // set 원소 탐색
    FindElement(s, v);
    cout << "\n";

    // set 삽입 / 삭제
    s.insert(9);
    s.erase(3);
    FindElement(s, v);
    cout << "\n";

    // 반복자를 활용한 삭제
    auto it = s.find(7);
    if(it != s.end()) s.erase(it);

    // count를 활용한 삽입
    if(s.count(3) == false) s.insert(3);

    FindElement(s, v);
    cout << "\n";

    cout << "s1 : ";
    for(auto it = s.begin() ; it != s.end() ; ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";

    // 참조 초기화가 아니기 때문에 s1의 컨테이너의 영향을 받지 않음
    cout << "s2 : ";
    for(auto it = s2.begin() ; it != s2.end() ; ++it)
    {
        cout << *it << " ";
    }
    cout << "\n" << "\n";

    return 0;
}

void FindElement(const set<int>& s, const vector<int>& v)
{
    for(int target : v)
    {
        auto it = s.find(target);

        if(it != s.end())
        {
            cout << target << " exist element : " << *it << "\n";
        }
        else
        {
            cout << target << " not exist element " << "\n";
        }
    }
}