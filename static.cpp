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
	Static. Если это обычная функция, то мы ее просто можем вызвать. 
	Но если ее пометить как static, то теперь ее нужно будет вызывать ::. 
	Грубо говоря static говорит, что метод или поле, он теперь не принадлежит какому либо объекту (инстансу), 
	он будет общий для всех объектов, созданных от этого класса.
*/