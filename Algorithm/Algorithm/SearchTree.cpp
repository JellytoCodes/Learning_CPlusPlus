#include "SearchTree.h"
#include <iostream>
#include <windows.h>
using namespace std;

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y)};
	::SetConsoleCursorPosition(output, pos);
}

void SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<SHORT>(color));
}

void ShowConsoleCursor(bool flag)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = flag;
	::SetConsoleCursorInfo(output, &cursorInfo);
}

BinarySearchTree::BinarySearchTree()
{
	_nil = new Node();	// Black
	_root = _nil;
}

BinarySearchTree::~BinarySearchTree()
{
	delete _nil;
}

void BinarySearchTree::Print()
{
	::system("cls");
	ShowConsoleCursor(false);
	Print(_root, 10, 0);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == _nil)
		return;

	SetCursorPosition(x, y);

	if (node->color == Color::Black)
		SetCursorColor(ConsoleColor::BLUE);
	else
		SetCursorColor(ConsoleColor::RED);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

	SetCursorColor(ConsoleColor::WHITE);
}
/*
void BinarySearchTree::Print_Inorder(Node* node)
{
	if (node == nullptr) return;

	cout << node->key << "\n";
	Print_Inorder(node->left);
	Print_Inorder(node->right);
}
*/

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == _nil || key == node->key) return node;

	if (key < node->key)	return Search(node->left, key);
	else					return Search(node->right, key);
}

/*
Node* BinarySearchTree::Search2(Node* node, int key)
{
	while (node && key != node->key)
	{
		if (key < node->key)	node = node->left;
		else					node = node->right;
	}
	return node;
}
*/

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left != _nil)
	{
		node = node->left;	
	}
	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right != _nil)
	{
		node = node->right;	
	}
	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right != _nil)	return Min(node->right);

	Node* parent = node->parent;
	while (parent != _nil && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	Node* node = _root;
	Node* parent = _nil;

	while (node != _nil)
	{
		parent = node;
		if (key < node->key)	node = node->left;
		else					node = node->right;
	}

	newNode->parent = parent;

	if (parent == _nil)		
		_root = newNode;
	if (key < parent->key)	
		parent->left = newNode;
	else					
		parent->right = newNode;

	// 검사
	newNode->left = _nil;
	newNode->right = _nil;
	newNode->color = Color::Red;

	InsertFixup(newNode);
}

