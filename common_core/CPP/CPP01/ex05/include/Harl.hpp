#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>

#ifndef DEBUG_MESSAGE
# define DEBUG_MESSAGE "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#endif
#ifndef INFO_MESSAGE
# define INFO_MESSAGE  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#endif
#ifndef WARNING_MESSAGE
# define WARNING_MESSAGE "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
#endif
#ifndef ERROR_MESSAGE
# define ERROR_MESSAGE "This is unacceptable! I want to speak to the manager now."
#endif

class Harl {
private :
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public :
    void complain(std::string level);
};

#endif