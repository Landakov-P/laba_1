#include <iostream>
#include "Basic.h"
#include "GetPrint.h"
struct Line* Insert_Line(struct Matrix &mtx, int number)
{
	struct Line *curr = mtx.Lfirst;
	struct Line *tmp = new Line;
	if (curr->no <= number)
	{
		while (curr->Lnext != nullptr && curr->Lnext->no < number)
			curr = curr->Lnext;
		if (curr->no == number || (curr->Lnext != nullptr && curr->Lnext->no == number))
		{
			delete tmp;
			if (curr->no == number)
				tmp = curr;
			else
				tmp = curr->Lnext;
		}
		else
		{
			tmp->no = number;
			tmp->Lnext = curr->Lnext;
			tmp->Efirst = nullptr;
			curr->Lnext = tmp;
		}
	}
	else
	{
		tmp->no = number;
		tmp->Lnext = curr;
		tmp->Efirst = nullptr;
		mtx.Lfirst = tmp;
	}
	return tmp;
}
struct Element* Insert_Element(struct Line *line, int number)
{
	struct Element *curr = line->Efirst;
	struct Element *tmp = new Element;
	if (curr->column <= number)
	{
		while (curr->Enext != nullptr && curr->Enext->column < number)
			curr = curr->Enext;
		if (curr->column == number || (curr->Enext != nullptr && curr->Enext->column == number))
		{
			delete tmp;
			return nullptr;
		}
		else
		{
			tmp->column = number;
			tmp->Enext = curr->Enext;
			curr->Enext = tmp;
		}
	}
	else
	{
		struct Element *tmp = new Element;
		tmp->column = number;
		tmp->Enext = curr;
		line->Efirst = tmp;
	}
	std::cout << "Enter the value" << std::endl;
	getValue(tmp->value);
	return tmp;
}