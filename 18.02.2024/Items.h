#pragma once
#include<iostream>

using namespace std;
class Item
{
	private:
		static int id;
		int uniqId;
		string text;
		string data;

	public:
		Item(string text, string data);
		int getId();
		void showInfo();

};

