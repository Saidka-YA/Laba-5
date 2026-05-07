#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void PLANES_FOR_TOWN(map<string, vector<string>>& towns, const string& town)
{
    if (towns.find(town) == towns.end())
    {
        cout << "Ошибка: Город " << town << " не найден\n";
        return;
    }
    cout << "Самолеты в городе " << town << ": ";
    for (int i = 0; i < towns[town].size(); i++)
    {
        cout << towns[town][i];
        if (i != towns[town].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "\n";
}