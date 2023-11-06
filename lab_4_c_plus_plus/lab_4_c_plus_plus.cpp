#include <iostream>
#include <windows.h>
#include "Laptop.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Laptop test = Laptop();
	test.setDataStorage(new SSD());
	std::cout << test << std::endl;
	test.boostCPU(9.0);
	test.boostRAM(5400);
	std::cout << test << std::endl;
}