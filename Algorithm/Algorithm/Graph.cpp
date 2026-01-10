#include "Graph.h"

void GraphBasic::CreateGraph_1()
{
	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// 0번 -> 3번 정점이 연결되어 있는가?
	bool connected = false;
	for (const Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			break;
		}
	}
}

void GraphBasic::CreateGraph_2()
{
	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// 드문드문 연결되어 있는 방식에 유리한 예시이다.
	// adjacent[n] -> n번째 정점과 연결된 정점 목록
	vector<vector<int>> adjacent(6);

	adjacent[0] = {1, 3};
	adjacent[1] = {0, 2, 3};
	adjacent[3] = {4};
	adjacent[5] = {4};

	// 0번 -> 3번 정점이 연결되어 있는가?
	bool connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			break;
		}
	}

	// STL
	vector<int>& adj = adjacent[0];
	bool connected2 = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}

void GraphBasic::CreateGraph_3()
{
	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// 행렬을 이용한 그래프 표현으로 간선이 많은 경우 이점이 있다.
	// 메모리에는 소모가 높으나 데이터 접근엔 매우 유리함
	// [X][O][X][O][X][X]
	// [O][X][O][O][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));

	// 읽는 방법 : adjacect[from][to]
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// 0번 -> 3번 정점이 연결되어 있는가?
	bool connected = adjacent[0][3];

	// -1로 필터링하여 정점에 연결 되어있는지 체크
	vector<vector<int>> adjacent2 =
	{
		vector<int>{-1, 15, -1, 35, -1, -1},
		vector<int>{15, -1, +5, 10, -1, -1},
		vector<int>{-1, -1, -1, -1, -1, -1},
		vector<int>{-1, -1, -1, -1, +5, -1},
		vector<int>{-1, -1, -1, -1, -1, -1},
		vector<int>{-1, -1, -1, -1, +5, -1},
	};
}

void DFS::CreateAdjacentList()
{
	vertices.resize(6);

	// 인접 리스트
	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
	
	visited.resize(vertices.size(), false);
}

void DFS::CreateAdjacentMatrix()
{
	vertices.resize(6);

	// 인접 행렬
	adjacent =vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
	};

	visited.resize(vertices.size(), false);
}

// 재귀 함수를 활용한 탐색
// 0
// - 1
// -- 2
// -- 3
// --- 4
// ---- 5
void DFS::AdjacentListByHere(int here)
{
	// 방문 완료
	visited[here] = true;
	cout << "Visited : " << here << "\n";

	// 인접 리스트
	// 모든 인접 정점을 순회한다.
	for (int i = 0 ; i < adjacent[here].size() ; i++)
	{
		// 목적지
		int there = adjacent[here][i];
		if (visited[there] == false) AdjacentListByHere(there);
	}
}

void DFS::AdjacentMatrixByHere(int here)
{
	// 방문 완료
	visited[here] = true;
	cout << "Visited : " << here << "\n";

	// 인접 행렬
	// 모든 입접 정점을 순회한다.
	for (int there = 0 ; there < 6 ; there++)
	{
		if (adjacent[here][there] == 0) continue;

		// 아직 방문하지 않은 곳이 있으면 방문한다.
		if (visited[there] == false) AdjacentMatrixByHere(there);
	}
}

void DFS::DFSAll(bool sw)
{
	for (int i = 0 ; i < 6 ; i++) 
		if (visited[i] == false) 
			sw ? AdjacentListByHere(i) : AdjacentMatrixByHere(i);
}

void BFS::CreateAdjacentList()
{
	vertices.resize(6);

	// 인접 리스트
	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
	
	discovered.resize(vertices.size(), false);
}

void BFS::CreateAdjacentMatrix()
{
	vertices.resize(6);

	// 인접 행렬
	adjacent =vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
	};

	discovered.resize(vertices.size(), false);
}

void BFS::AdjacentListByHere(int here)
{
	// 누구에 의해 발견 되었는가?
	vector<int> parent(6, -1);
	// 시작점에서 얼마나 떨어져 있는가?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited : " << here << "\n";

		for (int there : adjacent[here])
		{
			if (discovered[there]) continue;

			q.push(there);
			discovered[there] = true;

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}
}

void BFS::AdjacentMatrixByHere(int here)
{
	// 누구에 의해 발견 되었는가?
	vector<int> parent(6, -1);
	// 시작점에서 얼마나 떨어져 있는가?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited : " << here << "\n";

		for (int there = 0 ; there < 6 ; there++)
		{
			if (adjacent[here][there] == 0) continue;
			if (discovered[there]) continue;

			q.push(there);
			discovered[there] = true;

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}
}

void BFS::BFSAll(bool sw)
{
	for (int i = 0 ; i < 6 ; i++)
		if (discovered[i] == false)
			sw ? AdjacentListByHere(i) : AdjacentMatrixByHere(i);
}

void Dijkstra::CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[5][4] = 5;

}

void Dijkstra::DijkstraHere(int here)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	// BFS, DFS와는 달리 queue 대신 list를 사용하는 이유는
	// 먼저 발견한 원소가 먼저 방문이 된다는 보장이 없기 때문에
	// FIFO 방식은 사용할 수 없어 다른 자료 구조로 관리를 하는 것
	// 발견 목록
	list<VertexCost> discovered;

	// 각 정점별로 지금까지 발견한 최소 거리
	vector<int> best(6, INT32_MAX);

	vector<int> parent(6, -1);

	discovered.push_back(VertexCost{here, 0});
	best[here] = 0;
	parent[here] = here;

	while (discovered.empty() == false)
	{
		// 제일 좋은 후보를 찾는다
		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;

		for (auto it = discovered.begin() ; it != discovered.end() ; ++it)
		{
			if (it->cost < bestCost)
			{
				bestCost = it->cost;
				bestIt = it;
			}
		}

		int cost = bestIt->cost;
		here = bestIt->vertex;
		discovered.erase(bestIt);

		// 방문을 하는데 더 짧은 경로를 뒤늦게 찾았다면 스킵
		if (best[here] < cost) continue;

		// 방문
		for (int there = 0 ; there < 6 ; there++)
		{
			// 연결되지 않았으면 스킵
			if (adjacent[here][there] == -1) continue;

			// 더 좋은 경로를 과거에 찾았으면 스킵
			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there]) continue;

			best[there] = nextCost;
			parent[there] = here;

			discovered.push_back(VertexCost{there, nextCost});
		}
	}
	int dummy = 3;
}
