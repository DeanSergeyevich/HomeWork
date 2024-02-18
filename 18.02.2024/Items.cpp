#include "Items.h"

Item::Item(string text, string data)
{
	uniqId = id++;
	this->text = text;
	this->data = data;
}

int Item::getId()
{
	return 0;
}

void Item::showInfo()
{
	cout << uniqId << " : " << text << " : " << data << endl;
}

int Item::id = 0;