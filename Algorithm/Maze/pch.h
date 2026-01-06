#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;
using uint8		= unsigned __int8;
using uint16	= unsigned __int16;
using uint32	= unsigned __int32;
using uint64	= unsigned __int64;

struct Pos
{
	bool operator==(Pos& other)
	{
		return y == other.y && x == other.x;
	}
	bool operator!=(Pos& other)
	{
		return !(*this == other);
	}

	bool operator<(const Pos& other) const
	{
		if (y != other.y) return y < other.y;
		return x < other.x;
	}

	Pos operator+(Pos& other)
	{
		Pos ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}
	Pos& operator +=(Pos& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	int32 x = 0;
	int32 y = 0;
};

enum Dir
{
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4,
};