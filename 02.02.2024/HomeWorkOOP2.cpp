#include <iostream>
#include <string>
#include <random>

using namespace std;

class Car
{
private:
    static int idGenerator;
    int uniqId;
    string color;
    string model;
    float price;
public:

    Car()
    {
        uniqId = ++idGenerator;
        cout << "car created with ID: " << uniqId << endl;
    }
    Car(string color, string model)
    {
        this->color = color;
        this->model = model;

    }
    Car(string color, string model, float price) : Car(color, model)
    {
        this->price = price;
    }



    void setColor(string color)
    {
        this->color = color;
    }
    void setModel(string model)
    {
        this->model = model;
    }
    void setPrice(float price)
    {
        this->price = price;
    }
    float getPrice()
    {
        return price;
    }
    string getColor()
    {
        return color;
    }
    string toString()
    {
        return "color: " + color + "\n model: " + model + " \n price: " + to_string(price);
    }

    int getUniqueId() const
    {
        return uniqId;
    }

};

Car getMinPriceCar(Car& car1, Car& car2)
{
    if (car1.getPrice() < car2.getPrice())
        return car1;
    else
        return car2;
}

void changeColor(Car& car)
{
    car.setColor("gold");
}

Car& createCopy(Car car)
{
    Car copyCar = car;
    return car;

}

int Car::idGenerator = 0;

class Garage : Car
{
private:
    Car* cars = nullptr;
    int countCars = 0;
public:
    Garage(){}

    ~Garage()
    {
        delete[] cars; 
    }

    void addCar(const Car& newCar)
    {
        if(countCars == 5)
        {
            cout << "Превышен допустимый предел количества машин в гараже" << endl;
            return;
        }
        Car* buf = new Car[countCars + 1];
        std::copy(cars, cars + countCars, buf);
        buf[countCars] = newCar;
        countCars++;

        delete[] cars;
        cars = buf;
    }

    void removeCar(const string& colorToRemove)
    {
        if(countCars == 0)
        {
            return;
        }
        int indexToRemove = -1;
        for (int i = 0; i < countCars; i++)
        {
            if(cars[i].getColor() == colorToRemove)
            {
                indexToRemove = i;
                break;
            }
        }

        if(indexToRemove == -1)
        {
            cout << "Машина с цветом " << colorToRemove << " не найдена в гараже " << endl;
            return;
        }
        Car* buf = new Car[countCars - 1];
        std::copy(cars, cars + indexToRemove, buf);

        std::copy(cars + indexToRemove + 1, cars + countCars, buf + indexToRemove);

        countCars--;

        delete[] cars;

        cars = buf;
    }
    int getCountCars() const
    {
        return countCars;
    }

    Car getCar(int index) const
    {
        
        return cars[index];
    }
};




int main()
{
    setlocale(LC_ALL, "ru");


    Car car1("Black", "lada");
    cout << car1.toString() << endl;
    cout << "Car 1 ID: " << car1.getUniqueId() << endl;

    Car car2("silver", "audi", 3000);
    cout << getMinPriceCar(car1, car2).toString() << endl;
    cout << "Car 2 ID: " << car2.getUniqueId() << endl;

    changeColor(car1);
    cout << car1.toString() << endl;

    Car car3 = createCopy(car2);
    cout << "Копия car2: " << car3.toString() << endl;

    Garage myGarage;

    myGarage.addCar(car1);
    myGarage.addCar(car2);

    cout << "Машины в гараже до удаления:" << endl;
    for (int i = 0; i < myGarage.getCountCars(); i++)
    {
        cout << "Car " << i + 1 << ":" << endl;
        cout << myGarage.getCar(i).toString() << endl;
    }

    // Удаляем машину с заданным цветом
    myGarage.removeCar("Black");

    // Выводим машины в гараже после удаления
    cout << "Машины в гараже после удаления:" << endl;
    for (int i = 0; i < myGarage.getCountCars(); i++)
    {
        cout << "Car " << i + 1 << ":" << endl;
        cout << myGarage.getCar(i).toString() << endl;
    }

    return 0;
}


