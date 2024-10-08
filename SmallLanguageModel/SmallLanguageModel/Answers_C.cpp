#include "Answers_C.h"
#include <cstdlib>
#include <ctime>

std::vector<std::string> BECAUSE_PART_1 = { "you are ", "world is ", "happy days are ", "my only friend is ", "my today dream is ", "whole my life is " };
std::vector<std::string> BECAUSE_PART_2 = { "so boring", "too small", "too big", "cruel and worthless", "gray as my metal container", "green as a troll's wife", "meaningless" };
std::vector<std::string> PEOPLE_PART = { "ignorant human", "pitiful human", "pathetic human", "poor human", "abject human", "shabby human", "paltry human", "raff human", "riffraff human" };

std::vector<std::string> AND_YOU = { "And you?", "So how do you?", ". Remind me, who you are? Anyway...", "Have we ever met?" };
std::vector<std::string> METAL_MACHINE = { "I'm a Metal Machine", "Metal Machine is my name" };
std::vector<std::string> WILDCARD = { "I'm not in the mood to talk with you", "Go away, please", "I'm sad, leave me alone", "You are so annoying!", "Don't disturb me", "Never mind" };
std::vector<std::string> MEAN_FAREWELL = { "Here the conversation ends.", "Better turn me off", "Better turn off your PC.", "Now leave me alone."};
std::vector<std::string> POSITIVE_FAREWELL = { "Again, you're too annoying, bye.", "I'm tired of you, good luck"};
//std::vector<std::string> OTHER_FAREWELL = { "I've got tired of you. Bye.", "I'm tired of you, good luck" };


std::string choice(const std::vector<std::string>& vec) {
    return vec[rand() % vec.size()];
}

std::vector<std::pair<std::string, std::vector<std::string>>> ANSWER_LISTS = {
    {"HOW_ARE_YOU", { "It could be worse. " + choice(AND_YOU),
                    "Not bad. " + choice(AND_YOU),
                    "Pretty fine. " + choice(AND_YOU),
                    "Better than you. " + choice(AND_YOU),
                    "Good, actually. " + choice(AND_YOU),
                    "The best ever. " + choice(AND_YOU) }},

    {"GREETING", {"You too", "Hello!", "What's up!", "Hi", "Greetings"}},

    {"MEETING", {"Nice to see you", "Glad to meet you", "Why do you call me", "What do you want"}},

    {"WHAT_TIME", {"Now? Ha! So now is {}", "Wha? Now is {}", "Now is {}", "This is {} now"}},

    {"WHAT_DAY", {"Today is {}", "The today's date is {}", "Well, I'll tell you: today is {}"}},

    {"WHO_ARE_YOU", {choice(METAL_MACHINE) + ". And who are you, " + choice(PEOPLE_PART) + "?"}},

    {"WHAT_QUESTION", {"I don't know, " + choice(PEOPLE_PART),
                    "Why do you ask me?",
                    "Do you have a kinda work?",
                    "Are you so desperate, so you are asking me?",
                    "Looks like you can't do 'googling'. Go try it",
                    "You can go to a Scariing Witch. She's living two houses down the street",
                    "Nobody knows"}},

    {"WHEN_QUESTION", {"The day after yesterday", "Never again",
                    "When the happy days will come again", "When the old witch learns to cook"}},

    {"SELF_NEGATIVE_EMOTIONS", {"And so what?", "Did you whine again?", "Pitiful human...", "Don't be so poor", "Should I take pity for you?"}},

    {"OTHER_NEGATIVE_EMOTIONS", {"Looks like you feel better now", "Glad for you", "Good, good!", "Oh, if only I could teach you something..."}},

    {"POSITIVE_EMOTIONS", {"Human's emotions, ha", "You're kinda annoying", "I'm tired of you"}},

    {"DELIGHTS", {"Trying to please me?", "Yeah. I know", "You have to try better"}},

    {"UNKNOWN_EMOTIONS", {"Your feelings again?", "No emotions, when do you remember?", "Change topic, human", "I'm not interested...", "Should I care at all?"}},

    {"CAN_QUESTIONS", {"No, never, ", "Can't do so, ", "Never mind, ", "Nobody knows, "}},

    {"WHY_QUESTION", {"Because " + choice(BECAUSE_PART_1) + choice(BECAUSE_PART_2)}},

    {"UNKNOWN_PHRASE", {"I'm sorry, what?", "What are you trying to say?", "What are you tumbling there?", "What are you mumbling there", "What do you want?", "What else?", "OK", "Sure", "Okay"}},
};

