// Developer: CoconutMinz
// Edition: RC-con
// Version: 0.7.5
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;
const int SIZE = 6;
const int INTMIN = -2147483648;  // Минимальное значение типа int
int q;
int matrix[SIZE][SIZE];
void reduceSecondaryDiagonal(int matrix[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			// Проверяем, является ли элемент частью побочной диагонали
			if (i + j == SIZE - 1) {
				// Уменьшаем элемент в два раза
				matrix[i][j] /= 2;
			}
		}
	}
}
int findMaxNegative(const int matrix[SIZE][SIZE]) {
	int maxNegative = INTMIN;  // Используем начальное значение, которое гарантированно меньше любого отрицательного числа

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (matrix[i][j] < 0 && matrix[i][j] > maxNegative) {
				maxNegative = matrix[i][j];
			}
		}
	}

	return maxNegative;
}
void case1() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = rand() % 100-100;
			//cout << matrix[i][j] << " ";
		}
		//cout << endl;
	}
}
void case2() {
	cout << "Filling in the matrix from the keyboard" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Enter the " << i + 1 << " line of the matrix" << endl;
		for (int j = 0; j < SIZE; j++) {
			cin >> matrix[i][j];
		}
	}
}
void case3() {
	cout << "Filling in a matrix from a file" << endl;
	ifstream file("matrix.txt");
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	else {
		for (int i = 0; i < SIZE; i++) {
			cout << "Enter the " << i + 1 << " line of the matrix" << endl;
			for (int j = 0; j < SIZE; j++) {
				file >> matrix[i][j];
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
}
void maxmenu() {
	cout<<"\t\tMenu"<<endl;
	cout<<"Select the method of filling the matrix:" << endl;
	cout << "1. Filling in the matrix randomly" << endl;
	cout << "2. Filling in the matrix from the keyboard" << endl;
	cout << "3. Filling in a matrix from a file" << endl;
	cin>>q;
}
int main() {
	maxmenu();
	switch (q) {
		case 1:
			case1();
			break;
		case 2:
			case2();
			break;
		case 3:
			case3();
			break;
		default:
			cout << "Error" << endl;
			main();
			break;
	}
	int maxNegative = findMaxNegative(matrix);
    cout<<"Original matrix"<<endl;
    for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout<<matrix[i][j]<<" 1";
			}
            cout<<endl;
		}
        cout<<endl;
	if (maxNegative != INTMIN) {
		cout << "Min number: " << maxNegative << endl;
		cout << endl;
	}
	else {
		cout << "number not exit." << endl;
		cout << endl;
	}
	reduceSecondaryDiagonal(matrix);
	cout << "Matrix after reduce secondary diagonal:" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//cout<<"Made by CoconutMinz!"<<endl;
    cout<<"Сделал: Грибанов Александр. Группа ТИ-318. Вариант №17"<<endl;
	cout<<"Version: 0.7.5"<<endl;
	return 0;
}
