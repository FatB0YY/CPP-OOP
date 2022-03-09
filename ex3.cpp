#include <iostream>
#include <vector>
#include <string>
#include <exception>

// C
typedef struct vector_3d_t {
	int x;
	int y;
	int z;
};

void vector_add(vector_3d_t& lhs, const vector_3d_t& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.z;
	lhs.z += rhs.z;
}


// C++
class Vector3D {
public:
	// ���������
	Vector3D& operator += (const Vector3D& other) {
		x += other.x;
		y += other.z;
		z += other.z;
		return *this;
	}

	// �� ���������
	Vector3D operator + (const Vector3D lhs, const Vector3D rhs);
private:
	int x;
	int y;
	int z;
};

// �� ���������
Vector3D operator + (const Vector3D lhs, const Vector3D rhs) {
	Vector3D vec;
	vec.x = lhs.x + rhs.x;
	vec.y = lhs.y + rhs.z;
	vec.z = lhs.z + rhs.z;
	return vec;
}


int main() {
	vector_3d_t lhs{};
	vector_3d_t rhs{};
	vector_add(lhs, rhs);

	Vector3D vec1;
	Vector3D vec2;
	vec1 += vec2;

	return EXIT_SUCCESS;
}

/*
	���������� ����������. 
	�� ����� ��������� �������������� �������� � ���������������� �����. 
	����� ���������� ����� ������� �����. 
	���� �������� ���� ������, �� �� ������ ���� ���������. 
	���� ��� ���������, �� ��� ����� ������ ��� �����. 
*/