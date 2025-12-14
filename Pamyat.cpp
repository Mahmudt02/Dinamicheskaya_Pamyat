#include <iostream>
#include <vector>
#include <locale>
int main() {
    std::setlocale(LC_ALL, "Russian");
    int size;
    std::cout << "Введите размер массива: ";
    
    std::cin >> size;

    
    if (size <= 0) {
        std::cerr << "Размер массива должен быть положительным числом." << std::endl;
        return 1;
    }

   
    std::vector<int> arr(size);

  
    for (int i = 0; i < size; ++i) {
   
        std::cout << "arr[" << i << "] = ";
     
        std::cin >> arr[i];
    }

    std::cout << "Введённый массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " "); 
    }
    std::cout << std::endl;

    return 0;
}