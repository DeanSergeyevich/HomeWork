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
	// m_type тип текущего тетромино,  m_correction_x, m_correction_y коррекция для позиции тетромино.
	int m_type, m_correction_x, m_correction_y;
	// массив, содержащий типы тетромино и их ориентации
	array<array<int, 4>, 7> m_tetratype;
	// массив спрайтов для отображения тетромино
	array<Sprite, 4> m_sprites;
	// массив координат спрайтов тетромино
	array <Point, 4> m_sprites_cords;
	// массив цветов спрайтов тетромино
	array<Color, 4> m_color;
	// метод для вычисления координат спрайтов тетромино
	void spriteCordCalculation(int sprite_index);
public:
	Tetramino(): m_type{0}, m_tetratype{0}, m_sprites{Sprite{}}, m_sprites_cords{0}, m_color{Color::Black}
	{}
	Tetramino(Texture& texture, int correct_x = 0, int correct_y = 0);
	array <Sprite, 4> getSprites() { return m_sprites; } // метод для получения массива спрайтов тетромино
	array <Point, 4> getSpritesCords() { return m_sprites_cords; } // метод для получения массива координат спрайтов тетромино
	void setSpritesCords(array <Point, 4>& arr); // метод для установки новых координат спрайтов тетромино
	void moveRight(); // метод для перемещения тетромино вправо
	void moveLeft(); // влево
	void makeRotation(); // метод для поворота тетромино

};

