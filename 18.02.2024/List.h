#pragma once
#include <iostream>
#include "Items.h"

using namespace std;

class List
{
private:
	int countItems = 0;
	Item** items;
public:
	int getIndexItemById(int id);
	void addItems(Item items );
	void deleteItems(int id);
	void showInfo();

};

