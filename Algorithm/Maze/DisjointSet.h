#pragma once

class DisjointSet
{
public :
	DisjointSet(int n)
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

