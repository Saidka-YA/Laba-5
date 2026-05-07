#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void CLASS(vector<vector<string>>& schedule, int day, const string& subject)
{
    if (day < 1 || day > schedule.size())
    {
        cout << "Ошибка: В этом месяце всего " << schedule.size() << " дней\n";
        return;
    }
    vector<string>& subjects = schedule[day - 1];
    if (find(subjects.begin(), subjects.end(), subject) != subjects.end())
    {
        cout << "Ошибка: Дисциплина " << subject << " уже есть в этот день\n";
        return;
    }
    subjects.push_back(subject);
    cout << "Добавлена дисциплина " << subject << " на день " << day << "\n";
}