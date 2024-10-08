#pragma once
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include <map>
#include <vector>

std::string what_time();
std::string what_date();
void add_new_answer_pattern(const std::string& question_type, const std::string& question);
std::vector<std::string> get_answer(const std::string& question);
std::vector<std::string> get_emotional_answer(const std::string& question);
std::string get_question_type(const std::string& question);
std::vector<std::string> what_s_your_name();
void set_human_name(const std::string& name);
std::string get_human_name();
std::string generateQuestion(std::string message);
bool findType(std::string s, std::vector<std::string> vs);

extern std::string human_name;
extern std::map<std::string, std::pair<std::string, std::vector<std::string>>> question_answer;

#endif


