#include <iostream>
#include <algorithm>
#include "square.h"
#include "conteiners/list.h"

int main() {
    size_t N;
    float S;
    char option = '0';
    containers::list<Square<int>> q;
    Square<int> kva{};
    while (option != 'q') {
        std::cout << "выберите опцию (m for man, q to quit)" << std::endl;
        std:: cin >> option;
        switch (option) {
            case 'q':
                break;
            case 'm': {
                std::cout << "1. Добавить фигуру в начало списка\n"
                 << "2. Добавить фигуру в конец списка\n"
                 << "3. Добавить фигуру по индексу\n"
                 << "4. Удалить фигуру в начале списка\n"
                 << "5. Удалить фигуру в конце списка\n"
                 << "6. Удалить фигуру по индексу\n"
                 << "7. Вывести первую фигуру в списке\n"
                 << "8. Вывести последнюю фигуру в списке\n"
                 << "9. Вывести фигуру по индексу\n"
                 << "o. Вывести все фигуры\n"
                 << "a. Вывести кол-во фигур чья площаль больше чем ...\n";
                break;
            }
            case '1':{
                std::cout << "введите вершины квадрата: " << std::endl;
                kva = Square<int>(std::cin);
                try{
                    kva.Check();
                }catch(std::logic_error& err1){
                    std::cout << err1.what() << std::endl;
                    break;
                }
                try{
                    q.push_front(kva);}
                catch(std::logic_error& err2){
                    std::cout << err2.what()<<std::endl;
                    break;
                }
                break;


            }
            case '2': {
                std::cout << "введите вершины квадрата: " << std::endl;
                kva = Square<int>(std::cin);
                try {
                    kva.Check();
                } catch (std::logic_error &err3) {
                    std::cout << err3.what() << std::endl;
                    break;
                }
                try {
                    q.push_back(kva);
                }
                catch (std::logic_error &err4) {
                    std::cout << err4.what() << std::endl;
                    break;
                }
                break;
            }

            case '3': {
                std::cout << "позиция для вставки: ";
                std::cin >> N;
                std::cout << "введите квадрат: \n";
                kva = Square<int>(std::cin);
                try {
                    kva.Check();
                } catch (std::logic_error &err5) {
                    std::cout << err5.what() << std::endl;
                    break;
                }
                try {
                    q.insert_by_number(N , kva);
                }
                catch (std::logic_error &err6) {
                    q.delete_by_number(N);
                    std::cout << err6.what() << std::endl;
                    break;
                }
                break;
            }
            case '4': {
                q.pop_front();
                break;
            }
            case '5': {
            q.pop_back();
            break;
            }
            case '6': {
            std::cout << "позиция для удаления: ";
            std::cin >> N;
            q.delete_by_number(N);
            break;
            }
            case '7': {
            q.top_front().Printout(std::cout);
            break;
            }
            case '8': {
            q.top_back().Printout(std::cout);
            break;
            }
            case '9': {
            std::cout << "введите индекс элемента: ";
            std::cin >> N;
            q[N].Printout(std::cout);
            break;
            }
            case 'o': {
            std::for_each(q.begin(), q.end(), [](Square<int> &X) { X.Printout(std::cout); });
            break;
            }
            case 'a': {
                std::cout << "площадь для сравнения: ";
                std::cin >> S;
                std::cout <<"количестов элементов с площадью меньше чем " << S << " :" << std::count_if(q.begin(), q.end(), [=](Square<int>& X){return X.Area() < S;}) << std::endl;
            break;
            }
            default:
                break;
        }
    }
    return 0;
}
