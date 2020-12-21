#include <iostream>
#include "Basic.h"
struct Element* Find_Min(struct Line *line)
{
	struct Element *Emin = line->Efirst, *curr = line->Efirst->Enext;
	while (curr != nullptr)
	{
		if (curr->value < Emin->value)
			Emin = curr;
		curr = curr->Enext;
	}
	return Emin;
}
void Create_Line(struct Line *line1, struct Line *line2)
{
	struct Element *Emin = Find_Min(line1);
	struct Element *Ecopypoint;
	line2->no = line1->no;
	int offset;
	if (Emin->value > 0)
	{
		Ecopypoint = line1->Efirst;
		offset = 0;
		line2->length = line1->length;
	}
	else
	{
		Ecopypoint = Emin;
		offset = Ecopypoint->column;
		line2->length = line1->length - offset;
	}
	struct Element *curr = new Element;
	line2->Efirst = curr;
	while (Ecopypoint != nullptr)
	{
		curr->column = Ecopypoint->column - offset;
		curr->value = Ecopypoint->value;
		Ecopypoint = Ecopypoint->Enext;
		if (Ecopypoint != nullptr)
		{
			curr->Enext = new Element;
			curr = curr->Enext;
		}
		else
			curr->Enext = nullptr;
	}
}
void Create_Matrix(struct Matrix &mtx1, struct Matrix &mtx2)
{
	struct Line *line1 = mtx1.Lfirst;
	mtx2.Lfirst = new Line;
	struct Line *line2 = mtx2.Lfirst;
	while (line1 != nullptr)
	{
		Create_Line(line1, line2);
		line1 = line1->Lnext;
		if (line1 != nullptr)
		{
			line2->Lnext = new Line;
			line2 = line2->Lnext;
		}
		else
			line2->Lnext = nullptr;
	}
}