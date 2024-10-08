#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <cstdlib>  
#include <ctime>    
#include <sstream>
#include "Constants.h"
#include "Functions.h"
#include "Questions_C.h"
#include "Answers_C.h"

std::vector<std::string> last_questions;

template <typename T>
T get_random_choice(const std::vector<T>& choices) 
{
    return choices[rand() % choices.size()];
}

std::string findEmotions(std::vector<std::string> lq)
{
    for (std::string s : lq)
    {
        int counter = 0;
        for (std::string ss : lq)
            if (s == ss)
                counter++;
        if (counter >= 4)
            return s;
    }
    return "NONE";
}

int main() 
{
    std::string ANNOYANCE_LEVEL = "NONE";
    std::string TIREDNESS_LEVEL = "NONE";
    std::string DELIGHTNESS_LEVEL = "NONE";
    int annoyance_l = 0;
    int tiredness_l = 0;
    int delightness_l = 0;
    //int SARCASTIC_DELIGHTNESS_LEVEL = 0;

    srand(static_cast<unsigned>(time(0)));

    for (const auto& [key, value] : QUESTION_PATTERNS) 
    {
        add_new_answer_pattern(key, value);
    }

    std::cout << "Looks like you've started a conversation..." << std::endl;

    std::string e_type = "NONE";

    bool casualFlag = false;

    while (true) 
    {
        std::string humans_input;

        if (get_human_name() == "stranger") 
        {
            std::cout << get_random_choice(what_s_your_name()) << std::endl;
            std::getline(std::cin, humans_input);
        }
        else {
            std::cout << "> ";
            std::getline(std::cin, humans_input);
        }

        //std::transform(humans_input.begin(), humans_input.end(), humans_input.begin(), ::tolower);

        std::string q_type = get_question_type(humans_input);

        if (std::find(last_questions.begin(), last_questions.end(), q_type) != last_questions.end() && false) 
        {

        }
        else 
        {
            if (last_questions.size() >= 7) 
            {
                last_questions.erase(last_questions.begin());
            }
            last_questions.push_back(q_type);

            e_type = "NONE";
            e_type = findEmotions(last_questions);

            if (casualFlag)
            {
                std::vector<std::string> casualAnswer = { "So exciting", "Really interesting", "Just amazing" };
                std::cout << get_random_choice(casualAnswer) << std::endl;
                casualFlag = false;
                continue;
            }

            if (q_type == "CASUAL_QUESTION")
            {
                //std::vector<std::string> answer;
                //answer.push_back(generateQuestion(humans_input));
                std::cout << generateQuestion(humans_input) << std::endl;
                casualFlag = true; 
                continue;
            }

            if (e_type != "NONE")
            {
                if (e_type == SELF_NEGATIVE_EMOTIONS || e_type == OTHER_NEGATIVE_EMOTIONS || e_type == POSITIVE_EMOTIONS)
                {
                    if (ANNOYANCE_LEVEL == "NONE")
                        ANNOYANCE_LEVEL = "MILD_ANNOYANCE";
                    else
                    if (ANNOYANCE_LEVEL == "MILD_ANNOYANCE")
                        ANNOYANCE_LEVEL = "MODERATE_ANNOYANCE";
                    else
                    if (ANNOYANCE_LEVEL == "MODERATE_ANNOYANCE")
                        ANNOYANCE_LEVEL = "HIGH_ANNOYANCE";
                }
                else if (e_type == DELIGHTS)
                {
                    if (DELIGHTNESS_LEVEL == "NONE")
                        DELIGHTNESS_LEVEL = "MILD_DELIGHT";
                    else
                    if (DELIGHTNESS_LEVEL == "MILD_DELIGHT")
                        DELIGHTNESS_LEVEL = "MODERATE_DELIGHT";
                    else
                    if (DELIGHTNESS_LEVEL == "MODERATE_DELIGHT")
                        DELIGHTNESS_LEVEL = "HIGH_DELIGHT";
                }
                else
                {
                    if (TIREDNESS_LEVEL == "NONE")
                        TIREDNESS_LEVEL = "MILD_TIREDNESS";
                    else
                    if (TIREDNESS_LEVEL == "MILD_TIREDNESS")
                        TIREDNESS_LEVEL = "MODERATE_TIREDNESS";
                    else
                    if (TIREDNESS_LEVEL == "MODERATE_TIREDNESS")
                        TIREDNESS_LEVEL = "HIGH_TIREDNESS";
                }
            }

           
            if (ANNOYANCE_LEVEL != "NONE" && (q_type == SELF_NEGATIVE_EMOTIONS || q_type == OTHER_NEGATIVE_EMOTIONS || q_type == POSITIVE_EMOTIONS))
            {
                std::vector<std::string> e_answer;
                std::vector<std::string> e_wild = get_emotional_answer(ANNOYANCE_LEVEL);
                e_answer.push_back(get_random_choice(e_wild));
                std::cout << e_answer[e_answer.size() - 1] << std::endl;
                continue;
            }

            if (DELIGHTNESS_LEVEL != "NONE" && q_type == DELIGHTS)
            {
                std::vector<std::string> e_answer;
                std::vector<std::string> e_wild = get_emotional_answer(DELIGHTNESS_LEVEL);
                e_answer.push_back(get_random_choice(e_wild));
                std::cout << e_answer[e_answer.size() - 1] << std::endl;
                continue;
            }

            if (TIREDNESS_LEVEL != "NONE" && e_type == q_type)
            {
                std::vector<std::string> e_answer;
                std::vector<std::string> e_wild = get_emotional_answer(TIREDNESS_LEVEL);
                e_answer.push_back(get_random_choice(e_wild));
                std::cout << e_answer[e_answer.size() - 1] << std::endl;
                continue;
            }

            if (q_type == MEETING) 
            {

                std::vector<std::string> words;
                std::istringstream iss(humans_input);
                std::string word;
                while (iss >> word) {
                    words.push_back(word);
                }

                set_human_name(words.back());

                std::vector<std::string> answer;
                WILDCARD = get_answer(q_type);
                answer.push_back(get_random_choice(WILDCARD));
                std::string final_answer = get_random_choice(answer) + ", " + get_human_name();
                std::cout << final_answer << std::endl;

                continue;
            }

             

            std::vector<std::string> answer;
            WILDCARD = get_answer(q_type);
            //std::cout << q_type << std::endl;
            answer.push_back(get_random_choice(WILDCARD));
            std::cout << answer[answer.size() - 1] << std::endl;
            //std::cout << get_random_choice(answer) << std::endl;

            if (q_type == GOOD_BYE) 
            {
                exit(0);
            }
        }
    }

    return 0;
}
