#include <iostream>
#include <thread>

#include "SearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree bst;

	bst.Insert(30);
	bst.Print();
	this_thread::sleep_for(std::chrono::seconds(1));

	bst.Insert(10);
	bst.Print();
	this_thread::sleep_for(std::chrono::seconds(1));

	bst.Insert(20);
	bst.Print();
	this_thread::sleep_for(std::chrono::seconds(1));

	bst.Insert(25);
	bst.Print();
	this_thread::sleep_for(std::chrono::seconds(1));

	bst.Delete(20);
	bst.Print();
	this_thread::sleep_for(std::chrono::seconds(1));

	bst.Delete(10);
	bst.Print();
	this_thread::sleep_for(std::chrono::seconds(1));

	/*
	int a = 0;
	srand((unsigned int)&a);

	int total = 0;
	for (int i = 0; i <= 10 ; i++)
	{
		bool check = rand() % 2;
		if (check) total += i;
	}
	cout << total << "\n";
	*/
}