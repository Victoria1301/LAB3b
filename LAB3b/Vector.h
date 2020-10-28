#pragma once
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

class Vector {
public:
	Vector(int i = 0);
	Vector(int E, int i);
	Vector(int i, int* E);
	void SetVector(const int E);
	void GetVectorI(int l, int i);
	void Sort();
	int GetMax();
	const Vector operator +(const int E) const;
	const Vector operator +(const Vector& E) const;
	friend std::ostream& operator << (std::ostream&, const Vector&);
	friend std::istream& operator >> (std::istream&, Vector&);
	const int operator [](int w) const;

private:

	static const int SZ = 20;
	int i;
	int Elem[SZ];
};

