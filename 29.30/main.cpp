#include <iostream>
#include <ctime>
#include "Matrix.h"
using namespace std;


int main() {
    srand((time(nullptr));  // генератор случайных чисел

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Создание двух матриц с заданным числом строк и столбцов
    Matrix<int> matrix1(rows, cols);
    matrix1.Rand();  

    Matrix<int> matrix2(rows, cols);
    matrix2.Input();  

    cout << "Matrix 1:" << endl;
    matrix1.Print();
    cout << "Matrix 2:" << endl;
    matrix2.Print();

   
    Matrix<int> sumMatrix = matrix1.Add(matrix2);
    Matrix<int> diffMatrix = matrix1.Subtract(matrix2);
    Matrix<int> productMatrix = matrix1.Multiply(matrix2);
    Matrix<int> quotientMatrix = matrix1.Divide(matrix2);
  
    cout << "Sum " << endl;
    sumMatrix.Print();
    cout << "Difference :" << endl;
    diffMatrix.Print();
    cout << "Product " << endl;
    productMatrix.Print();
    cout << "Quotient " << endl;
    quotientMatrix.Print();

    return 0;
}