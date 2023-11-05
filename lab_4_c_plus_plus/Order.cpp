#include "Order.h"

std::ostream& operator << (std::ostream& out, Order& order) {
	out << order.toString();
	return out;
}

Order::Order(Laptop laptop) {
	numOfOrder = ++numOfLastOrder;
	this->laptop = laptop;
}

Order::Order(Laptop laptop, StatusType status) : Order(laptop) {
	tryToSetArguments(status);
}

int Order::getNumOfLastOrder() {
	return numOfLastOrder;
}

int Order::getNumOfOrder() const {
	return numOfOrder;
}

const Laptop& Order::getLaptop() const {
	return laptop;
}

StatusType Order::getStatus() const {
	return status;
}

void Order::input() {
	StatusType type;
	numOfLastOrder++;

	std::cout << "����� ������: " << numOfLastOrder;
	std::cout << "������� ������ ������ (0 - � ��������, 1 - � �������, 2 - ��������������): ";
	std::cin >> type;
	std::cout << "\t���� ���������� ��������\n";
	this->laptop.input();

	this->numOfOrder = numOfLastOrder;
	this->laptop = laptop;
	tryToSetArguments(type);
}

void Order::setStatus(StatusType status) {
	if (checkArguments(status)) {
		this->status = status;
		std::cout << "��������� ������ ������� ��������!\n";
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

void Order::setLaptop(Laptop laptop) {
	this->laptop = laptop;
}

std::string Order::toString() const {
	std::string name = std::to_string(this->getNumOfOrder()) + ". " + this->laptop.getModelName() + "\t" + StatusTypeToString(this->getStatus());
	return name;
}


bool Order::checkArguments(StatusType status) const {
	return status >= ONHOLD && status <= FINISHED;
}

void Order::tryToSetArguments(StatusType status) {
	if (checkArguments(status)) {
		this->status = status;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}