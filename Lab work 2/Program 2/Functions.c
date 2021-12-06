#define _CRT_SECURE_NO_WARNINGS
// Program 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void ManualNumberGeneration(int n, float** mas1)
{
	float b = 0.0;
	int i = 0;
	printf("Введите числа типа float\n");
	printf("Пример ввода: 11.100247 (после точки должно быть максимум 6 цифр)\n");
	for (i = 0; i < n; i++)
	{
		scanf("%f", &b);
		(*mas1)[i] = b;
	}
}
void ZeroingAnArray(int n, float** mas1)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		(*mas1)[i] = 0;
	}
}
void RandomNumberGeneration(int n,int min,int max, float** mas1)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		(*mas1)[i] = (((float)rand()) / RAND_MAX) * (max - min) + min;
	}
}

// Program 2

void BubbleSort(int N, float* mas1)
{
	int i = 0;
	float tmp = 0.0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (mas1[j] > mas1[j + 1])
			{
				tmp = mas1[j];
				mas1[j] = mas1[j + 1];
				mas1[j + 1] = tmp;
			}
		}
	}

}
void InsertSort(int N, float* mas1)
{
	float tmp = 0.0;
	int k = 0;
	int i = 0;
	for (i = 1; i < N; ++i)
	{
		k = i;
		while ((k > 0) && (mas1[k - 1] > mas1[k]))
		{
			tmp = mas1[k - 1];
			mas1[k - 1] = mas1[k];
			mas1[k] = tmp;
			k -= 1;
		}
	}
}

void QuickSort(float* mas1, int first, int last)
{
	if (first < last)
	{
		float tmp = 0.0;
		int left = first;
		int right = last;
		double middle = mas1[(left + right) / 2];
		do
		{
			while (mas1[left] < middle)
				left++;
			while (mas1[right] > middle)
				right--;
			if (left <= right)
			{
				tmp = mas1[left];
				mas1[left] = mas1[right];
				mas1[right] = tmp;
				left++;
				right--;
			}
		} while (left < right);
		QuickSort(mas1, first, right);
		QuickSort(mas1, left, last);
	}
}
void PrintArray(int n, float* mas1)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("mas[%d] = %f\n ",i ,mas1[i]);
	}
}
void FirstNorm(int n, float* mas) 
{
	int i = 0;
	float norm = 0;
	for (i = 0; i < n; i++) 
	{
		norm += fabs(mas[i]);
	}
	printf("Первая норма вектора равна  %f\n", norm);
}
void SecondNorm(int n, float* mas) 
{
	int i = 0;
	float sum = 0;
	float norm = 0;
	for (i = 0; i < n; i++)
	{
		sum += pow(fabs(mas[i]),2);
	}
	norm = sqrtf(sum);
	printf("Вторая норма вектора равна  %f\n", norm);
}
void HelderNorm(int n, float* mas,int p)
{
	int i = 0;
	float sum = 0;
	float norm = 0;
	for (i = 0; i < n; i++)
	{
		sum += pow(fabs(mas[i]), p);
	}
	norm = pow(sum,1.0/p);
	printf("Гельдерова норма вектора равна  %f\n", norm);
}
void InfiniteNorm(int n, float* mas)
{
	float max = -9999999.9999999;
	int i = 0;
	float sum = 0;
	for (i = 0; i < n; i++)
	{
		mas[i] = fabs(mas[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (mas[i] > max)
			max = mas[i];
	}
	printf("Бесконечная норма вектора равна  %f\n", max);
}
void Rationing(int n, float* mas)
{
	int i = 0;
	float len,sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += pow(mas[i], 2);
	}
	len = sqrtf(sum);
	for (i = 0; i < n; i++)
	{
		mas[i] = mas[i] / len;
	}
	printf("Вектор нормирован\n");
}