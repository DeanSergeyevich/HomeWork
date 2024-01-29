#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    float price;
    string color;
    string model;
    float engine_capacity;

public:
    Car(float price, const string& color, const string& model, float engine_capacity)
        : price(price), color(color), model(model), engine_capacity(engine_capacity) {}

    void setPrice(float price)
    {
        this->price = price;
    }

    void setColor(const string& color)
    {
        this->color = color;
    }

    void setModel(const string& model)
    {
        this->model = model;
    }

    void setEngineCapacity(float engine_capacity)
    {
        this->engine_capacity = engine_capacity;
    }

    float getPrice() const
    {
        return price;
    }

    const string& getColor() const
    {
        return color;
    }

    const string& getModel() const
    {
        return model;
    }

    float getEngineCapacity() const
    {
        return engine_capacity;
    }

    void show() const
    {
        cout << "Информация о машине:\n";
        cout << "Цена: " << getPrice() << endl;
        cout << "Цвет: " << getColor() << endl;
        cout << "Модель: " << getModel() << endl;
        cout << "Объём Двигателя: " << getEngineCapacity() << endl;
    }
};

int main()
{
   
     setlocale(LC_ALL, "ru");

     
     Car car1(25000.0, "Чёрная", "Шевроле Импала", 2.5);
     Car car2(30000.0, "Синий", "SUV", 3.0);
     Car car3(20000.0, "Красная", "Toyota Camry", 2.0);
     Car car4(35000.0, "Белая", "Jeep Grand Cherokee", 3.6);

     
     cout << "Машина 1:\n";
     car1.show();

     cout << "\nМашина 2:\n";
     car2.show();

     cout << "\nМашина 3:\n";
     car3.show();

     cout << "\nМашина 4:\n";
     car4.show();

    return 0;
}
