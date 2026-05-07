#ifndef QUEUE_H
#define QUEUE_H
#pragma once
#include <string>
#include <vector>
#include <utility>

std::string generateTalon(int& counter);
bool compareVisitors(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
void DISTRIBUTE(int windows, std::vector<std::pair<std::string, int>> visitors);

#endif