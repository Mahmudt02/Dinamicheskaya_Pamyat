#include <iostream>
#include <iomanip>
#include <locale>

double* create_array(int size) {
    
    if (size <= 0) {
       
        return nullptr;
    }

    
    double* dynamic_array = new double[size];

    
    for (int i = 0; i < size; ++i) {
        dynamic_array[i] = 0.0;
    }

    return dynamic_array;
}

int main() {

    std::setlocale(LC_ALL, "Russian");
    int size;

   
    std::cout << "Введите размер массива: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cerr << "Некорректный размер массива." << std::endl;
        return 1;
    }

   
    double* my_array = create_array(size);

   
    if (my_array == nullptr) {
        std::cerr << "Ошибка при создании массива." << std::endl;
        return 1;
    }

   
    std::cout << "Массив: ";
   
    std::cout << std::fixed << std::setprecision(0);
    for (int i = 0; i < size; ++i) {
        std::cout << my_array[i] << " ";
    }
    std::cout << std::endl;

  
    delete[] my_array;
    my_array = nullptr; 

    return 0;
}
