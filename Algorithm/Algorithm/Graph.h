#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct Vertex
{
	
};

class GraphBasic
{
public :
	static void CreateGraph_1();
	static void CreateGraph_2();
	static void CreateGraph_3();
};

// DFS (Depth First Search) ±íÀÌ ¿ì¼± Å½»ö
class DFS
{
public :
	void CreateAdjacentList();
	void CreateAdjacentMatrix();

	void AdjacentListByHere(int here);
	void AdjacentMatrixByHere(int here);

	void DFSAll(bool sw);

	vector<Vertex> vertices;
	vector<vector<int>> adjacent;
	vector<bool> visited;
};

// BFS (Breadth First Search) ³Êºñ ¿ì¼± Å½»ö
class BFS
{
public :
	void CreateAdjacentList();
	void CreateAdjacentMatrix();

	void AdjacentListByHere(int here);
	void AdjacentMatrixByHere(int here);

	void BFSAll(bool sw);

	vector<Vertex> vertices;
	vector<vector<int>> adjacent;
	vector<bool> discovered;	
};

class Dijkstra
{
public :
	vector<Vertex> vertices;
	vector<vector<int>> adjacent;

	void CreateGraph();
	void DijkstraHere(int here);
};