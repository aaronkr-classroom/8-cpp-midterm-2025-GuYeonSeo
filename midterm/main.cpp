#include <iostream>
#include <vector>
#include <sstream>
#include "functions.h"

int main() {
	int student_num;
	std::cout << "�л� ���� �Է��Ͻÿ� : ";
	std::cin >> student_num;
	std::cin.ignore();

	std::vector<Student> student;

	for (int i = 0; i < student_num; ++i) {
		Student stu;
		std::cout << "\n== �л� " << i + 1 << " ==\n";

		std::cout << "�̸��� �Է��Ͻÿ� : ";
		std::getline(std::cin, stu.name);

		std::cout << "���� ������ �Է��Ͻÿ�(���ڰ� �ƴ� ���� �Է��ϸ� ����) : ";
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

	std::cout << "\n--- ���� ���(�̸� �� ����) ---\n\n";
	for (const auto& stu : student) {
		std::cout << stu.name << ": " << stu.avg << "\n";
	}
	return 0;
}
