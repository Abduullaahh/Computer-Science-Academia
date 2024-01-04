#include<iostream>
using namespace std;
int** TransposeMatrix(int** matrix, const int& rows, const int& cols)
{
	int** new_matrix = new int* [cols];   //becuae after transpose new matrix will have rows equal to cols of old matix
	for (int i = 0; i < cols; i++)    //and cols equal to rows of old matix (because when we take transpose rows becomes cols
	{ //and cols becomes rows 
		new_matrix[i] = new int [rows] {0};
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			new_matrix[i][j] = matrix[j][i];
		}

	}
	cout << "Matrix After Transpose:" << endl;
	for (int i = 0; i <cols; i++)
	{
		for (int j = 0; j <rows; j++)
		{
			cout << new_matrix[i][j] << "  ";
		}
		cout << endl;
	}
	return new_matrix;

}
int main()
{
	
		int rows, cols;
	cout << "Enter No Of Rows:" << endl;
	cin >> rows;
	cout << "Enter No Of Cols:" << endl;
	cin >> cols;
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {0};//{0} this will initialize each element of matrix with zero(good programming practice)
	}
	cout << "Fill Your Matrix" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "Enter Elements For Row No: " << i + 1 << endl;
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];

		}
	}
	cout << "Matrix Before Transpose:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	matrix = TransposeMatrix(matrix, rows, cols);

	// i will not deduct the marks for dynamic memory deletion 
	for (int i = 0; i <cols; i++) //as we know by taking transpose rows becomes cols and cols becomes rows 
	{
		delete[]matrix[i];
	}
	delete[]matrix;
	matrix = nullptr;
	system("pause");
	return 0;


}