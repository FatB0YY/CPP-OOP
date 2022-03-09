#include <iostream>

//struct Data {
//	void print() {
//		// code
//	}
//};

struct Data {
	static void print() {
		// code
	}

	static inline int m_value = 0;
};

int main() {
	//Data data1;
	//data1.print();

	Data::print();
	Data::m_value = 1000;

	Data data1;
	data1.m_value = 200;

	Data data2;
	data2.m_value = 300;



	return 1;
}

/*
	Static. ���� ��� ������� �������, �� �� �� ������ ����� �������. 
	�� ���� �� �������� ��� static, �� ������ �� ����� ����� �������� ::. 
	����� ������ static �������, ��� ����� ��� ����, �� ������ �� ����������� ������ ���� ������� (��������), 
	�� ����� ����� ��� ���� ��������, ��������� �� ����� ������.
*/