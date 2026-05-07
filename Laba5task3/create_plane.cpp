#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void CREATE_PLANE(map<string, vector<string>>& planes,
                  map<string, vector<string>>& towns,
                  const vector<string>& tokens)
{
    if (tokens.size() < 4)
    {
        cout << "Ошибка: Неверная команда\n";
        return;
    }
    string plane = tokens[1];
    int count = stoi(tokens[2]);
    if (planes.find(plane) != planes.end())
    {
        cout << "Ошибка: Самолет с именем " << plane << " уже создан\n";
        return;
    }
    if (count < 2)
    {
        cout << "Ошибка: Самолет не может быть создан менее чем с двумя городами\n";
        return;
    }
    if (tokens.size() != 3 + count)
    {
        cout << "Ошибка: Неверное количество городов\n";
        return;
    }
    vector<string> route;
    for (int i = 3; i < tokens.size(); i++)
    {
        if (find(route.begin(), route.end(), tokens[i]) != route.end())
        {
            cout << "Ошибка: Самолет не может проходить через один город дважды\n";
            return;
        }
        route.push_back(tokens[i]);
    }
    planes[plane] = route;
    for (int i = 0; i < route.size(); i++)
    {
        towns[route[i]].push_back(plane);
    }

    cout << "Самолет " << plane << " создан\n";
}