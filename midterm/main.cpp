#include <iostream>
#include <vector>
#include <sstream>
#include "functions.h"

int main() {
	int student_num;
	std::cout << "학생 수를 입력하시오 : ";
	std::cin >> student_num;
	std::cin.ignore();

	std::vector<Student> student;

	for (int i = 0; i < student_num; ++i) {
		Student stu;
		std::cout << "\n== 학생 " << i + 1 << " ==\n";

		std::cout << "이름을 입력하시오 : ";
		std::getline(std::cin, stu.name);

		std::cout << "과제 점수를 입력하시오(숫자가 아닌 값을 입력하면 종료) : ";
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string token;
		int count = 0;

		while (iss >> token) {
			if (!number(token))
				break;
			if (count >= 5)
				break;
			stu.score.push_back(std::stoi(token));
			count++;
		}
		stu.avg = average(stu.score);
		student.push_back(stu);
	}
	student_name(student);

	std::cout << "\n--- 성적 요약(이름 순 정렬) ---\n\n";
	for (const auto& stu : student) {
		std::cout << stu.name << ": " << stu.avg << "\n";
	}
	return 0;
}
