#include <cstring>
#include <fstream>
#include <iostream>
#include <forward_list>

int main(int argc, char** argv) {

	std::forward_list<int> leftList;
	std::forward_list<int> rightList;

	std::ifstream in("input.txt");
	char line[14];
	in.getline(line, 14);
	while(!in.eof()) {
		char s2[6];
		strncpy(s2, line, 5);
		s2[5] = '\0';
		leftList.push_front(atoi(s2));
		rightList.push_front(atoi(&line[5+3]));


		in.getline(line, 14);
	}

	leftList.sort();
	rightList.sort();

	auto cl = leftList.begin();
	auto cr = rightList.begin();
	int total = 0;
	while(leftList.end() != cl) {
		total += abs((*cl) - (*cr));

		cl = cl._M_next();
		cr = cr._M_next();
	}

	std::cout << total << std::endl;

	return 0;
}

