#include <iostream>

using namespace std;

class Fraction
{
private:
    int num;
    int denum;
public:
    Fraction(int num, int denum)
    {
        this->num = num;
        this->denum = denum;
    }

    void show()
    {
            cout  << num << "/" << denum << endl;
    }

    Fraction add(const Fraction& other)
    {
        int new_num = num * other.denum + other.num * denum;
        int new_denum = denum * other.denum;
        return Fraction(new_num, new_denum);
    }

    Fraction subtract(const Fraction& other)
    {
        int new_num = num * other.denum - other.num * denum;
        int new_denum = denum * other.denum;
        return Fraction(new_num, new_denum);
    }

    Fraction multiply(const Fraction& other)
    {
        int new_num = num * other.num;
        int new_denum = denum * other.denum;
        return Fraction(new_num, new_denum);
    }

    Fraction divide(const Fraction& other)
    {
        int new_num = num * other.denum;
        int new_denum = denum * other.num;
        return Fraction(new_num, new_denum);
    }
};



int main()
{
    setlocale(LC_ALL, "ru");
    
    Fraction num1(3, 6);
    Fraction num2(23, 10);
    num1.show();
    num2.show();

    Fraction sum = num1.add(num2);
    Fraction difference = num1.subtract(num2);
    Fraction product = num1.multiply(num2);
    Fraction quotient = num1.divide(num2);

    cout << "Сумма: ";
    sum.show();
    cout << "Разность: ";
    difference.show();
    cout << "Произведение: ";
    product.show();
    cout << "Частное: ";
    quotient.show();

    return 0;
}


