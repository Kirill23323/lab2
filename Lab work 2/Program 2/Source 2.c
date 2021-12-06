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
	printf("Выберите действие и введите соответствующую ему цифру:\n");
	printf("1 - Напечатать массив в консоли\n");
	printf("2 - Отсортировать массив\n");
	printf("3 - Вернуть массив в исходное состояние\n");
	printf("4 - Выйти из программы\n");
	printf("5 - Дополнительный функционал\n");
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
			printf("Выберите тип сортировки:\n");
			printf("1 - Пузырек\n");
			printf("2 - Вставками\n");
			printf("3 - Быстрая\n");
			while (fl2) 
			{
				res = scanf("%d", &b);
				if (b == 1) 
				{
					clock_t start = clock();
					BubbleSort(N, masWork);
					clock_t end = clock();
					time_in_seconds = (double)(end - start)/ CLOCKS_PER_SEC;
					printf("Массив успешно отсортирован\n ");
					printf("Время работы алгоритма : %lf  секунд\n", time_in_seconds);
					fl2 = 0;
				}

				else if (b == 2) 
				{
					clock_t start = clock();
					InsertSort(N, masWork);
					clock_t end = clock();
					time_in_seconds = (float)(end - start) / CLOCKS_PER_SEC;
					printf("Массив успешно отсортирован\n ");
					printf("Время работы алгоритма: %lf  секунд\n", time_in_seconds);
					fl2 = 0;
				}
				else if (b == 3)
				{
					clock_t start = clock();
					QuickSort(masWork, 0, N - 1);
					clock_t end = clock();
					time_in_seconds = (float)(end - start) / CLOCKS_PER_SEC;
					printf("Массив успешно отсортирован\n ");
					printf("Время работы алгоритма: %lf  секунд\n", time_in_seconds);
					fl2 = 0;
				}
				else {
					printf("Вы ввели некорректное значение!\n ");
					printf("Повторите попытку\n");
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
			printf("Массив успешно сброшен до исходного состояния\n");
		}
		else if (a == 4)
			fl1 = 0;
		else if (a == 5) 
		{
			fl3 = 1;
			printf("Выберите действие и введите соответствующую ему цифру:\n");
			printf("1 - Вычисление первой нормы вектора\n");
			printf("2 - Вычисление второй нормы вектора\n");
			printf("3 - Вычисление Гельдеровой нормы вектора\n");
			printf("4 - Вычисление бесконечной нормы вектора\n");
			printf("5 - Нормировка вектора\n");
			printf("6 - Запустить сортировку через параметры командной строки\n");
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
					printf("Введите целое p (p >= 1)\n");
					scanf("%d", &p);
					if (p < 1) 
					{
						printf("Ошибка!!! (p >= 1)\n");
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
						printf("Параметры не введены");
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
							printf("Массив успешно отсортирован\n ");
							printf("Время работы алгоритма : %lf  секунд\n", time_in_seconds);
							fl3 = 0;
						}

						else if (b == 2)
						{
							clock_t start = clock();
							InsertSort(N, masWork);
							clock_t end = clock();
							time_in_seconds = (float)(end - start) / CLOCKS_PER_SEC;
							printf("Массив успешно отсортирован\n ");
							printf("Время работы алгоритма: %lf  секунд\n", time_in_seconds);
							fl3 = 0;
						}
						else if (b == 3)
						{
							clock_t start = clock();
							QuickSort(masWork, 0, N - 1);
							clock_t end = clock();
							time_in_seconds = (float)(end - start) / CLOCKS_PER_SEC;
							printf("Массив успешно отсортирован\n ");
							printf("Время работы алгоритма: %lf  секунд\n", time_in_seconds);
							fl3 = 0;
						}
					}
				}
				else
				{
					printf("Вы ввели некорректное значение!\n ");
					printf("Повторите попытку\n");
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
			printf("Вы ввели некорректное значение!\n ");
			printf("Повторите попытку\n");
			if (res != 1)
			{
				while (fgetc(stdin) != '\n');
				continue;
			}
		}
	}
	printf("Работа завершена");
	return 0;
}