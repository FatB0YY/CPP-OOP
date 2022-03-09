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

	// ����������
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
	������������. � ����� ������� ���� ���������������� ���� �������. 
	� ���, �������� ������ ������� ���������� � ��������������� ��� ������� �����. 
	������� �������������� ���� (� private �������). 
	����� ���������� ����������� �������� ������. 
	����� ���������� ��������������� ���� (private) ������� � ������ ���� �� �������� (�������), 
	� ����� ���������� ��� �� ����������� (������������ ������). 
	����������� ��� � �������� �������.

	Protected. ��� ���������� ����� ������������ ������ � ������ ������, 
	� ����� � ������� �������������� �� ��������.


	Public ������������. ��� �������, ��� �������� ��� ��� ���� � ����������� ������, ��� ��� � 
	�����������. ��� ��������� ������������ ������ �� ��������.
	Protected ������������. ��� ���� � ������, ������� ��������� ��� ���������, 
	���������� protected ������ ����� ������.


	Friend. friend void Game(GameObjectCpp& g);
	������ � ������� Game �� ������ ����������� �� private �����. 


	����������� ������������.
*/