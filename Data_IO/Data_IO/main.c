#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#ifndef DATATYPE
#define DATATYPE
typedef int Etype;
//#define SCANFORMAT "%f"
//#define PRNFORMAT "%10.6f"
#define SCANFORMAT "%d"
#define PRNFORMAT "%d"
#endif

#ifndef DATASET
#define DATASET
typedef struct
{
	int rows;
	int cols;
	int length;
	Etype *elem;

}DataSet;
#endif

static DataSet *ReadData(const char *fileName);
static void DestroyData(DataSet *dataSet);
static void PrintData(DataSet *dataSet);


int main(int argc, char *argv[])
{
	DataSet *data = NULL;

	data = ReadData("input.txt");
	PrintData(data);
	printf("\n");

	DestroyData(data);

	return 0;

}

DataSet *ReadData(const char *fileName)
{
	FILE *rfp;
	int i;
	DataSet ds;

	rfp = fopen(fileName, "r");

	fscanf(rfp, "%d", &ds.rows);
	fscanf(rfp, "%d", &ds.cols);
	fscanf(rfp, "%d", &ds.length);

	ds.elem = (int*)malloc(sizeof(int)*ds.length);

	for (i = 0; i < ds.length; i++)
	{
		if (feof(rfp) && i == ds.length - 1)
		{
			break;
		}
		else
		{
			if (feof(rfp))
			{
				printf("0 ");
			}
			else
			{
				fscanf(rfp, "%d", &ds.elem[i]);

			}
		}
	}

	return &ds;

}
void DestroyData(DataSet *dataSet)
{
	return;
}
void PrintData(DataSet *dataSet)
{
	int i;
	for (i = 0; i < dataSet->length; i++)
	{
		printf(PRNFORMAT, dataSet->elem[i]);

		if ((i + 1) % (dataSet->cols) == 0)
		{
			printf("\n");
		}
	}
}