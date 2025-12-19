#include <iostream>
#include <set>
#include <unordered_set>
#include <tuple>
#include <string>
using namespace std;

struct Edge {
    int x1, y1, x2, y2;

    // set에서 컨테이너가 유일성/정렬을 판단하기 위함
    bool operator<(const Edge& other) const {
        return tie(x1, y1, x2, y2) < tie(other.x1, other.y1, other.x2, other.y2);
    }
};

int solution(const string& dirs)
{
    set<Edge> visited;
    int x = 0, y = 0;

    for(char ch : dirs)
    {
        int nx = x, ny = y;

        if(ch == 'U') ny++;
        else if(ch == 'D') ny--;
        else if(ch == 'R') nx++;
        else if(ch == 'L') nx--;

        if(nx < -5 || nx > 5 || ny < -5 || ny > 5) continue;

        Edge e;
        if(tie(x, y) < tie(nx, ny)) e = {x, y, nx, ny};
        else                       e = {nx, ny, x, y};

        visited.insert(e);

        // 실제 위치 갱신
        x = nx; y = ny;
    }

    return (int)visited.size();
}

int main()
{
    cout << solution("ULURRDLLU") << "\n";
    cout << solution("LULLLLLLU") << "\n";
    return 0;
}
