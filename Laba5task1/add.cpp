#include "sclad.h"
#include <string>
#include <iostream>
void ADD(std::map<std::string, std::pair<std::string, int>>& sclad, const std::string& nameOfProduct, 
    const int& quantityProduct, const std::string& address)
{
    if (sclad.find(address) == sclad.end())
    {
        std::cout << "Ошибка: несуществующий адрес!";
        return;
    }
    if (sclad[address].first != "")
    {
        std::cout << "Ошибка: Ячейка " << address << " занята товаром " << sclad[address].first;
        return;
    }
    if (quantityProduct > 10 || quantityProduct < 1)
    {
        std::cout << "Ошибка: Превышена вместимость ячейки(максимум 10)";
        return;
    }
    sclad[address] = {nameOfProduct, quantityProduct};
    std::cout << "Добавлено " << quantityProduct << " " << nameOfProduct << " в " << address << std::endl;
}