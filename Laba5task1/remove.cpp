#include "sclad.h"
#include <map>
#include <utility>
#include <string>
#include <iostream>
using namespace std;
void REMOVE(map<string, pair<string, int>>& sclad, const string& nameOfProduct, 
    const int& quantityProduct, const string& address)
{
    if (sclad.find(address) == sclad.end())
    {
        cout << "Ошибка: несуществующий адрес!";
        return;
    }
    if (sclad[address].first == "")
    {
        cout << "Ошибка: Товар " << nameOfProduct << " не найден в ячейке " << address;
        return;
    } 
    if (sclad[address].first != nameOfProduct)
    { 
        cout << "Ошибка: в ячейке другой товар!";
        return;
    }  
    if (quantityProduct > sclad[address].second)
    {
        cout << "Ошибка: недостаточно товаров для удаления";
        return;
    }
    sclad[address].second -= quantityProduct;
    cout << "Удалено " << quantityProduct << " " << nameOfProduct << " ( " << "остаток: " << sclad[address].second << ")";
    if (sclad[address].second == 0)
    {
        sclad[address].first = "";
    }
}