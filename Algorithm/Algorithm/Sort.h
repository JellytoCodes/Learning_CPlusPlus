#pragma once
#include <queue>
#include <vector>

using namespace std;

class Sort
{
public :
	// 1) 버블 정렬 (Bubble Sort)
	static void BubbleSort(vector<int>& v)
	{
		const int n = v.size();

		// (N-1) + (N-2) + ... + 2 + 1
		// 등차수열의 합 = N * (N-1) / 2
		// O(N^2)
		for (int i = 0 ; i < n - 1 ; i++)
		{
			for (int j = 0 ; j < ((n - 1) - i) ; j++)
			{
				if (v[j] > v[j + 1])
				{
					int temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
				}
			}
		}
	}

	// 2) 선택 정렬 (Selection Sort)
	static void SelectionSort(vector<int>& v)
	{
		const int n = v.size();

		// 시간 복잡도는 버블 정렬과 동일하나
		// 데이터를 정렬하는 방식이 달라 미세한 차이가 있음
		// O(N^2)
		for (int i = 0 ; i < n - 1 ; i++)
		{
			int bestIdx = i;
			for (int j = i + 1 ; j < n ; j++)
			{
				if (v[j] < v[bestIdx]) 
					bestIdx = j;
			}

			// 교환
			int temp = v[i];
			v[i] = v[bestIdx];
			v[bestIdx] = temp;

		}
	}

	// 3) 삽입 정렬 (Insertion Sort)
	static void InsertionSort(vector<int>& v)
	{
		const int n = v.size();

		// 시간 복잡도는 버블 정렬과 동일하나
		// 기본적으로 어느정도 데이터가 정렬이 잘 되어있다면 효율은 조금 더 높다.
		// O(N^2)
		for (int i = 1 ; i < n ; i++)
		{
			int insertData = v[i];

			int j;
			for (j = i - 1 ; j >= 0 ; j--)
			{
				if (v[j] > insertData)
					v[j + 1] = v[j];
				else
					break;
			}
			v[j + 1] = insertData;
		}
	}

	// 4) 힙 정렬 (Heap Sort)
	static void HeapSort(vector<int>& v)
	{
		// priority queue는 힙 구조을 기반으로 만들어져있다.
		priority_queue<int, vector<int>, greater<int>> pq;

		// O(NlogN)
		for (int num : v) 
			pq.push(num);

		v.clear();

		// O(NlogN)
		while (pq.empty() == false)
		{
			v.push_back(pq.top());
			pq.pop();
		}
	}

	// 5) 병합 정렬 (Merge Sort)
	// 분할 정복 (Divide and Conquer)
	// - 분할 (Divide)	문제를 더 단순하게 분할
	// - 정복 (Conquer)	분할된 문제를 해결
	// - 결합 (Combine)	결과를 취합하여 마무리
	static void MergeResult(vector<int>&v, int left, int mid, int right)
	{
		// O(NlogN)
		int leftIdx = left;
		int rightIdx = mid + 1;

		vector<int> temp;

		while (leftIdx <= mid && rightIdx <= right)
		{
			if (v[leftIdx] <= v[rightIdx])
			{
				temp.push_back(v[leftIdx++]);
			}
			else
			{
				temp.push_back(v[rightIdx++]);
			}
		}

		// 왼쪽이 먼저 끝난 경우
		if (leftIdx > mid)
		{
			while (rightIdx <= right)
			{
				temp.push_back(v[rightIdx++]);
			}
		}
		// 오른쪽이 먼저 끝난 경우
		else
		{
			while (leftIdx <= mid)
			{
				temp.push_back(v[leftIdx++]);
			}
		}

		for (int i = 0 ; i < temp.size() ; i++)
		{
			v[left + i] = temp[i];
		}
	}

	static void MergeSort(vector<int>& v, int left, int right)
	{
		if (left >= right) 
			return;

		int mid = (left + right) / 2;

		MergeSort(v, left, mid);
		MergeSort(v, mid + 1, right);

		MergeResult(v, left, mid, right);
	}

	// 6) 퀵 정렬(Quick Sort)
	static int Partition(vector<int>& v, int left, int right)
	{
		int pivot = v[left];
		int low = left + 1;
		int high = right;

		// O(N)
		while (low <= high)
		{
			while (low <= right && pivot >= v[low])
				low++;

			while (high > left && pivot <= v[high])
				high--;

			if (low < high)
			{
				swap(v[low], v[high]);
			}
		}

		swap(v[left], v[high]);
		return high;
	}

	// 병합 정렬과 시간 복잡도가 같아서 차이는 없어보일 수 있으나
	// 데이터 복사 등의 행위를 생각하면 차이가 발생할 수 있음을 알 수 있다.
	// 평균 : O(NlogN)
	// 최악 : O(N^2)
	static void QuickSort(std::vector<int>& v, int left, int right)
	{
		if (left > right) return;

		int pivot = Partition(v, left, right);
		QuickSort(v, left, pivot - 1);
		QuickSort(v, pivot + 1, right);
	}
};

