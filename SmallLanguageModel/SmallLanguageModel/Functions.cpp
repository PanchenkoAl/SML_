#include "Functions.h"
#include "Questions_C.h"
#include "Answers_C.h"  
#include <regex>
#include <ctime>
#include <iostream>

std::string human_name = "stranger";
std::map<std::string, std::pair<std::string, std::vector<std::string>>> question_answer;

std::string what_time() 
{
    std::time_t t = std::time(nullptr);
    char time_str[10];
    return std::string("Huh?");
}

std::string what_date() 
{
    std::time_t t = std::time(nullptr);
    char date_str[11];

    return std::string("Huh?");
}

void add_new_answer_pattern(const std::string& question_type, const std::string& question) 
{

}

std::vector<std::string> get_answer(const std::string& question) 
{
    for (const auto& [q, t_a] : ANSWER_LISTS)  
    {
        if (std::regex_match(question, std::regex(q))) 
        {
            return t_a; 
        }
    }
    std::vector<std::string> v = { "Something wrong happened! Sorry!" };
    return v;
}

std::vector<std::string> get_emotional_answer(const std::string& question)
{
    for (const auto& [q, t_a] : EMOTIONAL_ANSWER_LISTS)
    {
        if (std::regex_match(question, std::regex(q)))
        {
            return t_a;
        }
    }
    std::vector<std::string> v = { "Something wrong happened! Sorry!" };
    return v;
}

bool findType(std::string s, std::vector<std::string> vs)
{
    for (int i = 0; i < vs.size(); i++)
        if (vs[i] == s)
            return true;
    return false;
}

std::string generateQuestion(std::string message) {
    std::transform(message.begin(), message.end(), message.begin(), ::tolower);

    std::vector <std::string> verbsType_1 = { "play", "watch", "read", "eat", "make" };
    std::vector <std::string> nounsType_1 = { "school", "work", "gym", "school" };

    std::regex actionObjectPattern(R"(i (will|was|am|like|love) (\w+)(?: (a|the|to the|at the))? (\w+))", std::regex::icase);
    std::smatch match;

    if (std::regex_search(message, match, actionObjectPattern)) {
        std::string action = match[2];
        std::string prep = match[3];
        std::string object = match[4];
        bool isFuture = match[1].str() == "will";
        bool isPast = match[1].str() == "was";


        if (action.length() > 3 && action.compare(action.length() - 3, 3, "ing") == 0) {
            action.erase(action.length() - 3);
        }

        if (match[1] == "like" || match[1] == "love")
        {
            return "What " + object + " do you " + match[1].str() + " to " + action + "?";
        }

        if (isPast)
        {
            return "What " + object + " were you " + action + "ing?";
        }
        else if (isFuture)
        {
            return "What " + object + " will you " + action + "?";
        }
        else
        {
            return "What " + object + " are you " + action + "ing?";
        }
    }

    return "That's interesting! Could you tell me more?";
}

std::string get_question_type(const std::string& input) 
{
    
    for (const auto& [pattern_name, pattern] : QUESTION_PATTERNS) 
    {
        try 
        {
            std::regex regex_pattern(pattern); 
            if (std::regex_search(input, regex_pattern)) 
            {
                //std::cout << pattern_name << std::endl;
                return pattern_name;
            }
        }
        catch (const std::regex_error& e) 
        {
            std::cerr << "Regex error: " << e.what() << " for pattern: " << pattern_name << std::endl;
        }
    }

    return "NO_MATCH";
}

std::vector<std::string> what_s_your_name() 
{
    return WHAT_IS_YOUR_NAME;
}

void set_human_name(const std::string& name) 
{
    human_name = name;
    std::cout << "Human name set to: " << human_name << std::endl;
}

std::string get_human_name() 
{
    return human_name;
}
