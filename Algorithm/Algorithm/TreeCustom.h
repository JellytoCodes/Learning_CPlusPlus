#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

using NodeRef = shared_ptr<struct Node>;

struct Node
{
	Node() { }
	Node(const string& data) : data(data) { }
	string data;
	vector<NodeRef> children;
};

// 깊이(depth) : 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수
// 높이(height) : 가장 깊숙히 있는 노드의 깊이

class Tree
{
public :
	NodeRef CreateTree();
	void PrintTree(NodeRef root, int depth);
	int GetHeight(NodeRef root);
};

// 이진 트리 : 각 노드가 최대 두 개의 자식 노드를 가지는 트리
// 왼쪽을 타고 가면 현재 값보다 작고, 오른쪽을 타고 가면 현재 값보다 크다는 특징이 있다.
// 무식하게 추가하면, 한쪽으로 기울어져 균형이 깨지는 문제가 생긴다.
// 트리 재배치를 통해 균형을 유지하는 것이 핵심이다. (AVL, Red-Black)

// 힙 트리 특징
// [부모 노드]가 가진 값은 항상 [자식 노드]가 가진 값보다 크다.
// 노드 개수를 알면, 트리 구조는 무조건 확정할 수 있다.
// 배열을 이용해서 힙 구조를 바로 표현할 수 있다.
// 1) i번 노드의 왼쪽 자식은 [(2*i) + 1] 번
// 2) i번 노드의 오른쪽 자식은 [(2*i) + 2] 번
// 3) i번 노드의 부모는 [(i-1) / 2] 번

template<typename T, typename  Container = vector<T>, typename Predicate = less<T>>
class PriorityQueue
{
public :
	void push(const T& data)
	{
		// 우선 힙 구조부터 맞춰준다.
		_heap.push_back(data);

		// 도장깨기 시작 (부모와의 크기 비교)
		int now = static_cast<int>(_heap.size()) - 1;

		// 루트 노드까지 시도
		while (now > 0)
		{
			// 부모 노드의 데이터와 비교해서 더 작으면 패배
			int next = (now - 1) / 2;
			// if (_heap[now] < _heap[next]) break;

			if (_predicate(_heap[now], _heap[next])) break;

			// 승리했기 때문에(값이 더 크기 때문에) 데이터 교체
			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = (2 * now) + 1;
			int right = (2 * now) + 2;

			// leaf에 도달한 경우
			if (left >= _heap.size()) break;

			int next = now;

			// 왼쪽과 비교
			if (_predicate(_heap[next], _heap[left])) next = left;

			// 둘 중 승자를 오른쪽과 비교
			// 오른쪽은 없는 경우가 있기 때문에 유효성을 체크해줘야 한다.
			if (right < _heap.size() && _predicate(_heap[next], _heap[right])) next = right;

			// 왼쪽/오른쪽 둘 다 현재 값보다 작으면 종료
			if (next == now) break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	T& top()
	{
		return _heap[0];
	}

	bool empty() { return _heap.empty(); }

private :
	Container _heap = { };
	Predicate _predicate;
};