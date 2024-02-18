#include "List.h"
using namespace std;

int List::getIndexItemById(int id)
{
	for(int i = 0; i<countItems; i++)
	{
		if (items[i]->getId() == id) return i;
	}
	return -1;
	
}

void List::addItems(Item newItems)
{
	Item** buf = new Item*[countItems + 1];
	for (int i = 0; i < countItems; i++)
	{
		buf[i] = items[i];
	}
	buf[countItems++] = new Item(newItems);
	delete[] items;
	items = buf;
}

void List::deleteItems(int id)
{
	if (countItems == 0) return;
	int index = getIndexItemById(id);
		if (index == -1)return;
	Item** buf = new Item * [countItems - 1];
	for (int i = 0; i < index; i++)
	{
		buf[i] = items[i];
	}
	for (int i = index + 1; i < countItems; i++)
	{
		buf[i-1] = items[i];
	}
	delete[] items;
	items = buf;
	countItems--;
}

void List::showInfo()
{
	for(int i = 0; i<countItems; i++)
	{
		items[i]->showInfo();
		cout << endl;
	}
}
