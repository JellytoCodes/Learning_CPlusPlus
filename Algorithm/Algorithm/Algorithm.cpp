#include <iostream>
#include <thread>

#include "Sort.h"

int main()
{
	vector<int> v;

	srand(time(0));

	for (int i = 0 ; i < 10 ; i++)
	{
		int randValue = rand() % 100;
		v.push_back(randValue);
	}

	// MergeSort(v, 0, v.size()-1);
	Sort::QuickSort(v, 0, v.size() - 1);
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