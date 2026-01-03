#include <iostream>
#include <vector>

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
int main()
{
    vector<int> v;

    v.reserve(100);

    for (int i = 0 ; i < 100 ; i++)
    {
	    v.push_back(i);
        cout << v[i] << " : " << v.size() << " " << v.capacity() << "\n";
    }

    v.resize(10);
    cout << v.size() << " " << v.capacity() << "\n";

    v.clear();
    // size는 초기화되나 capacity는 초기화되지 않음
    cout << v.size() << " " << v.capacity() << "\n";
}