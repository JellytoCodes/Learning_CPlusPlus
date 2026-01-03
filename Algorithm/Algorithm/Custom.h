#pragma once

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
class Vector
{
public :
	Vector()
	{
	
	}

	~Vector()
    {
		if (_data) delete[] _data;
    }

    void push_back(const T& value)
    {
	    if (_size == _capacity)
	    {
		    // 증설 작업
            int newCapacity = static_cast<int>(_capacity * 1.5);
            if (newCapacity == _capacity) newCapacity++;

            reserve(newCapacity);
	    }

		// 데이터 저장
		_data[_size] = value;

		_size++;
    }

	void reserve(int capacity)
    {
		if (_capacity >= capacity) return;

        _capacity = capacity;

        T* newData = new T[_capacity];

        // 데이터 복사
        for (int i = 0 ; i < _size ; i++) newData[i] = _data[i];

        if (_data) delete[] _data;

        _data = newData;
    }

    T& operator[](const int pos) { return _data[pos]; }

    // size는 초기화되나 capacity는 초기화되지 않는 차이를 확실하게 알고 넘어가야한다.
    int size()      { return _size; }
    int capacity()  { return _capacity; }

    void clear()
    {
		if (_data)
		{
			delete[] _data;
            _data = new T[_capacity];
		}

	    _size = 0;
    }

private :
	T*          _data = nullptr;

    // 현재 데이터의 총 개수
    int         _size = 0;

    // 할당받은 데이터의 총 크기
    int         _capacity = 0;
};

template<typename T>
class Node
{
public :
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{
	
	}

    Node(const T& value)  : _prev(nullptr), _next(nullptr), _data(value)
	{
		
	}

    Node*   _prev;
    Node*   _next;
	T       _data;
};

template<typename T>
class Iterator
{
public :
	Iterator() : _node(nullptr)
	{
		
	}
	Iterator(Node<T>* node) : _node(node)
	{
		
	}

	Node<T>* _node;

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	// it++
	Iterator& operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	// it--
	Iterator& operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}
};

template<typename  T>
class List
{
public :
    List() : _size(0)
	{
		_head = new Node<T>();
	    _tail = new Node<T>();

		// [head] <-> ... <-> [tail]
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		while (_size > 0) pop_back();

		delete _head;
		delete _tail;
	}

    void push_back(const T& value)
	{
		AddNode(_tail, value);
	}

    void pop_back()
	{
		RemoveNode(_tail->_prev);
	}

	int size() { return _size; }

	using iterator = Iterator<T>;

	iterator begin() { return iterator (_head->_next); }
	iterator end() { return iterator (_tail); }

	// it 앞에 추가
	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

private :
    // Before :
    // [head] <-> [1] <-> [prevNode] <-> [before] <-> [tail]
	// After :
    // [head] <-> [1] <-> [prevNode] <-> [newNode] <-> [before] <-> [tail]
    Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}

    // Before :
	// [head] <-> [1] <-> [prevNode] <-> [node] <-> [nextNode] <-> [tail]
	// After :
    // [head] <-> [1] <-> [prevNode] <-> [nextNode] <-> [tail]
    Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}
	
private :
    // 리스트의 시작
    Node<T>*    _head;

    // 리스트의 끝
    Node<T>*    _tail;
    int         _size;
};