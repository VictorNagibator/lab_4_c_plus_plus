#include <iostream>
#include <windows.h>
#include <vector>
#include "Order.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//1. Пример работы со статическим методом
	for (int i = 0; i < 5; i++)
	{
		Order test = Order(Laptop());
	}
	std::cout << "Общее количество заказов: " << Order::getNumOfLastOrder() << std::endl << std::endl;

	//2. Возврат значения через указатель и ссылку
	Laptop example = Laptop();
	DataStorage* storage = example.getDataStorage();
	const CPU& cpu = example.getCPU();
	std::cout << storage->toString() << std::endl;
	std::cout << cpu << std::endl << std::endl;

	//3. Перегрузка оператора +,++
	RAM ram = RAM();
	std::cout << ram++ << std::endl;
	std::cout << ++ram << std::endl;
	RAM ram2 = ram + 100;
	std::cout << ram2 << std::endl << std::endl;

	//4. Работа с классом std::string
	std::string str = cpu.toString();
	std::cout << str << std::endl;
	str += " example"; //конкатенация строк 
	std::cout << str << std::endl;
	std::cout << str.find("0") << std::endl; //найти первый 0
	str.erase(str.find("0")); //удалить подстроку
	std::cout << str << std::endl;

	return 0;
}