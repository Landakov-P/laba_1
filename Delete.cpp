#include <iostream>
#include "Basic.h"
void Delete_Mtx(struct Matrix &mtx)
{
	struct Line *Lcurr, *Ltmp;
	Lcurr = mtx.Lfirst;
	struct Element *Ecurr, *Etmp;
	while (Lcurr != nullptr)
	{
		Ecurr = Lcurr->Efirst;
		while (Ecurr != nullptr)
		{
			Etmp = Ecurr;
			Ecurr = Ecurr->Enext;
			delete Etmp;
		}
		Ltmp = Lcurr;
		Lcurr = Lcurr->Lnext;
		delete Ltmp;
	}
}