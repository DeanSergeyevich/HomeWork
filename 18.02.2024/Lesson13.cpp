#include <iostream>
#include "Product.h"
#include "Shop.h"
#include "Items.h"
#include "List.h"
#include "Journal.h"
using namespace std;








int main()
{
    setlocale(LC_ALL, "ru");
   
   /* Product product1("banana", 120);
    cout << "Продукт" << product1.getName() << ", Цена:" << ":" << product1.getPrice();

    cout << endl;

    Shop shop("5-ka");
    shop.buyProduct(product1);
    cout << "Информация о магазине:" << endl;
    shop.showInfo();
    shop.sellProduct(0)->showInfo();
    shop.showInfo();*/

    List list1;
    list1.addItems(Item("qwerty", "12.03.24"));
    list1.addItems(Item("qwt", "12.04.24"));
    list1.addItems(Item("qwerty19", "12.05.24"));
    list1.addItems(Item("qwerty20", "12.06.24"));
    


    List list2;
    list2.addItems(Item("qwerty13", "12.03.24"));
    list2.addItems(Item("qwt20", "12.04.24"));
   
    
    Journal journal;
    journal.addList(list1);
    journal.addList(list2);

    journal.showInfo();

    journal.showList(1);

    return 0;
}

