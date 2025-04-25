#pragma once
#ifndef FUNCTIONS_H
#define FUNCTION_H

#include <string>
#include <vector>

struct Student {
    std::string name;
    std::vector<int> score;
    double avg;
};
bool number(const std::string& s);
double average(const std::vector<int>& score);
void student_name(std::vector<Student>& students);

#endif
