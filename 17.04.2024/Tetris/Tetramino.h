#pragma once
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

struct Point
{
	int x, y;
};



class Tetramino
{
private:
	// m_type ��� �������� ���������,  m_correction_x, m_correction_y ��������� ��� ������� ���������.
	int m_type, m_correction_x, m_correction_y;
	// ������, ���������� ���� ��������� � �� ����������
	array<array<int, 4>, 7> m_tetratype;
	// ������ �������� ��� ����������� ���������
	array<Sprite, 4> m_sprites;
	// ������ ��������� �������� ���������
	array <Point, 4> m_sprites_cords;
	// ������ ������ �������� ���������
	array<Color, 4> m_color;
	// ����� ��� ���������� ��������� �������� ���������
	void spriteCordCalculation(int sprite_index);
public:
	Tetramino(): m_type{0}, m_tetratype{0}, m_sprites{Sprite{}}, m_sprites_cords{0}, m_color{Color::Black}
	{}
	Tetramino(Texture& texture, int correct_x = 0, int correct_y = 0);
	array <Sprite, 4> getSprites() { return m_sprites; } // ����� ��� ��������� ������� �������� ���������
	array <Point, 4> getSpritesCords() { return m_sprites_cords; } // ����� ��� ��������� ������� ��������� �������� ���������
	void setSpritesCords(array <Point, 4>& arr); // ����� ��� ��������� ����� ��������� �������� ���������
	void moveRight(); // ����� ��� ����������� ��������� ������
	void moveLeft(); // �����
	void makeRotation(); // ����� ��� �������� ���������

};

