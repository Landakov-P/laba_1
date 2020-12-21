#ifndef basic
#define OK 0
#define ERROR -1
typedef struct Element
{
	int column;
	int value;
	Element *Enext;
} Element;
typedef struct Line
{
	int no;
	int length;
	Line *Lnext;
	Element *Efirst;
} Line;
typedef struct Matrix
{
	int m;
	Line *Lfirst;
} Matrix;
#endif