#pragma once
#include<iostream>
#include"List.h"

using namespace std;


class Journal
{
private:
	List** lists;
	int countLists = 0;
public:
	void addList(List list);
	void showList(int index);
	void showInfo();
};

