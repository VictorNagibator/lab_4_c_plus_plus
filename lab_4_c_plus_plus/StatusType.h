#pragma once

enum StatusType { ONHOLD, INPROCCESS, FINISHED };

static std::string StatusTypeToString(StatusType type) {
	std::string result;
	switch (type)
	{
	case ONHOLD:
		result = "� ��������";
		break;
	case INPROCCESS:
		result = "� �������";
		break;
	case FINISHED:
		result = "�����";
		break;
	default:
		break;
	}
	return result;
}

static std::istream& operator >> (std::istream& in, StatusType& status) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		status = ONHOLD;
		break;
	case 1:
		status = INPROCCESS;
		break;
	case 2:
		status = FINISHED;
		break;
	default:
		break;
	}
	return in;
};
static std::ostream& operator << (std::ostream& out, StatusType& status) {
	out << StatusTypeToString(status);
	return out;
};