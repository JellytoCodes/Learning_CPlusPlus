#pragma once

#include <vector>
#include <iostream>

using namespace std;

// 이진 탐색(binary search) = O(logN)
// 정렬된 배열을 이용해서 이진 탐색 가능
// 정렬된 연결 리스트로는 불가 (임의 접근 불가)

// 배열의 단점으론 중간 삽입/삭제가 느리다.
// 때문에 이진 탐색만으론 한계가 있기 때문에 이진 탐색 트리가 필요하다.

class BinarySearch
{
public :
	void Search(int N);

	vector<int> numbers;
};

// 이진 탐색 트리(binary search tree)
struct Node
{
	Node*	parent	= nullptr;
	Node*	left	= nullptr;
	Node*	right	= nullptr;
	int		key		= { };

	// 데이터가 비어있는 공간에
	// 데이터가 비어있다는 것을 표시하기 위한 방식으로 사용되는 경우가 있음
	// [nil]
	bool external;
};

class BinarySearchTree
{
public :
	void	Print() { Print(_root, 10, 0); }
	void	Print(Node* node, int x, int y);

	// 전위 순회 (preorder traverse) [중][전][후]
	// 중위 순회 (inorder traverse) [전][중][후]
	// 후위 순회 (postorder traverse) [전][후][중]
	void	Print_Inorder() { Print_Inorder(_root); }
	void	Print_Inorder(Node* node);

	Node*	Search(Node* node, int key);
	Node*	Search2(Node* node, int key);

	Node*	Min(Node* node);
	Node*	Max(Node* node);
	Node*	Next(Node* node);

	void	Insert(int key);

	void	Delete(int key);
	void	Delete(Node* node);

	void	Replace(Node* u, Node* v);

private:
	Node*	_root = nullptr;
};
