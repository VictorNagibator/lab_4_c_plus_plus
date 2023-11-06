#pragma once
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include "RAMType.h"
#include "LaptopComponent.h"

class RAM : public LaptopComponent
{
public:
	RAM() = default;
	RAM(std::string modelName);
	RAM(RAMType type);
	RAM(std::string modelName, RAMType type, float frequency, int capacity);
	~RAM() = default;

	void operator=(RAM other);
	RAM operator+(float addable);
	RAM& operator++();
	RAM operator++(int);
	friend std::ostream& operator << (std::ostream& out, const RAM& ram);

	std::string getComponentName() const override;
	std::string getModelName() const;
	RAMType getRAMType() const;
	float getFrequency() const;
	int getCapacity() const;
	void input() override;
	std::string toString() const override;
private:
	std::string modelName;
	RAMType type = DDR;
	float frequency = 0;
	int capacity = 0;

	//������ ����������� ��������� ������ ��� ������� ���� ������
	const std::vector<int> DDRFreqMax = { 400, 1066, 2400, 3333, 6400 };
	const float tryFreq = 50; //�������� ��������� ������� ��� �������

	bool checkArguments(std::string modelName, RAMType type, float frequency, int capacity) const;
	void tryToSetArguments(std::string modelName, RAMType type, float frequency, int capacity);
};