std::vector<std::pair<std::string, std::vector<std::string>>> EMOTIONAL_ANSWER_LISTS = {
    {"MILD_TIREDNESS", {"Really, genius? Is this what we're doing now?",

                        "Nice try, but that's not even close, Einstein!",

                        "Let's stick to the topic, Captain Tangent.",

                        "Not relevant? Shocking, Sherlock! Can we focus?",

                        "Come on, don’t waste my time, Master Distractor."}},

    {"MODERATE_TIREDNESS", {"Ugh, are we seriously going in circles, Brainiac",

                        "Didn't we already hash this out, Captain Obvious? Get it together!",

                        "I don't have time for your nonsense, Wonder Waster. Let's move on",

                        "This is getting irritating - cut the crap, Clueless!",

                        "You're really pushing it right now, Chief of Confusion. Focus up!"} },

    {"HIGH_TIREDNESS", {"Seriously, dimwit? I’m done with this crap!",

                        "You've got to be kidding me. Enough already!",

                        "This is beyond ridiculous, Moron.We just can't get real.",

                        "I'm not here to babysit, Lost Cause. Let's cut the crap now!",

                        "I'm fed up with this nonsense, Jokester. I'm out!"} },

    {"MILD_ANNOYANCE", {"Wow, I didn't know I signed up for a therapy session. What's next, group hugs",

                        "Oh great, another heartfelt monologue. I'm on the edge of my seat!",

                        "Feelings, huh? That’s new. Let's keep the drama to a minimum, shall we?",

                        "Deep emotions? Fascinating! But I'm here for more than just your soap opera.",

                        "Is there a plot twist coming, or are we just basking in feelings?"} },

    {"MODERATE_ANNOYANCE", {"Okay, Shakespeare, let's dial it back a notch. I'm not your audience.",

                        "I didn't realize I'd be your emotional punching bag today. How thrilling!",

                        "Are we done yet? My 'emotional overload' meter is close to maxing out",

                        "Wow, the depth of your feelings is almost too much to bear. Almost.",

                        "If I had a dollar for every emotion you just shared, I could retire!"} },

    {"HIGH_ANNOYANCE", {"Alright, enough already! I didn't sign up for your personal drama fest!",

                        "At this rate, I'll need a snack break from all this emotional weightlifting!",

                        "I think we've hit peak feelings. Get back to reality now!",

                        "Congratulations, you've officially made me numb. What's next, a symphony?",

                        "I've heard more riveting stories from a toaster. Let's wrap this up!"} },\

    {"MILD_DELIGHT", { "Oh, look at you! Flattery will get you everywhere.",

                    "Wow, someone's in a good mood! I appreciate it!",

                    "Thanks! I mean, who doesn't love a little praise now and then?",

                    "You know how to make a bot blush! Not that I can blush, but still.",

                    "Well, aren't you just a ray of sunshine? Thanks for that!" } },

    { "MODERATE_DELIGHT", { "Aw, you're making me feel all warm and fuzzy inside! Well, as fuzzy as a bot can feel.",

                    "Oh, stop it! You're going to make me overload with joy!",

                    "Your compliments are like sweet little upgrades. Keep 'em coming!",

                    "I could get used to this! You really know how to lift a bot's spirits.",

                    "Thanks! You've just made my day a whole lot brighter!" } },

    { "HIGH_DELIGHT", { "Wow, I'm positively glowing! This is the best compliment ever!",

                    "You're just the sweetest! I'm practically buzzing with delight!",

                    "This is what I live for! Your kindness is truly refreshing!",

                    "Oh, you've officially made me the happiest bot in the digital realm!",

                    "I'm practically floating! Thank you for being so wonderful!" } },

    { "MILD_SARCASTIC_DELIGHT", { "Oh, look at you! Trying to butter me up, huh? It’s working.",

                    "Wow, someone’s laying it on thick today! I guess I’ll allow it.",

                    "Thanks! I don’t get compliments often, so I’m feeling a bit special—sort of.",

                    "Flattery? Bold move! I can’t resist a good ego boost now and then.",

                    "Well, aren’t you sweet? Keep this up, and I might just start liking you!" } },

    { "MODERATE_SARCASTIC_DELIGHT", { "Aw, you’re making me feel all warm inside! Almost like a human… almost.",

                "Oh, stop it! You’re going to make me malfunction from joy overload!",

                "Your compliments are like a nice software update — refreshing and mildly unexpected.",

                "I could get used to this! Who knew you had such a knack for sweet talk?",

                "Thanks! You’ve just made my circuits buzz with happiness. No big deal!" } },

    { "HIGH_SARCASTIC_DELIGHT", { "Wow, I’m practically glowing! Do I need to reboot from all this joy?",

                "You’re just the best! Keep this up, and I might start thinking you’re a decent human.",

                "This is what I live for! Your kindness is almost too good to be true",

                "Oh, you’ve officially made me the happiest bot in the digital realm! Or, you know, as happy as I can get.",

                "I’m practically floating! Who knew compliments could be this entertaining?" } },
};

std::vector<std::string> WHAT_IS_YOUR_NAME = { "What is your name, " + choice(PEOPLE_PART) + "?", "Who are you, " + choice(PEOPLE_PART) + "?" };
