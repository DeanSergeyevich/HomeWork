#include <iostream>
#include "SFML/Graphics.hpp"
#include "Tetramino.h"
#include <time.h>



using namespace sf;
using namespace std;




const int Y = 21; // высота игрового поля
const int X = 10; // ширина игрового поля

array <array <bool, Y>, X> is_field_sprite{ false }; // игровое поле (true - ячейка занята, false - свободна)
array <array <Sprite, Y>, X> field_sprites; // спрайты игрового поля, которые уже установлены

void fEvents(RenderWindow& window, Tetramino& tetramino, float& delay);
void fCheck_field(Tetramino& tetramino, array<Point, 4>& good_points);
bool fGoDown(Tetramino& tetramino, float& timer, float& delay, Clock& clock);
void fSearchAndDelLines();
void fDeleteLine(int line);
bool fIsGameOver(Tetramino& tetramino);
void fPrintText(string text, Font& font, RenderWindow& window);

int main()
{

    // Настраиваем сглаживание 
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    // Настраиваем основное окно
    RenderWindow window(VideoMode(320, 480), "The Tetris!", Style::Default, settings);
    // Создаем переменную для текстуры спрайта и загружаем текстуру
    Texture texture_cube, texture_background, texture_frame;
    // Путь к текстуре
    texture_cube.loadFromFile("E:\\VisualCodes\\Tetris\\SFML_images\\tiles.png");
    texture_background.loadFromFile("E:\\VisualCodes\\Tetris\\SFML_images\\background.png");
    texture_frame.loadFromFile("E:\\VisualCodes\\Tetris\\SFML_images\\frame.png");

    // Создадим спрайт для рамки
    Sprite frame(texture_frame);
    Sprite background(texture_background);

    Font font;
    font.loadFromFile("E:\\VisualCodes\\Tetris\\SFML_images\\ALGER.TTF");

    // Создаем новую тетрамино?
    bool new_tetramino = true;
    // Игра окончена?
    bool game_over = false;
    // Переменная которая хранит всю информацию по тетрамино
    Tetramino tetramino;
    // Переменная, которая хранит временные координаты тетрамино
    array <Point, 4> good_points;
    // Переменная таймера, задержки и часы
    float timer = 0, delay = 0.3f;
    Clock clock;
    
    // Главный цикл приложения: выполняется, пока открыто окно
    while(window.isOpen())
    {
        window.clear(Color::White);
        window.draw(background);
        window.draw(frame);
        // Если нужна новая тетрамино, то создаем ее
        if(new_tetramino && !game_over)
        {
            tetramino = Tetramino(texture_cube, 28, 31);
            new_tetramino = false;

            // Проверим не закончилась ли игра
            if (fIsGameOver(tetramino))
                game_over = true;
        }

        // движение тетрамино вниз, если достигли конца поля, то создаем новую
        if (!fGoDown(tetramino, timer, delay, clock))
            new_tetramino = true;

        // Проверяем границы поля
        fCheck_field(tetramino, good_points);

        // Поиск и удаление собранных линий
        fSearchAndDelLines();
        array<Sprite, 4> temp_sprites{ tetramino.getSprites() };
        for (int i = 0; i < temp_sprites.size(); i++)
            window.draw(temp_sprites.at(i));

        // Отрисовка поля
        for (int x = 0; x < field_sprites.size(); x++)
            for (int y = 0; y < field_sprites.at(x).size(); y++)
                window.draw(field_sprites.at(x).at(y));

        // Обрабатываем события в цикле
        fEvents(window, tetramino, delay);

        // Если игра закончилась, то выводим текст
        if (game_over)
            fPrintText("Game Over!", font, window);

        window.display();
    }
    return 0;


   
}

// функция обработки событий
void fEvents(RenderWindow& window, Tetramino& tetramino, float& delay)
{
    Event event;
    while(window.pollEvent(event))
    {
        // Пользователь нажал на "Крестик" и хочет закрыть окно?
        if (event.type == Event::Closed)
            // тогда закрываем его
            window.close();
        if(event.type == Event::KeyPressed)
            if(event.key.code == Keyboard::Right)
            {
                tetramino.moveRight();
            }
            else if(event.key.code == Keyboard::Left)
            {
                tetramino.moveLeft();
            }
            else if (event.key.code == Keyboard::Up)
            {
                tetramino.makeRotation();
            }
            else if (event.key.code == Keyboard::Down)
            {
                delay = 0.05f;
            }
    }
}

