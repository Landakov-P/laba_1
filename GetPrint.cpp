#include <iostream>
#include <limits>
#include "Basic.h"
void getNatural(int &num)
{
	int state = ERROR;
	while (state == ERROR)
	{
		std::cin >> num;
		if (!std::cin.good() || num<1)
		{
			std::cout << "Incorrect data" << std::endl;
			state = ERROR;
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		else
			state = OK;
	}
}
void getValue(int &num)
{
	int state = ERROR;
	while (state == ERROR)
	{
		std::cin >> num;
		if (!std::cin.good())
		{
			std::cout << "Incorrect data" << std::endl;
			state = ERROR;
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		else
			state = OK;
	}
}
void getLC(int &num, int limit, int exit)
{
	int state = ERROR;
	while (state == ERROR)
	{
		std::cin >> num;
		if (!std::cin.good() || (num<0 && exit == ERROR) || (num<0 && num != -1 && exit == OK) || num >= limit)
		{
			std::cout << "Incorrect data" << std::endl;
			state = ERROR;
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		else
			state = OK;
	}
}
void Print_Mtx(struct Matrix &mtx, int n)
{
	struct Line *line = mtx.Lfirst;
	for (int j = 0; j<mtx.m; j++)
	{
		if (line != nullptr && j == line->no)
		{
			struct Element *curr = line->Efirst;
			for (int i = 0; i < line->length; i++)
			{
				if (curr != nullptr && i == curr->column)
				{
					std::cout << curr->value << "   ";
					curr = curr->Enext;
				}
				else
					std::cout << "0   ";
			}
			line = line->Lnext;
		}
		else
			for (int i = 0; i < n; i++)
				std::cout << "0   ";
		std::cout << std::endl;
	}
}