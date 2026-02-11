#pragma once

// 이진 탐색(binary search) = O(logN)
// 정렬된 배열을 이용해서 이진 탐색 가능
// 정렬된 연결 리스트로는 불가 (임의 접근 불가)

// 배열의 단점으론 중간 삽입/삭제가 느리다.
// 때문에 이진 탐색만으론 한계가 있기 때문에 이진 탐색 트리가 필요하다.

enum class Color
{
	Red = 0,
	Black = 1
};

struct Node
{
	Node*	parent	= nullptr;
	Node*	left	= nullptr;
	Node*	right	= nullptr;
	int		key		= { };

	// nil 노드는 Black이기 때문에 기본값을 Black으로 설정
	Color	color = Color::Black;

	// 데이터가 비어있는 공간에
	// 데이터가 비어있다는 것을 표시하기 위한 방식으로 사용되는 경우가 있음
	// [nil]
	//bool external;
};

// Read-Black Tree
// 1) 모든 노드는 Red or Black
// 2) Root는 Black
// 3) Leaf(NIL)는 Black
// 4) Red 노드의 자식은 Black (연속해서 Red가 나올 수 없음)
// 5) 각 노드로부터 리프까지 가는 경로들은 모두 같은 수의 Black
// 
class BinarySearchTree
{
public :
	BinarySearchTree();
	~BinarySearchTree();

	void	Print();
	void	Print(Node* node, int x, int y);

	// 전위 순회 (preorder traverse) [중][전][후]
	// 중위 순회 (inorder traverse) [전][중][후]
	// 후위 순회 (postorder traverse) [전][후][중]
	//void	Print_Inorder() { Print_Inorder(_root); }
	//void	Print_Inorder(Node* node);

	Node*	Search(Node* node, int key);
	//Node*	Search2(Node* node, int key);

	Node*	Min(Node* node);
	Node*	Max(Node* node);
	Node*	Next(Node* node);

	void	Insert(int key);
	void	InsertFixup(Node* node);

	void	Delete(int key);
	void	Delete(Node* node);
	void	DeleteFixup(Node* node);

	void	Replace(Node* u, Node* v);

	// Red-Black Tree Helper
	void LeftRotate(Node* x);
	void RightRotate(Node* y);

private:
	Node*	_root = nullptr;
	Node*	_nil = nullptr;
};