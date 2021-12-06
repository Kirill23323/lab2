#define _CRT_SECURE_NO_WARNINGS
#include "Functions2.h"
#include <stdio.h>
#include <locale.h>
#include <time.h>
int main(int argc, char* argv[])
{
	double time_in_seconds = 0.0;
	int N,i,a,b,res,c,p = 0;
	int fl1,fl2,fl3 = 1;
	float* mas;
	float* masWork;
	FILE* f;
	setlocale(LC_ALL, "Rus");
	setlocale(LC_NUMERIC, "C");
	fopen_s(&f, "..\\text.txt", "r");
	fscanf_s(f, "%d\n", &N);
	mas = (float*)malloc(N * sizeof(float));
	masWork = (float*)malloc(N * sizeof(float));
	ZeroingAnArray(N, &mas);
	ZeroingAnArray(N, &masWork);
	for (i = 0; i < N; i++)
		fscanf_s(f, "%f", &(mas[i]));
	fclose(f);
	for (i = 0; i < N; i++)
		masWork[i] = mas[i];
	fl1 = 1;
	printf("�������� �������� � ������� ��������������� ��� �����:\n");
	printf("1 - ���������� ������ � �������\n");
	printf("2 - ������������� ������\n");
	printf("3 - ������� ������ � �������� ���������\n");
	printf("4 - ����� �� ���������\n");
	printf("5 - �������������� ����������\n");
	while (fl1) 
	{
		res = scanf("%d", &a);
		if (a == 1) 
		{
			PrintArray(N, masWork);
		}
		else if (a == 2)
		{
			fl2 = 1;
			printf("�������� ��� ����������:\n");
			printf("1 - �������\n");
			printf("2 - ���������\n");
			printf("3 - �������\n");
			while (fl2) 
			{
				res = scanf("%d", &b);
				if (b == 1) 
				{
					clock_t start = clock();
					BubbleSort(N, masWork);
					clock_t end = clock();
					time_in_seconds = (double)(end - start)/ CLOCKS_PER_SEC;
					printf("������ ������� ������������\n ");
					printf("����� ������ ��������� : %lf  ������\n", time_in_seconds);
					fl2 = 0;
				}

				else if (b == 2) 
				{
					clock_t start = clock();
					InsertSort(N, masWork);
					clock_t end = clock();
					time_in_seconds = (float)(end - start) / CLOCKS_PER_SEC;
					printf("������ ������� ������������\n ");
					printf("����� ������ ���������: %lf  ������\n", time_in_seconds);
					fl2 = 0;
				}
				else if (b == 3)
				{
					clock_t start = clock();
					QuickSort(masWork, 0, N - 1);
					clock_t end = clock();
					time_in_seconds = (float)(end - start) / CLOCKS_PER_SEC;
					printf("������ ������� ������������\n ");
					printf("����� ������ ���������: %lf  ������\n", time_in_seconds);
					fl2 = 0;
				}
				else {
					printf("�� ����� ������������ ��������!\n ");
					printf("��������� �������\n");
					if (res != 1)
					{
						while (fgetc(stdin) != '\n');
						continue;
					}
				}
			}

		}
		else if (a == 3) 
		{
			for (i = 0; i < N; i++)
				masWork[i] = mas[i];
			printf("������ ������� ������� �� ��������� ���������\n");
		}
		else if (a == 4)
			fl1 = 0;
		else if (a == 5) 
		{
			fl3 = 1;
			printf("�������� �������� � ������� ��������������� ��� �����:\n");
			printf("1 - ���������� ������ ����� �������\n");
			printf("2 - ���������� ������ ����� �������\n");
			printf("3 - ���������� ����������� ����� �������\n");
			printf("4 - ���������� ����������� ����� �������\n");
			printf("5 - ���������� �������\n");
			printf("6 - ��������� ���������� ����� ��������� ��������� ������\n");
			while (fl3)
			{
				res = scanf("%d", &c);
				if (c == 1)
				{
					FirstNorm(N, masWork);
					fl3 = 0;
				}

				else if (c == 2)
				{
					SecondNorm(N, masWork);
					fl3 = 0;
				}
				else if (c == 3)
				{
					printf("������� ����� p (p >= 1)\n");
					scanf("%d", &p);
					if (p < 1) 
					{
						printf("������!!! (p >= 1)\n");
						fl3 = 0;
					}
					else 
					{
						HelderNorm(N, masWork, p);
						fl3 = 0;
					}
				}
				else if (c == 4)
				{
					InfiniteNorm(N, masWork);
					fl3 = 0;
				}
				else if (c == 5)
				{
					Rationing(N, masWork);
					fl3 = 0;
				}
				else if (c == 6)
				{
					if (argc == 1)
					{
						printf("��������� �� �������");
						fl3 = 0;
					}
					else 
					{
						b = atoi(argv[1]);
						if (b == 1)
						{
							clock_t start = clock();
							BubbleSort(N, masWork);
							clock_t end = clock();
							time_in_seconds = (double)(end - start) / CLOCKS_PER_SEC;
							printf("������ ������� ������������\n ");
							printf("����� ������ ��������� : %lf  ������\n", time_in_seconds);
							fl3 = 0;
						}

						else if (b == 2)
						{
							clock_t start = clock();
							InsertSort(N, masWork);
							clock_t end = clock();
							time_in_seconds = (float)(end - start) / CLOCKS_PER_SEC;
							printf("������ ������� ������������\n ");
							printf("����� ������ ���������: %lf  ������\n", time_in_seconds);
							fl3 = 0;
						}
						else if (b == 3)
						{
							clock_t start = clock();
							QuickSort(masWork, 0, N - 1);
							clock_t end = clock();
							time_in_seconds = (float)(end - start) / CLOCKS_PER_SEC;
							printf("������ ������� ������������\n ");
							printf("����� ������ ���������: %lf  ������\n", time_in_seconds);
							fl3 = 0;
						}
					}
				}
				else
				{
					printf("�� ����� ������������ ��������!\n ");
					printf("��������� �������\n");
					if (res != 1)
					{
						while (fgetc(stdin) != '\n');
						continue;
					}
				}
			}
		}
		else 
		{
			printf("�� ����� ������������ ��������!\n ");
			printf("��������� �������\n");
			if (res != 1)
			{
				while (fgetc(stdin) != '\n');
				continue;
			}
		}
	}
	printf("������ ���������");
	return 0;
}