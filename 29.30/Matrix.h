#include <iostream>
#include <ctime> //��������� ��������� �����
using namespace std;

// ���������� � ����������� ���������� ������ Matrix.
template <typename T>
class Matrix {
    T** arr;   // ��������� ������������ ������ ��� �������� ��������� �������
    int rows;  
    int cols;  

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        arr = new T * [rows];   // ��������� ������ ��� ��������� �� ������.
        for (int i = 0; i < rows; ++i) {
            arr[i] = new T[cols];  // ��������� ������ ��� ������ ������.
        }
    }

    // ����������� ������, ���������� ��� �������.
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i]; 
        }
        delete[] arr; 
    }

    
    T Get(int r, int c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return arr[r][c];
        }
        return T();  
    }

    void Set(int r, int c, T value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            arr[r][c] = value;
        }
    }

    
    void Rand() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = rand() % 50 + 1;  // ���������� ��������� ����� 
            }
        }
    }

    void Input() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element"  << i << j;
                cin >> arr[i][j];
            }
        }
    }

    // ����� ������� �� �����
    void Print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "\t" << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    
    Matrix<T> Add(const Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Matrix dimensions do not match for addition." << endl;
            return *this;  // ���������� ������� �������, ���� ������� �� ���������.
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] + other.arr[i][j];
            }
        }
        return result;
    }

    Matrix<T> Subtract(const Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Matrix dimensions do not match for subtraction." << endl;
            return *this;  
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] - other.arr[i][j];
            }
        }
        return result;
    }
    Matrix<T> Multiply(const Matrix<T>& other) {
        if (cols != other.rows) {
            return *this;  
        }

        Matrix<T> result(rows, other.cols);  

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.arr[i][j] = 0;  // �������������� ������� ���������� �����.

                for (int k = 0; k < cols; ++k) {
                    result.arr[i][j] += arr[i][k] * other.arr[k][j];  // ��������� 
                }
            }
        }

        return result;
    }

    Matrix<T> Divide(const Matrix<T>& other) {
        

        Matrix<T> result(rows, cols);  
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (other.arr[i][j] != 0) {
                    result.arr[i][j] = arr[i][j] / other.arr[i][j];  // ������������ �������.
                }
                else {
                  
                    return *this;  // ������� �� 0-����� �������
                }
            }
        }

        return result;
    }
};
