#define _CRT_SECURE_NO_WARNINGS
#include "Functions1.h" 
#include <stdio.h>
#include<stdlib.h>
#include <locale.h>	
int main(void) {
	int a,min,max,tmp = 0;
	float b = 0;
	float* mas;
	int N = 0;
	int i = 0;
	FILE* f;
	FILE* f1;
	fopen_s(&f, "..\\text.txt", "w");
	setlocale(LC_ALL, "Rus");
	setlocale(LC_NUMERIC, "C");
	printf("Каким способом будете записывать числа в файл?\n");
	printf("Введите одну из трех цифр:\n");
	printf("1 - Записать числа случайно сгенерированные программой\n");
	printf("2 - Записать числа вручную \n");
	printf("3 - У меня уже есть файл с числами \n");
	scanf("%d", &a);
	if (a == 1) {
		printf("Введите количество случайных чисел\n");
		scanf("%d", &N);
		fprintf(f, "%d\n", N);
		if (N <= 0)
		{
			printf("Количество не может быть отрицательным или равным нулю");
			return 0;
		}
		printf("Введите диапазон генерации случайных чисел\n");
		printf("Введите минимальное значение\n");
		scanf("%d", &min);
		printf("Введите максимальное значение\n");
		scanf("%d", &max);
		if (min > max) 
		{
			tmp = min;
			min = max;
			max = tmp;
		}
		else if (min == max) 
		{
			printf(" Ошибка!! min != max");
			return 0;
		}
		mas = (float*)malloc(N * sizeof(float));
		ZeroingAnArray(N, &mas);
		RandomNumberGeneration(N,min,max, &mas);
		for (i = 0; i < N; i++)
		{
			fprintf(f, "%f\n", mas[i]);
		}
		printf("Числа сгенерированы и записаны в файл");

		fclose(f);
	}
	else if (a == 2)
	{
		printf("Введите количество чисел\n");
		scanf("%d", &N);
		if (N <= 0)
		{
			printf("Количество не может быть отрицательным или равным нулю");
			return 0;
		}
		fprintf(f, "%d\n", N);
		mas = (float*)malloc(N * sizeof(float));
		ZeroingAnArray(N, &mas);
		ManualNumberGeneration(N, &mas);
		for (i = 0; i < N; i++)
		{
			fprintf(f, "%f\n", mas[i]);
		}
		printf("Числа  записаны в файл");
		fclose(f);
	}
	else if (a == 3) 
	{
		printf("Ваш файл должен лежать в папке Lab work 2 и иметь название file.txt\n");
		printf("Числа внутри файла должны быть записаны строго друг под другом без пробелов перед ними\n");
		printf("Самое первое число (целого типа) обозначает колличество чисел\n");
		printf("Остальные уже сами числа (типа float)\n");
		printf("Пример правильного файла\n");
		printf("5\n");
		printf("0.001251\n");
		printf("0.563585\n");
		printf("0.193304\n");
		printf("0.808740\n");
		printf("0.585009\n");
		fopen_s(&f1, "..\\file.txt", "r");
		fscanf_s(f1, "%d\n", &N);
		mas = (float*)malloc(N * sizeof(float));
		for (i = 0; i < N; i++)
			fscanf_s(f1, "%f", &(mas[i]));
		fprintf(f, "%d\n", N);
		for (i = 0; i < N; i++)
			fprintf(f, "%f\n", mas[i]);
		fclose(f);
		fclose(f1);
	}
	else 
	{
		printf("Вы ввели некорректное значение!\n ");
		return 0;
	}
	return 0;
}