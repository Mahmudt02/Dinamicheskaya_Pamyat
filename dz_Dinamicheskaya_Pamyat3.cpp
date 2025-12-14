#include <iostream>
#include <iomanip>
#include <locale>


int** create_two_dim_array(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return nullptr;
    }

   
    int** matrix = new int* [rows];

    
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    return matrix;
}



void fill_two_dim_array(int** matrix, int rows, int cols) {
    if (matrix == nullptr) {
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }
}



void print_two_dim_array(int** matrix, int rows, int cols) {
    if (matrix == nullptr) {
        std::cout << "Массив пуст или не был создан." << std::endl;
        return;
    }

   
    const int W = 4;
    std::cout << "Таблица умножения:" << std::endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(W) << matrix[i][j];
        }
        std::cout << std::endl; 
    }
}

void delete_two_dim_array(int**& matrix, int rows, int cols) {
    if (matrix == nullptr) {
        return;
    }

    
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    
    delete[] matrix;

    
    matrix = nullptr;
} 


int main() {
     std::setlocale(LC_ALL, "Russian"); 
    int rows, cols;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cerr << "Количество строк и столбцов должно быть положительным." << std::endl;
        return 1;
    }

   
    int** table = create_two_dim_array(rows, cols);

    fill_two_dim_array(table, rows, cols);

    print_two_dim_array(table, rows, cols);

   
    delete_two_dim_array(table, rows, cols);

    return 0;
}
