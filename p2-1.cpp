#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void print(double [5][5]);
void add(double[5][5], double[5][5], double[5][5]);
void sub(double[5][5], double[5][5], double[5][5]);
void mult(double[5][5], double[5][5], double[5][5]);
int main()
{
	double a[5][5] = { { 1.0, 2.0, 3.0, 4.0, 5.0 },{ 2.0, 2.0, 2.0 ,2.0, 2.0 },
	                   {3.0, 1.0, 1.0, 1.0, 3.0}, {0.0, 0.0, 2.0, 3.0, - 2.0}, 
					   {4.0, 4.0, - 4.0, 0.0, 0.0} };
	double b[5][5] = { { 1.0, 0.0, 0.0, 0.0, 0.0 }, { 1.0, 2.0, 1.0, 2.0 ,1.0 },
	                   {0.0, 0.0, 1.0, 0.0, 0.0}, {1.0, 1.0, 1.0, 1.0, 1.0},
					   {2.0, 2.0, - 2.0, 2.0, 2.0} };
	double c[5][5];
	double d[5][5];
	double e[5][5];

	cout << "M1" << endl;
	print(a);

	cout << "M2" << endl;
	print(b);

	cout << "M3" << endl;
	add(a, b, c); //Adds the two matrices

	cout << "M4" << endl;
	sub(a, b, d); //Subtracts the two matrices

	cout << "M5" << endl;
	mult(a, b, e); //Multiplies the two matrices
	system("pause");

	return 0;
}
void print(double p [][5]) //Prints out the specified matrix
{
	for (int i = 0; i < 5; i++)
	{
		cout << "|";
		for (int j = 0; j < 5; j++)
		{
			cout << " " << p[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}
void add(double a [][5], double b[][5], double c[][5]) //Adds two matrices
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	print(c);
	//delete c; //Deletes the matrix that was created
}
void sub(double a[][5], double b[][5], double d[][5]) //Subtracts two matrices
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			d[i][j] = a[i][j] - b[i][j];
		}
	}
	print(d);
	//delete[] d;
}
void mult(double a[][5], double b[][5], double e[][5]) //Multiplies two matrices
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			e[i][j] = 0; //Initializes the appropriate position
			for (int k = 0; k < 5; k++)
			{
				e[i][j] += a[i][k] * b[k][j]; //The sum of multiple products
			}
		}
	}
	print(e);
	//delete[] e;
}