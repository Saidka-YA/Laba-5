#ifndef SCLAD_H
#define SCLAD_H
#pragma once
#include <utility>
#include <map>
#include <string>

void initialiazeSclad(std::map<std::string, std::pair<std::string, int>>& sclad);

void ADD(std::map<std::string, std::pair<std::string, 
        int>>& sclad, const std::string& nameOfProduct, 
        const int& quantityProduct, const std::string& address);

void REMOVE(std::map<std::string, std::pair<std::string, int>>& sclad, 
        const std::string& nameOfProduct, 
        const int& quantityProduct, const std::string& address);

void INFO(std::map<std::string, std::pair<std::string, int>>& sclad);

#endif