#pragma once
#include "Vector.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>

Vector::Vector(int i) {
	this->i = 0;
	for (int l = 0; l < this->SZ; l++)
		this->Elem[l] = 0;
}
Vector::Vector(int E, int i) {
	this->i = i;
	this->Elem[0] = E;
}

Vector::Vector(int i, int* E) {
	this->i = 0;
	for (int l = 0; l < i; l++) {
		SetVector(E[l]);
	}
}

const Vector Vector::operator +(const int E) const {
	Vector New;
	for (int i = 0; this->i; i++)
		New.Elem[i] = this->Elem[i];
	New.i += this->i;
	New.Elem[i + 1] = E;
	New.i++;
	return New;
}

const Vector Vector::operator +(const Vector& E) const {
	Vector New;

	for (int i = 0; i < this->i; i++)
		New.Elem[i] = this->Elem[i];
	New.i += this->i;

	int i = 0;
	for (int l = this->i; l < this->i + E.i; l++) {
		New.Elem[l] = E.Elem[i];
		i++;
	}
	New.i += E.i;

	return New;
}

std::ostream& operator <<(std::ostream& c, const Vector& r) {
	c << "{";
	for (int l = 0; l < r.i; l++)
		if (l != r.i - 1)
			c << r.Elem[l] << ",";
		else c << r.Elem[l];
	c << "}" << std::endl << std::endl;
	return c;
}

std::istream& operator >> (std::istream& c, Vector& r) {
	int i;
	int E;
	c >> i;
	if (!c.good())
		c.setstate(std::ios::failbit);
	else {
		for (int l = 0; l < i; l++) {
			c >> E;
			if (!c.good())
				c.setstate(std::ios::failbit);
			else {
				r.Elem[l] = E;
			}
		}
		r.i = i;
	}
	return c;
}

const int Vector::operator [](int w) const {
	if (w < 0 || w >= this->SZ)
		throw std::exception("illegal index");
	return this->Elem[w];
}

void Vector::SetVector(const int E) {
	this->Elem[this->i] = E;
	this->i++;
}


void Vector::GetVectorI(int l, int i) {
	if (this->i < i)
		std::cout << "Too much" << std::endl;
	else {
		std::cout << "{";
		for (i; i < this->i || i < l; i++) {
			if (i != this->i - 1)
				std::cout << this->Elem[i] << ",";
			else std::cout << this->Elem[i];
		}
		std::cout << "}" << std::endl << std::endl;
	}
}

void Vector::Sort() {
	int temp;
	for (int i = 0; i < this->i; i++) {
		for (int j = 0; j < this->i - 1; j++) {
			if (this->Elem[j] > this->Elem[j + 1]) {
				temp = this->Elem[j];
				this->Elem[j] = this->Elem[j + 1];
				this->Elem[j + 1] = temp;
			}
		}
	}
}

int Vector::GetMax() {
	double res = this->Elem[0];
	int i;
	for (i = 0; i < this->i; ++i)
		if (isgreater(this->Elem[i], res) > 0)
			res = this->Elem[i];
	return res;
}