// Функция проверки координат поля 
void fCheck_field(Tetramino& tetramino, array<Point, 4>& good_points)
{
    // Записываем текущие координаты тетрамино во временную переменную
    array <Point, 4> temp = tetramino.getSpritesCords();
    // Проверяем выходит ли хоть один спрайт за границы поля и не занимает ли он ячейки других спрайтов?
    int count = 0;
    for(int i = 0; i<good_points.size(); i++)
    {
        if (temp.at(i).x < X && temp.at(i).x >= 0 && temp.at(i).y < Y - 1 && temp.at(i).y >= 0 &&
            is_field_sprite.at(temp.at(i).x).at(temp.at(i).y + 1) == false)
            count++;
        else
            break;
    }
    // Если не выходит, то текущие координаты "хорошие", сохраняем их
    if(count == 4)
    {
        good_points = temp;
    }
    // Если не выходит, то установим тетрамино "хорошие" координтаы
    else 
        tetramino.setSpritesCords(good_points);
}

/* Функция для движения тетрамино вниз, возвращает true когда движение происходит и false
если дошли до конца поля по вертикали */
bool fGoDown(Tetramino& tetramino, float& timer, float& delay, Clock& clock)
{
    bool result = true;
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    array <Point, 4> sprites_cords = tetramino.getSpritesCords();
    if(timer > delay)
    {
        for (int i = 0; i < sprites_cords.size(); i++)
        {
            sprites_cords.at(i).y += 1;
            if(sprites_cords.at(i).y == Y - 1 ||
                (sprites_cords.at(i).y > 0 && 
                    (sprites_cords.at(i).y > 0 && is_field_sprite.at(sprites_cords.at(i).x).at(sprites_cords.at(i).y + 1))))
            {
                delay = 0.3f;
                result = false;
            }
        }
        if(!result)
            for(int i = 0; i< sprites_cords.size(); i++)
            {
                is_field_sprite.at(sprites_cords.at(i).x).at(sprites_cords.at(i).y) = true;
                field_sprites.at(sprites_cords.at(i).x).at(sprites_cords.at(i).y) = tetramino.getSprites().at(i);
            }
        tetramino.setSpritesCords(sprites_cords);
        timer = 0;
    }
    return result;
}

// функция поиска и удаления собранных линий
void fSearchAndDelLines()
{
    for(int y = 1; y<is_field_sprite.at(0).size(); y++)
    {
        int count = 0;
        for (int x = 0; x < is_field_sprite.size(); x++)
        {
            if (!is_field_sprite.at(x).at(y))
                break;
            else
                count++;
        }
        if (count == is_field_sprite.size())
            fDeleteLine(y);
    }
}
// Функция удаления линии
void fDeleteLine(int line)
{
    for(int y = line; y > 0; y--)
        for(int x = 0; x < is_field_sprite.size(); x++)
        {
            is_field_sprite.at(x).at(y) = is_field_sprite.at(x).at(y - 1);
            field_sprites.at(x).at(y) = field_sprites.at(x).at(y - 1);
            field_sprites.at(x).at(y).move(0, 18);
        }
}

// Проверяем не закончилась ли игра
bool fIsGameOver(Tetramino& tetramino)
{
    array<Point, 4> temp = tetramino.getSpritesCords();
    for(int i = 0; i< temp.size(); i++)
    {
        if (is_field_sprite.at(temp.at(i).x).at(temp.at(i).y))
            return true;
    }
    return false;
}

// Функция для вывода текста на окно SFML
void fPrintText(string text, Font& font, RenderWindow& window)
{
    Text stext(text, font, 40); // создаем текст, размер шрифта - 40
    stext.setStyle(Text::Bold | Text::Underlined); // стиль жирный и подчеркнутый
    stext.setFillColor(Color::Red); // цвет красный
    stext.setPosition(X * 1, Y * 9);
    window.draw(stext);
}

    