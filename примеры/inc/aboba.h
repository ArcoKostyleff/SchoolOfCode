// моя библиотека
#pragma once
#include <string>
#include <iostream>
struct complex {
    double x{};
    double y{};
    complex(double x, double y) {
        this->x = x;
        this->y = y;
    }
    complex() {};
};


void printAboba(std::string s);
void aboba();
void aboba(std::string s);
