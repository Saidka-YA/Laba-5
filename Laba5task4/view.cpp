#include <vector>
#include <string>
#include <iostream>
using namespace std;

void VIEW(vector<vector<string>>& schedule, int day)
{
    if (day < 1 || day > schedule.size())
    {
        cout << "Ошибка: В этом месяце всего " << schedule.size() << " дней\n";
        return;
    }
    vector<string>& subjects = schedule[day - 1];
    if (subjects.empty())
    {
        cout << "В день " << day << " мы свободны!\n";
        return;
    }
    cout << "В день " << day << " занятия в университете: ";
    for (int i = 0; i < subjects.size(); i++)
    {
        cout << subjects[i];
        if (i != subjects.size() - 1)
            cout << " ";
    }
    cout << "\n";
}