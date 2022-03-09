#include <iostream>

// C
struct GameObjectCpp {
	unsigned health;
};

struct PlayerC {
	GameObjectCpp base;
	unsigned magic;
};

//struct EnemyC {
//	GameObjectCpp base;
//	unsigned health;
//};


// C++
struct GameObjectCpp {
	friend void Game(GameObjectCpp& g);

	GameObjectCpp() {
		std::cout << "GameObjectCpp" << std:endl;
	}

	~GameObjectCpp() {
		std::cout << "~GameObjectCpp" << std:endl;
	}

	void shoot() {
		std::cout << "GameObjectCpp" << std::endl;
	}

private:
	unsigned health;

protected:
	int br;
};

//struct PlayerCpp : GameObjectCpp {
//	unsigned magic;
//};

struct EnemyCpp : GameObjectCpp {
	EnemyCpp() {
		br = 1000;
		std::cout << "EnemyCpp" << std:endl;
	}

	~EnemyCpp() {
		std::cout << "~EnemyCpp" << std:endl;
	}

	// перекрытие
	void shoot() {
		std::cout << "EnemyCpp" << std::endl;
	}

private:
	unsigned magic;
};

void Game(GameObjectCpp& g) {
	// g.health = 0; // error 
}


int main() {
	EnemyCpp enemy;
	enemy.shoot();

	GameObjectCpp game_obj;
	game_obj.shoot();


	EnemyCpp enemy;
	// health GameObjectCpp magic EnemyCpp
	// ~EnemyCpp magic ~GameObjectCpp health

	// enemy.health = 100; // error
	return 1;
}

/*
	Наследование. В каком порядке буду конструироваться наши объекты. 
	И так, создание нашего объекта начинается с конструирование его базовой части. 
	Сначала конструируются поля (в private которые). 
	Затем вызывается конструктор базового класса. 
	Затем вызывается конструирование поля (private) которое в классе ниже по иерархии (ребенок), 
	а затем вызывается его же конструктор (производного класса). 
	Разрушается все в обратном порядке.

	Protected. Эту переменную можно использовать внутри в рамках класса, 
	а также в классах унаследованных от родителя.


	Public наследование. Нам говорит, что допустим все как было в производном классе, все так и 
	перенесется. При публичном наследовании ничего не меняется.
	Protected наследование. Все поля и методы, которые объявлены как публичные, 
	становятся protected внутри этого класса.


	Friend. friend void Game(GameObjectCpp& g);
	Теперь в функции Game мы сможем достучаться до private полей. 


	Виртуальное наследование.
*/