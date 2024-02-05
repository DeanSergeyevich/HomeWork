#include <iostream>


using namespace std;


class ValuteConvert
{
private:
   double RubtoUsd;
   double RubtoEur;

public:
    ValuteConvert(double usdRate, double eurRate) : RubtoUsd(usdRate), RubtoEur(eurRate){}

    double convertRubToUsd(double rubAmount) const
    {
        return rubAmount / RubtoUsd;
    }

    double convertRubToEur(double rubAmount) const
    {
        return rubAmount / RubtoEur;
    }

    double convertUsdToRub(double usdAmount) const
    {
        return usdAmount * RubtoUsd;
    }

    double convertEurToRub(double eurAmount) const
    {
        return eurAmount * RubtoEur;
    }

    void setUsdRate(double newRate)
    {
        RubtoEur = newRate;
    }

    void setEurRate(double newRate)
    {
        RubtoEur = newRate;
    }

};

int main()
{
    setlocale(LC_ALL, "ru");
    
    ValuteConvert converter(73.0, 87.0);

    double amountInRub = 1000.0;
    cout << amountInRub << "руб. составляет примерно " << converter.convertRubToUsd(amountInRub) << "Доллар.\n";

    converter.setUsdRate(75.0);

    cout << amountInRub << "руб. составляет примерно " << converter.convertRubToEur(amountInRub) << " Евро.\n";

    converter.setEurRate(85.0);


    return 0;
}


