#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int Obs;
	int c1;
	int c2;
	int c3;
	int c4;
	int c5;
	int c6;
	int c7;
	int c8;

}Record;

typedef struct RecordSet
{
	int rows;
	int cols;
	Record **rc;

}RecordSet;

static RecordSet *ReadData(const char *fileName);
static void DestroyData(RecordSet *dataSet);
static void PrintData(RecordSet *dataSet);

void main(void)
{
	RecordSet *dataSet;
	dataSet = ReadData("Heartbeat.txt");
	PrintData(dataSet);
	DestroyData(dataSet);
}

static RecordSet *ReadData(const char *fileName)
{
	FILE *infile;
	RecordSet *recordSet;
	int i;
	char ids[100], title[30];

	infile = fopen(fileName, "r");

	recordSet = (RecordSet*)malloc(sizeof(RecordSet));
	fscanf(infile, "%d %d", &recordSet->rows, &recordSet->cols);
	(recordSet->rc) = (RecordSet**)malloc(sizeof(RecordSet*) * (recordSet->rows));

	printf("%d %d\n", recordSet->rows, recordSet->cols);

	fgets(title, 49, infile);
	fgets(title, 49, infile);
	fgets(ids, 99, infile);

	printf("\t\t\t%s", title);
	printf("%s", ids);

	for (i = 0; i < recordSet->rows;i++)
	{
		recordSet->rc[i] = (Record*)malloc(sizeof(Record));
		//fscanf_s(infile, "%d %d %d %d %d %d %d %d %d", &recordSet->rc[i]);
		fscanf_s(infile, "%d", &recordSet->rc[i]->Obs);
		fscanf_s(infile, "%d", &recordSet->rc[i]->c1);
		fscanf_s(infile, "%d", &recordSet->rc[i]->c2);
		fscanf_s(infile, "%d", &recordSet->rc[i]->c3);
		fscanf_s(infile, "%d", &recordSet->rc[i]->c4);
		fscanf_s(infile, "%d", &recordSet->rc[i]->c5);
		fscanf_s(infile, "%d", &recordSet->rc[i]->c6);
		fscanf_s(infile, "%d", &recordSet->rc[i]->c7);
		fscanf_s(infile, "%d", &recordSet->rc[i]->c8);
	}

	fclose(infile);
	return recordSet;
}


static void DestroyData(RecordSet *dataSet)
{
	int i;
	for (i = 0; i < dataSet->rows; i++)
	{
		free(dataSet->rc[i]);
	}

	free(dataSet);
}

static void PrintData(RecordSet *dataSet)
{
	int i;
	for (int i = 0; i < dataSet->rows; i++)
	{
		//printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", dataSet->rc[i]);
		printf("%d\t", dataSet->rc[i]->Obs);
		printf("%d\t", dataSet->rc[i]->c1);
		printf("%d\t", dataSet->rc[i]->c2);
		printf("%d\t", dataSet->rc[i]->c3);
		printf("%d\t", dataSet->rc[i]->c4);
		printf("%d\t", dataSet->rc[i]->c5);
		printf("%d\t", dataSet->rc[i]->c6);
		printf("%d\t", dataSet->rc[i]->c7);
		printf("%d\t", dataSet->rc[i]->c8);
		printf("\n");
	}
}