void BinarySearchTree::InsertFixup(Node* node)
{
	while (node->parent->color == Color::Red)
	{
		if (node->parent == node->parent->parent->left)
		{
			// 현재 parent의 상위에 있는 parent의 반대편 parent가 uncle
			Node* uncle = node->parent->parent->right;

			if (uncle->color == Color::Red)
			{
				// 1) p = red, uncle = red
				// -> p = black, uncle = black, pp = red로 바꿈
				node->parent->color = Color::Black; // parent
				uncle->color = Color::Black; // uncle
				node->parent->parent->color = Color::Red; // parent->parent

				// parent의 상위에 있는 parent의 상위에 또 다른 parent가 있는지를 확인해야하기 때문에
				// 아래와 같이 대입한다.
				node = node->parent->parent;
			}
			else // uncle->color == Color::Black
			{
				// 2) p = red, uncle = black (triangle) 트리가 <자 형태로 이루어진 상황
				// -> 회전을 통해 3) 으로 바꿈
				if (node == node->parent->right)
				{
					node = node->parent;
					LeftRotate(node);
				}

				// 3) p = red, uncle = black (list) 트리가 직선 형태로 이루어진 상황
				// -> 색상 변경 + 회전
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				RightRotate(node->parent->parent);
			}
		}
		else // node->parent == node->parent->parent->right
		{
			// 현재 parent의 상위에 있는 parent의 반대편 parent가 uncle
			Node* uncle = node->parent->parent->left;

			if (uncle->color == Color::Red)
			{
				// 1) p = red, uncle = red
				// -> p = black, uncle = black, pp = red로 바꿈
				node->parent->color = Color::Black; // parent
				uncle->color = Color::Black; // uncle
				node->parent->parent->color = Color::Red; // parent->parent

				// parent의 상위에 있는 parent의 상위에 또 다른 parent가 있는지를 확인해야하기 때문에
				// 아래와 같이 대입한다.
				node = node->parent->parent;
			}
			else // uncle->color == Color::Black
			{
				// 2) p = red, uncle = black (triangle) 트리가 >자 형태로 이루어진 상황
				// -> 회전을 통해 3) 으로 바꿈
				if (node == node->parent->left)
				{
					node = node->parent;
					RightRotate(node);
				}

				// 3) p = red, uncle = black (list) 트리가 직선 형태로 이루어진 상황
				// -> 색상 변경 + 회전
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				LeftRotate(node->parent->parent);
			}
		}
	}
	// root의 컬러는 항상 Black이어야 한다.
	_root->color = Color::Black;
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == _nil) return;

	if (node->left == _nil)
	{
		Color color = node->color;
		Node* right = node->right;
		Replace(node, node->right);

		if (color == Color::Black)
			DeleteFixup(right);
	}
	else if (node->right == _nil)
	{
		Color color = node->color;
		Node* left = node->left;
		Replace(node, node->left);

		if (color == Color::Black)
			DeleteFixup(left);
	}
	else								
	{
		// 다음 데이터 찾기
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

void BinarySearchTree::DeleteFixup(Node* node)
{
	// 삭제할 노드
	Node* x = node;

	while (x != _root && x->color == Color::Black)
	{
		if (x == x->parent->left)
		{
			Node* s = x->parent->right;
			if (s->color == Color::Red)
			{
				s->color = Color::Black;
				x->parent->color = Color::Red;
				LeftRotate(x->parent);

				s = x->parent->right;
			}

			if (s->left->color == Color::Black && s->right->color == Color::Black)
			{
				s->color = Color::Red;
				x= x->parent;
			}
			else
			{
				if (s->right->color == Color::Black)
				{
					s->left->color = Color::Black;
					s->color = Color::Red;
					RightRotate(s);
					s = x->parent->right;
				}

				s->color = x->parent->color;
				x->parent->color = Color::Black;
				s->right->color = Color::Black;
				LeftRotate(x->parent);
				x = _root;
			}
		}
		else // x == x->parent->right
		{
			Node* s = x->parent->left;
			if (s->color == Color::Red)
			{
				s->color = Color::Black;
				x->parent->color = Color::Red;
				LeftRotate(x->parent);

				s = x->parent->left;
			}

			if (s->left->color == Color::Black && s->left->color == Color::Black)
			{
				s->color = Color::Red;
				x= x->parent;
			}
			else
			{
				if (s->left->color == Color::Black)
				{
					s->right->color = Color::Black;
					s->color = Color::Red;
					LeftRotate(s);
					s = x->parent->left;
				}

				s->color = x->parent->color;
				x->parent->color = Color::Black;
				s->left->color = Color::Black;
				RightRotate(x->parent);
				x = _root;
			}	
		}
	}

	x->color = Color::Black;
}

// u 서브트리를 v 서브트리로 교체 후 u를 delete
void BinarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parent == _nil)		
		_root = v;
	else if (u == u->parent->left)	
		u->parent->left = v;
	else							
		u->parent->right = v;

	v->parent = u->parent;

	delete u;
}

void BinarySearchTree::LeftRotate(Node* x)
{
	Node* y = x->right;

	x->right = y->left;
	if (y->left != _nil) 
		y->left->parent = x;

	y->parent = x->parent;

	// x가 최상위 노드인지에 따른 분기
	if (x->parent == _nil)
		_root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

void BinarySearchTree::RightRotate(Node* y)
{
	Node* x = y->left;

	y->left = x->right;
	if (y->right != _nil) 
		y->right->parent = y;

	x->parent = y->parent;

	// y가 최상위 노드인지에 따른 분기
	if (y->parent == _nil)
		_root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	x->right = y;
	y->parent = x;

}