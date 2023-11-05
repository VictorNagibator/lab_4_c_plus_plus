#pragma once
#include <iostream>
#include <string>
#include <format>
#include "LaptopComponent.h"

class CPU : public LaptopComponent
{
public:
	CPU() = default;
	CPU(std::string modelName);
	CPU(std::string modelName, std::string socket, float frequency, int numOfCores);
	~CPU() = default;

	void operator=(CPU other);
	friend std::ostream& operator << (std::ostream& out, const CPU& cpu);

	std::string getComponentName() const override;
	std::string getModelName() const;
	std::string getSocket() const;
	float getFrequency() const;
	int getNumOfCores() const;
	void input() override;
	std::string toString() const override;

	const float maxFreq = 9.0; //условная максимальная тактовая частота для процессора
	const double tryFreq = 0.2; //условное повышение частоты для разгона
private:
	std::string modelName;
	std::string socket;
	float frequency = 0;
	int numOfCores = 0;

	bool checkArguments(std::string modelName, std::string socket, float frequency, int numOfCores) const;
	void tryToSetArguments(std::string modelName, std::string socket, float frequency, int numOfCores);
};