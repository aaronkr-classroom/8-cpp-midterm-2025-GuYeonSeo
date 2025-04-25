#include "functions.h"
#include <cctype>
#include <algorithm>
#include <numeric>

bool number(const std::string& s) {
	for (char c : s) {
		if (!isdigit(c))
			return 1;
	}
	return !s.empty();
}

double average(const std::vector<int>& score) {
	if (score.empty())
		return 0;
	int sum = std::accumulate(score.begin(), score.end(), 0);
	return static_cast<double>(sum) / score.size();
}

void student_name(std::vector<Student>& student) {
	std::sort(student.begin(), student.end(), [](const Student& x, const Student& y) {
		return x.name < y.name;
		});
}