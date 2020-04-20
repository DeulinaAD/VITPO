#include <fstream>
#include <iostream>
#include "conio.h"
using namespace std;

class matA
{
	int** Mat;
public:
	int AAA = 0, i, j;
	int** Tam;
	void init(int* k)
	{
		ifstream Oi("u.txt");
		char buff[20];
		int Bu[20][20], i, j = 0, b;
		for (i = 0; i < 20; i++)
			for (j = 0; j < 20; j++)
				Bu[i][j] = 0;
		i = j = b = 0;
		Oi >> buff;
		Bu[0][0] = buff[0] - 48;
		*k = Bu[0][0];
		while (Oi.good())
		{
			Oi >> buff;
			for (int i = 0; i < *k; i++)
				Bu[j][i] = buff[i] - 48;
			cout << buff << endl;
			j++;
		}
		Oi.close();
		int y = 0;
		Mat = new int* [*k];
		Tam = new int* [*k];
		for (int o = 0; o < *k + 1; o++)
		{
			Tam[o] = new int[*k];
			Mat[o] = new int[*k];
		}
		//будем действовать так
		//сначала считаем все возможные положительные индексы и диагонали с ними
		//затем отрицательные
		i = b = 0;
		for (j = 0; j < *k; j++)
		{
			if (Bu[i][j] != 0) //значит диагональ надо записать в матрицу
			{
				Mat[y][*k] = b = j;
				int t = j, p;
				for (p = 0, t; p < *k - b && t < *k; p++, t++)
					Mat[y][p] = Bu[p][t];
				y++;
				AAA++;
			}
		}
		j = b = 0;
		for (i = 1; i < *k; i++)
		{
			if (Bu[i][j] != 0) //значит диагональ надо записать в матрицу
			{
				Mat[y][*k] = b = -i;
				int t, p = i;
				for (p, t = 0; p < *k && t < *k + b; p++, t++)
					Mat[y][t] = Bu[p][t];
				y++;
				AAA++;
			}
		}
		cout << "\n" << AAA << "\n";
	}
	void Rras(int k)
	{
		int i = 0, j = 0, b = 0;
		//по индексу определ€ем, с какой строчки или столбца начинаетс€ диагональ 
		//переходим в эту €чейку и копируем первый ненулевой элемент 
		//в дальнейшем идЄм по столбцу матрицы, а к €чейкам развЄрнутой матрицы прибавл€ем по единице 
		for (i = 0; i < k; i++)
			for (j = 0; j < k; j++)
				Tam[i][j] = 0;
		for (int o = 0; o < AAA; o++)
		{
			i = j = 0;
			if (Mat[o][k] > 0)
			{
				i = 0;
				j = b = Mat[o][k];
			}
			if (Mat[o][k] < 0)
			{
				i = Mat[o][k];
				i = b = -i;
				j = 0;
			}
			for (int n = 0; n < k - b; n++)
			{
				Tam[i][j] = Mat[o][n];
				i++;
				j++;
			}
		}
		cout << j;
	}
	void Pr(int k)
	{
		int b = 0;
		for (int i = 0; i < AAA; i++)
		{
			if (Mat[i][k] > 0)
				b = Mat[i][k];
			if (Mat[i][k] < 0)
				b = -Mat[i][k];
			cout << Mat[i][k];
			cout << ": ";
			for (int j = 0; j < k - b; j++)
				cout << Mat[i][j] << "; ";
			cout << "\n";
		}
		for (int i = 0; i < k; i++)
		{
			cout << "\n";
			for (int j = 0; j < k; j++)
			{
				cout << Tam[i][j];
				cout << " ";
			}
		}
	}
};

class Par
{
public:
	int a = -90, b = -90;
	void init(int u, int y)
	{
		a = u;
		b = y;
	}
};

class matB
{
	Par*** Mat;
	//дл€ матрицы ¬ введЄм инификацию с клавиатуры построчно
	//плюс вывод сжатой матрицы и раскрытой матрицы
	//плюс функцию умножени€ матрицы на число
public:
	int** Tam;
	void init(int* k)
	{
		ifstream Oi("u1.txt");
		char buff[20];
		int Bu[20][20], i, j = 0, b;
		for (i = 0; i < 20; i++)
			for (j = 0; j < 20; j++)
				Bu[i][j] = 0;
		i = j = b = 0;
		Oi >> buff;
		Bu[0][0] = buff[0] - 48;
		*k = Bu[0][0];
		while (Oi.good())
		{
			Oi >> buff;
			for (int i = 0; i < *k; i++)
				Bu[j][i] = buff[i] - 48;
			cout << buff << endl;
			j++;
		}
		Oi.close();
		Mat = new Par **[*k];
		Tam = new int* [*k];
		for (int o = 0; o < *k; o++)
		{
			Tam[o] = new int[*k];
			Mat[o] = new Par * [*k];
		}
		for (int o = 0; o < *k; o++)
			for (int p = 0; p < *k; p++)
				Mat[o][p] = new Par[*k];
		int t = 0, t1 = 0, t2 = 0;
		for (int i = 0; i < *k; i++)
			for (int j = 0; j < *k; j++)
			{
				//необходимо находить ненулевые элементы в матрице Ѕу
				//запоминать их джи в т1, значение в т2
				if (Bu[i][j] != 0)
				{
					t1 = j;
					t2 = Bu[i][j];
					Mat[i][j]->init(t1, t2);
				}
			}

	}
	int Rras(int k)
	{
		//запускаем тройной цикл
		//дл€ каждого элемента, у которого i равна номеру строки 
		//а j равна первому элементу из мат, записать второй элемент из мат
		//дл€ остальных нули
		int f = 0;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				for (f = 0; f < k; f++)
				{
					if (j == Mat[i][f]->a)
					{
						Tam[i][j] = Mat[i][f]->b;
						f = 21;
					}
					else
						Tam[i][j] = 0;		
				}
		return f;

	}
	void Pr(int k)
	{
		for (int i = 0; i < k; i++)
		{
			cout << i;
			cout << ": ";
			for (int j = 0; j < k; j++)
			{
				if (Mat[i][j]->a != -90 && Mat[i][j]->b != -90)
					cout << Mat[i][j]->a << ", " << Mat[i][j]->b << "; ";
			}
			cout << "\n";
		}
		for (int i = 0; i < k; i++)
		{
			cout << "\n";
			for (int j = 0; j < k; j++)
			{
				cout << Tam[i][j];
				cout << " ";
			}
		}
	}
	void Um(int k, int T)
	{
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				Tam[i][j] = Tam[i][j] * T;
	}
};