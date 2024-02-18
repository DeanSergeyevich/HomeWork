#include "Journal.h"
#include<iostream>

void Journal::addList(List list)
{
	List** buf = new List * [countLists + 1];
	for (int i = 0; i < countLists; i++)
	{
		buf[i] = lists[i];
	}
	buf[countLists++] = new List(list);
	delete[] lists;
	lists = buf;
}

void Journal::showInfo()
{
for(int i = 0; i < countLists; i++)
{
	lists[i]->showInfo();
	cout << endl;
}
}

void Journal::showList(int index )
{
	lists[index]->showInfo();
}
