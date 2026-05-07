#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <vector>
#include <string>

int daysInMonth(int month);
void CLASS(std::vector<std::vector<std::string>>& schedule, int day, const std::string& subject);
void NEXT(std::vector<std::vector<std::string>>& schedule, int& currentMonth);
void VIEW(std::vector<std::vector<std::string>>& schedule, int day);

#endif