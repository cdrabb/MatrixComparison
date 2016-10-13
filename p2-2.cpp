#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void create(double **, int);
void populate(double **, int);
void autoPopulate(double **, int);
void print(double **, int);
void add(double **, double **, double**, int);
void sub(double **, double **, double**, int);
void mult(double **, double **, double**, int);
int main()
{
	int n;
	double **a;
	double **b;
	double **c;
	double **d; 
	double **e;

	cout << "Matrices will have the dimensions n x n..." << endl;
		cout << "Enter the n of the matrices: ";
	cin >> n;
	a = new double *[n];
	b = new double *[n];

	if (n < 5)
	{
		create(a, n); //Creates matrix
		create(b, n);
		populate(a, n); //Allows user to enter data manually
		populate(b, n);
	}
	//else if (n = 5)
	//{
		//*a = new double[5];
		//**a = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	//}
	else
	{
		create(a, n); //Creates matrix
		create(b, n);
		autoPopulate(a, n);
		autoPopulate(b, n);
	}
	cout << "M1" << endl;
	print(a, n);
	
	cout << "M2" << endl;
	print(b, n);

	cout << "M3" << endl;
	c = new double *[n];
	add(a, b, c, n); //Adds the two matrices

	cout << "M4" << endl;
	d = new double *[n];
	sub(a, b, d, n); //Subtracts the two matrices

	cout << "M5" << endl;
	e = new double *[n];
	mult(a, b, e, n); //Multiplies the two matrices
	system("pause");
}
void create(double **p, int n) //Creates the empty matrix
{
	for (int i = 0; i < n; i++)
	{
		*(p + i) = new double[n];
	}
}
void populate(double **p, int n) //Lets the user manually enter data
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "What number will be in row " << i << " column " << j << "?: ";
			cin >> *(*(p + i) + j);
			system("cls");
		}
	}
}
void autoPopulate(double **p, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(p + i) + j) = rand() % 100 + 1;;
		}
	}
}
void print(double **p, int n) //Prints out the specified matrix
{
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < n; j++)
		{
			cout << " " << *(*(p + i) + j) << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}
void add(double **a, double **b, double **c, int n) //Adds two matrices
{
	create(c, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
		}
	}
	print(c, n);
	delete[] c; //Deletes the matrix that was created
}
void sub(double **a, double **b, double **d, int n) //Subtracts two matrices
{
	create(d, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(d + i) + j) = *(*(a + i) + j) - *(*(b + i) + j);
		}
	}
	print(d, n);
	delete[] d;
}
void mult(double **a, double **b, double **e, int n) //Multiplies two matrices
{
	create(e, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(e + i) + j) = 0; //Initializes the appropriate position
			for (int k = 0; k < n; k++)
			{
				*(*(e + i) + j) += *(*(a + i) + k) * *(*(b + k) + j); //The sum of multiple products
			}
		}
	}
	print(e, n);
	delete[] e;
}