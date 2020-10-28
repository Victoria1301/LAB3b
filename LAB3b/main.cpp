#pragma once
#include"Vector.h"
#include <iostream>


int main() {
	Vector A;
	std::cin >> A;
	std::cout << A;
	A.Sort();
	std::cout << A;
	std::cout << A.GetMax();
}