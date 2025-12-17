#include <iostream>
#include <map>

using namespace std;

int main()
{
    // 키-값을 쌍으로 갖는 컨테이너
    map<string, int> studentScores
    {
        {"Alice", 95},
        {"Bob", 90},
        {"Charlie", 80}
    };

    // map의 하나의 원소는 pair 타입으로 표현
    for(const auto& pair : studentScores)
    {
        cout << pair.first << " : " << pair.second << "\n";
    }
    cout << "\n";

    // [] 연산자를 통한 원소 삽입
    studentScores["Rabbit"] = 90;

    auto score = studentScores.find("Rabbit");
    if(score != studentScores.end())
    {
        cout << score->first << " : " << score->second << "\n";
    }
    cout << "\n";

    // insert를 통한 원소 삽입
    studentScores.insert(make_pair("Sophia", 70));

    // erase를 통한 원소 제거
    studentScores.erase("Alice");

    // 반복자를 통한 원소 제거
    auto it = studentScores.find("Bob");
    if(it != studentScores.end()) studentScores.erase(it);

    for(auto& pair : studentScores)
    {
        // 참조이기 때문에 studentScores의 값도 변경
        if(pair.first == "Rabbit") pair.second = 20;

        cout << pair.first << " : " << pair.second << "\n";
    }
    cout << "\n";

    score = studentScores.find("Rabbit");
    if(score != studentScores.end())
    {
        cout << score->first << " : " << score->second << "\n";
    }

    return 0;
}