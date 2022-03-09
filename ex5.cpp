#include <iostream>
#include <vector>
#include <string>
#include <exception>

// C++
struct Data {
	Data() : m_data(new int{}) {}
	~Data() {
		delete m_data;
	}

	// correct
	Data(const Data& other) : m_data(new int{*other.m_data}) {

	}

	Data& operator = (const Data& other) {
		if (this != &other) {
			delete m_data;
			m_data(new int{ *other.m_data });
		}
		return *this;
	}
public:
	int* m_data;
};

int main() {
	Data data1;
	// data1 = data1;
	Data data2 = data1;

	

	return EXIT_SUCCESS;
}


/*
	��� �����������, ����������� ��� ���������. 
	������ ��������� �� data1 � data2 ��������� �� ���� � ��� �� ���� ������ ������ ����. 
	�������������� ����� ����� ��������� data2, ��������� delete ��� ����� ����� � data1 ����� ��������� � ��������� ��������� delete. 
	Double delete = undefined behaviour. 


	� C++ ��������� ������������ � ��������� �����������. ��� ������ ��� ��������.
	������ �� �� ������ �������� ���������, �� �������� �������� ���� ����������. 
	������ ��� ��������� ����� ���������� �� ������ ����� ������.


	������� 3. ��� ������ ��� ����� �������� ��� �� ���� (���� ����������� �����������, ���� �������� �����������, ���� ����������), �� ������, 
	��� ��� ����� ����������� ��� ���������, �� �� ��� �� ����� ��������� ������ ��������� (��� ���������� ������� 3�, ��������� �� c++ 11, 
	����� ������� 5 � ���������, �� ����������� ����������� ����������� � �������� �����������).


	������� ����. ���� �� ���������� �����, ������� ������ ���� ��� ������������� ������� 3 ��� 5, �� �� �� ����� ������ ������, ��� ����� ��������� ��������. 
	����� �������� ��� ������������.
*/

