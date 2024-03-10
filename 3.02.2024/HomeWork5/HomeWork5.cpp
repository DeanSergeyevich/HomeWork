#include <iostream>
#include <string>


using namespace std;

class Drob
{
    int num;
    int denum;
public:
    Drob(int num, int denum)
    {
        this->num = num;
        this->denum = denum;
    }

    Drob mult(Drob & drob)
    {
        int newNum = this->num * drob.num;
        int newDenum = this->denum * drob.denum;
        Drob newDrob(newNum, newDenum);
        return newDrob;
    }

    Drob operator *(Drob & drob)
    {
        int newNum = this->num * drob.num;
        int newDenum = this->denum * drob.denum;
        Drob newDrob(newNum, newDenum);
        return newDrob;
    }

    void show()
    {
        cout << num << " / ";
    }
};


int main()
{
    Drob d1(2, 3);
    Drob d2(4, 2);
    Drob d3 = d1.mult(d2);
    Drob d4 = d1 * d2;

    d1.show();
    d2.show();
    d3.show();
    d4.show();
}


