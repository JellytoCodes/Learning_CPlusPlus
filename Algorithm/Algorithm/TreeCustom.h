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