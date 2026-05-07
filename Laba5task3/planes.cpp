#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void PLANES(map<string, vector<string>>& planes)
{
    if (planes.empty())
    {
        cout << "Ошибка: Самолеты не найдены\n";
        return;
    }
    for (const pair<const string, vector<string>>& element : planes)
    {
        cout << "Самолет " << element.first << ": ";

        for (int i = 0; i < element.second.size(); i++)
        {
            cout << element.second[i] << " ";
        }

        cout << "\n";
    }
}