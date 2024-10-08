#include "Questions_C.h"

std::vector<std::pair<std::string, std::string>> QUESTION_PATTERNS = {
        {"HOW_ARE_YOU", R"(how are you (doing|feeling)?|what's up|are you (okay|fine)\?)"},
        {"GREETING", R"(welcome|hi|what's up|hello|good (mornin('|g)|day|evening|night)|greetings)"},
        {"CASUAL_QUESTION", R"(i (will|was|am|like|love) (\w+)(?: (a|the|to the|at the))? (\w+))"},
        {"SELF_NEGATIVE_EMOTIONS", R"(i('m| am) (sad|disappointed|cold|defeated|desperate|insecure|discouraged|lonely|confused|unhappy|paranoid))"},
        {"OTHER_NEGATIVE_EMOTIONS", R"(i('m| am) (angry|bored|jealous|egocentric|egoistical|vicious|selfish))"},
        {"POSITIVE_EMOTIONS", R"(i('m| am) (grateful|happy|joyful|loved|beautiful|pleased|loving))"},
        {"DELIGHTS", R"(you('re| are) (grateful|joyful|chill|nice|good|fine|exciting))"},
        {"MEETING", R"((my name is)|(i('m| am)) ([A-Z][a-z]*))"},
        {"WHY_QUESTION", R"(why (will|would|can|did|do|does|am|is|are) ([\w\s]+)\?)"},
        {"WHAT_TIME", R"(what (time is it|is the time|o'clock is it)\?)"},
        {"WHAT_DAY", R"(what (day is it|'s the date today|day is today)\?)"},
        {"WHO_ARE_YOU", R"((who are you\?|what's your name\?))"},
        {"WHAT_QUESTION", R"((what|who|whom|whose) (will|would|can|did|do|does|am|is|are) ([\w\s]+)\?)"},
        {"WHEN_QUESTION", R"(when (would|can|did|do|are|is|am|does|will) ([\w\s]+)\?)"},
        {"GOOD_BYE", R"(bye|good bye|i'm leaving|i'm out|have a nice (day|morning|night))"},
        {"CAN_QUESTIONS", R"(can|would|might you ([\w\s]*)\?)"},
        {"TYPE_WHAT", R"((I (am'm)) playing|lisening|reading|writing|searching|watching|)"},
        {"UNKNOWN_EMOTIONS", R"(i('m| am)([\w\s]*))"},
        {"UNKNOWN_PHRASE", R"([\w\s]*)"}                                                                        
};


