#pragma once
#include <algorithm>
#include <vector>

// 그래프/트리 응용
// 최소 스패닝 트리 (Minimum Spanning Tree)

// 상호 베타적 집합 (Disjoint Set)
// -> 유니온-파인드 (Union-Find)
// 직관적인 뜻대로 합치고 찾는데 유용한 알고리즘이라 생각하면된다.

// 단순한 유니온 파인드
static void UnionFind()
{
	struct User
	{
		int teamId;

	};

	// UserManager
	std::vector<User> users;
	for (int i = 0 ; i < 1000 ; i++)
	{
		users.push_back(User{i});
	}

	// 팀 동맹
	users[5].teamId = users[1].teamId;

	// teamId=1 과 teamId=2 통합이 되었을 때
	for (User& user : users)
	{
		if (user.teamId == 1)
			user.teamId = 2;
	}

	// 찾기 연산 O(1)
	// 합치기 연산 O(N)
}

// 트리 구조를 이용한 상호 베타적 집합의 표현
// 회사 조직도와 같은 느낌의 형태가 만들어진다.

// 시작 복잡도는 트리의 높이에 비례해 시간이 걸린다.
struct Node
{
	Node* leader;
};

class NaiveDisjointSet
{
public :
	NaiveDisjointSet(int n)
		: _parent(n)
	{
		for (int i = 0 ; i < n ; i++)
		{
			_parent[i] = i;
		}
	}

	// 최상위가 누구인지 찾기
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return Find(_parent[u]);
	}

	// u와 v를 합치기 (ex) u가 v밑으로)
	void Merge(int u, int v)
	{
		// 무조건 최상위 노드를 가져오기
		u = Find(u);
		v = Find(v);

		// 서로 최상위 노드가 같으면 더 진행할 필요가 없음
		if (u == v) 
			return;

		_parent[u] = v;
	}

private :
	std::vector<int> _parent;
};

// 트리의 구조가 한쪽으로 쏠리는 문제
// -> 트리를 합칠 때, 항상 [높이가 낮은 트리를][높이가 높은 트리]밑으로
// (Union-by-Rank) 랭크에 의한 합치기 최적화

// 시간 복잡도 O(Ackermann(n)) = O(1)
class DisjoinSet
{
public :
	DisjoinSet(int n)
		: _parent(n), _rank(n, 1)
	{
		for (int i = 0 ; i < n ; i++)
		{
			_parent[i] = i;
		}
	}

	// 최상위가 누구인지 찾기
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return _parent[u] = Find(_parent[u]);
	}

	// u와 v를 합치기 (ex) u가 v밑으로)
	void Merge(int u, int v)
	{
		// 무조건 최상위 노드를 가져오기
		u = Find(u);
		v = Find(v);

		// 서로 최상위 노드가 같으면 더 진행할 필요가 없음
		if (u == v) 
			return;

		if (_rank[u] > _rank[v])
			std::swap(u, v);

		// rank[u] <= rank[v]
		_parent[u] = v;

		if (_rank[u] == _rank[v]) 
			_rank[v]++;
	}

private :
	std::vector<int> _parent;
	std::vector<int> _rank;
};


struct Vertex
{
	
};

static std::vector<Vertex> vertices;
static std::vector<std::vector<int>> adjacent; // 인접 행렬

static void CreateGraph()
{
	vertices.resize(6);
	adjacent = std::vector<std::vector<int>>(6, std::vector<int>(6, -1));

	adjacent[0][1] = adjacent[1][0] = 15;
	adjacent[0][3] = adjacent[3][0] = 35;
	adjacent[1][2] = adjacent[2][1] = 5;
	adjacent[1][3] = adjacent[3][1] = 10;
	adjacent[3][4] = adjacent[4][3] = 5;
	adjacent[3][5] = adjacent[5][3] = 10;
	adjacent[5][4] = adjacent[4][5] = 5;
}

struct CostEdge
{
	int cost;
	int u;
	int v;

	bool operator<(CostEdge& other)
	{
		return cost < other.cost;
	}
};

static int Kruskal(std::vector<CostEdge>& selected)
{
	int ret = 0;

	selected.clear();

	std::vector<CostEdge> edges;

	for (int u = 0 ; u < adjacent.size(); u++)
	{
		for (int v= 0 ; v < adjacent[u].size() ; v++)
		{
			// 중복 간선 스킵 ex) [0][1] == [1][0]
			if (u > v) 
				continue;

			int cost = adjacent[u][v];
			if (cost == -1)
				continue;

			edges.push_back(CostEdge{cost, u, v});
		}
	}
	std::sort(edges.begin(), edges.end());

	DisjoinSet sets(vertices.size());

	for (CostEdge& edge : edges)
	{
		// 같은 그룹이면 스킵 (하지 않을 경우 사이클 발생)
		if (sets.Find(edge.u) == sets.Find(edge.v))
			continue;

		// 두 그룹을 합친다.
		sets.Merge(edge.u, edge.v);
		selected.push_back(edge);
		ret += edge.cost;
	}

	return ret;
}