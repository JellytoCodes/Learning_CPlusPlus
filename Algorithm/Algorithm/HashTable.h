#pragma once
#include <iostream>
#include <vector>

using namespace std;

class HashTable
{
public:
	// Hash Table
	// Q. map vs hash_map

	// map : Red-Black Tree 구조
	// - 추가/탐색/삭제 O(logN)

	// hash_map( = unordered map) :
	// 메모리의 사용을 늘리고 속도를 증가시킨다.
	// - 추가/탐색/삭제 O(1)

	// 참고.
	// C# dictionary != C++ map
	// C# dictionary == C++ unordered_map

	/////////////////////////////////////////////////////

	static void TestTable()
	{
		struct User
		{
			int userId = 0;
			string userName;
		};

		vector<User> users;
		users.resize(1000);

		// 777번 유저 정보 세팅
		users[777] = User{777, "Name"};

		string name = users[777].userName;
		cout << name << "\n";

		// 테이블
		// 키를 알면, 데이터를 단번에 찾을 수 있음
		// 다만, 데이터의 양이 너무 많으면 메모리는 무한이 아니기 때문에 문제가 될 수 있음
	}


	static void TestHash()
	{
		struct User
		{
			int userId = 0;
			string userName;
		};

		vector<User> users;
		users.resize(1000);

		const int userId = 123456789;
		int key = (userId % 1000); // hash (고유 번호 추출)

		// 123456789번 유저 정보 세팅
		users[key] = User{userId, "Name"};

		User& user = users[key];
		if (user.userId == userId)
		{
			string name = user.userName;
			cout << name << "\n";		
		}

		// 키 데이터가 중복이 되면 충돌 문제가 발생할 수 있음
		// 해결 방안으로 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾는다.
		// 선형 조사법 (linear probing)
		// hash(key) + 1 -> hash(key) + 2
		// 이차 조사법 (quadratic probing)
		// hash(key) + 1^2 -> hash(key) + 2^2
		// 그 외에도 다양한 알고리즘이 존재한다.

		// 체이닝
	}

	static void TestHashTableChaining()
	{
		struct User
		{
			int userId = 0;
			string userName;
		};
		vector<vector<User>> users;
		users.resize(1000);

		const int userId = 123456789;
		int key = (userId % 1000); // hash (고유 번호 추출)

		// 123456789번 유저 정보 세팅
		users[key].push_back(User{userId, "Me"});
		users[789].push_back(User{789, "You"});

		vector<User>& bucket = users[789];
		for (User& user : bucket)
		{
			if (user.userId == userId)
			{
				string name = user.userName;
				std::cout << name << "\n";		
			}
		}
	}
};

