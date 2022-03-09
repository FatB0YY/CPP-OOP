#include <iostream>

// C
typedef struct super_base_t {
	int super_base_data;
};

typedef struct base_1_t {
super_base_t: super_base;

	int base_1_data;
};

typedef struct base_2_t {
super_base_t: super_base;

	int base_2_data;
};


typedef struct derived_t {
base_1_t: base_1;
base_2_t: base_2;
	int derived;
};



// C++
struct SuperBase {
	int super_base_data;
};

struct Base1 : virtual SuperBase {
	int base_1_data;
};

struct Base2 : virtual SuperBase {
	int base_2_data;
};

struct Derived : Base1, Base2 {
	int derived;
};

int main() {
	// c++
	Derived derived;
	// derived.super_base_data = 100; // error
	// derived.Base1::super_base_data = 100;
	// derived.Base2::super_base_data = 100;

	// virtual
	derived.super_base_data = 100;
	derived.super_base_data = 100;


	// c
	derived_t derived_c;
	//derived_c.base_1.super_base.super_base_data = 200;
	//derived_c.base_2.super_base.super_base_data = 200;

	return 1;
}

/*
	Виртуальное наследование. Проблемы: дублируется информация, 
	у базового класса будет дважды вызываться конструктор и деструктор (разные объекты). 
	Как будет выглядеть в памяти: 
		super_base_data
		base_1_data 
		super_base_data
		base_2_data 
		derived

	Добавляем virtual, как в памяти:
	void* vbpt = 0xAABB;
	base_1_data
	void* vbpt = 0xAABB;
	base_2_data
	derived
	super_base_data[0xAABB]

	У нас получается один экземпляр. Не будет два инстанса.
*/