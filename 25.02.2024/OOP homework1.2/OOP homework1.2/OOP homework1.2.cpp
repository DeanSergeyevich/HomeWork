#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    static int count; 
    char* buffer; 
    size_t length; 

public:
   
    String() : String(80) {}

    
    explicit String(size_t size) {
        buffer = new char[size + 1]; // +1 для символа завершения строки
        length = size;
        ++count; // Увеличиваем счетчик созданных объектов
    }

   
    String(const char* str) {
        length = strlen(str);
        buffer = new char[length + 1];
        strcpy_s(buffer, length + 1, str);
        ++count; // Увеличиваем счетчик созданных объектов
    }
    
    ~String() {
        delete[] buffer;
        --count; // Уменьшаем счетчик созданных объектов при удалении объекта
    }

   
    void input() {
        std::cout << "Введите строку: ";
        std::cin.getline(buffer, length + 1);
    }

    
    void display() const {
        std::cout << "Строка: " << buffer << std::endl;
    }

   
    static int getCount() {
        return count;
    }
};


int String::count = 0;



int main()
{
    setlocale(LC_ALL, "ru");

    String str1; // Строка длиной 80 символов
    String str2(100); // Строка длиной 100 символов
    String str3("Hello, World!"); // Строка, инициализированная строкой от пользователя

    // Выводим созданные строки
    str1.display();
    str2.display();
    str3.display();

    // Вводим строку для третьего объекта
    str3.input();
    str3.display();

    // Выводим количество созданных объектов
    std::cout << "Количество созданных объектов: " << String::getCount() << std::endl;
}


