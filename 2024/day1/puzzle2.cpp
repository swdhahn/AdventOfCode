#include <cstring>
#include <fstream>
#include <iostream>
#include <forward_list>
#include <map>

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

	std::map<int, int> sim;
	for(auto l = leftList.begin(); l != leftList.end(); ++l) {
		sim[(*l)] = 0;
	}
	for(auto l = leftList.begin(); l != leftList.end(); ++l) {
		for(auto r = rightList.begin(); r != rightList.end(); ++r) {
			if((*r) == (*l)) {
				sim[(*l)] = sim[(*l)] + 1;
			}
		}
	}
	int totalScore = 0;
	for(auto it = sim.begin(); it != sim.end(); ++it) {
		totalScore += it->first * it->second;
	}

	std::cout << totalScore << std::endl;

	return 0;
}

