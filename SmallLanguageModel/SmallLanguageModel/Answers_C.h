#pragma once
#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <string>
#include <vector>
#include <map>

	std::string choice(const std::vector<std::string>& vec);

	extern std::vector<std::string> BECAUSE_PART_1;
	extern std::vector<std::string> BECAUSE_PART_2;
	extern std::vector<std::string> PEOPLE_PART;

	extern std::vector<std::string> AND_YOU;
	extern std::vector<std::string> GRUMPY_GOBLIN;
	extern std::vector<std::string> WILDCARD;

	extern std::vector<std::pair<std::string, std::vector<std::string>>> ANSWER_LISTS;

	extern std::vector<std::pair<std::string, std::vector<std::string>>> EMOTIONAL_ANSWER_LISTS;

	extern std::vector<std::string> WHAT_IS_YOUR_NAME;

#endif // DIALOGUE_HPP

