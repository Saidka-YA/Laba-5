#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void TOWNS_FOR_PLANE(map<string, vector<string>>& planes,
                     map<string, vector<string>>& towns,
                     const string& plane)
{
    if (planes.find(plane) == planes.end())
    {
        cout << "Ошибка: Самолет " << plane << " не найден\n";
        return;
    }
    cout << "Города самолета " << plane << ": ";
    for (int i = 0; i < planes[plane].size(); i++)
    {
        cout << planes[plane][i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < planes[plane].size(); i++)
    {
        string town = planes[plane][i];
        cout << "Город " << town << ": ";
        bool found = false;
        for (int j = 0; j < towns[town].size(); j++)
        {
            if (towns[town][j] != plane)
            {
                cout << towns[town][j] << " ";
                found = true;
            }
        }
        if (!found)
        {
            cout << "-";
        }
        cout << "\n";
    }
}
