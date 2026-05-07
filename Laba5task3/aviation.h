#ifndef AVIATION_H
#define AVIATION_H
#pragma once
#include <map>
#include <string>
#include <vector>

enum class Type
{
    CREATE_PLANE,
    PLANES_FOR_TOWN,
    TOWNS_FOR_PLANE,
    PLANES,
    UNKNOWN
};
Type parseCommand(const std::string& command);
void CREATE_PLANE(std::map<std::string, std::vector<std::string>>& planes,
                  std::map<std::string, std::vector<std::string>>& towns,
                  const std::vector<std::string>& tokens);
void PLANES_FOR_TOWN(std::map<std::string, std::vector<std::string>>& towns, const std::string& town);
void PLANES(std::map<std::string, std::vector<std::string>>& planes);
void TOWNS_FOR_PLANE(std::map<std::string, std::vector<std::string>>& planes,
                     std::map<std::string, std::vector<std::string>>& towns,
                     const std::string& plane);


#endif