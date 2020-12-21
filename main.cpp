#include <iostream>
#include "Basic.h"
#include "Insert.h"
#include "GetPrint.h"
#include "Create.h"
#include "Delete.h"
int main()
{
	struct Matrix mtx;
	mtx.Lfirst = nullptr;
	int n, comm, state=ERROR, exit;
	std::cout << "Enter m (number of lines) and n (number of columns):" << std::endl;
	getNatural(mtx.m);
	getNatural(n);
	std::cout << "Enter the number of the line" << std::endl;
	exit = ERROR;
	getLC(comm, mtx.m, exit);
	struct Line *Lcurr;
	while (comm!=ERROR)
	{
		if (mtx.Lfirst == nullptr)
		{
			mtx.Lfirst = new Line;
			mtx.Lfirst->no = comm;
			mtx.Lfirst->Lnext = nullptr;
			Lcurr = mtx.Lfirst;
			Lcurr->Efirst = nullptr;
		}
		else
			Lcurr = Insert_Line(mtx, comm);
		Lcurr->length = n;
		std::cout << "Enter the number of the column" << std::endl;
		exit = ERROR;
		getLC(comm, n, exit);
		while (comm != ERROR)
		{
			if (Lcurr->Efirst == nullptr)
			{
				Lcurr->Efirst = new Element;
				Lcurr->Efirst->column = comm;
				Lcurr->Efirst->Enext = nullptr;
				std::cout << "Enter the value" << std::endl;
				getValue(Lcurr->Efirst->value);
			}
			else
			{
				struct Element *Ecurr = Insert_Element(Lcurr, comm);
				if (Ecurr == nullptr)
					std::cout << "This cell is already taken" << std::endl;
			}
			std::cout << "Enter the number of the column. If you want to finish enter -1" << std::endl;
			exit = OK;
			getLC(comm, n, exit);
		}
		std::cout << "Enter the number of the line. If you want to finish enter -1" << std::endl;
		exit = OK;
		getLC(comm, mtx.m, exit);
	}
	struct Matrix newmtx;
	newmtx.m = mtx.m;
	Create_Matrix(mtx, newmtx);
	std::cout << "This is the original matrix:" << std::endl;
	Print_Mtx(mtx, n);
	Delete_Mtx(mtx);
	std::cout << "This is the new matrix:" << std::endl;
	Print_Mtx(newmtx, n);
	Delete_Mtx(newmtx);
	std::cin >> exit;
}