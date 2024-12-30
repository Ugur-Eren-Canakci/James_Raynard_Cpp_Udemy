#ifndef DEQUE_PROGRAM_H
#define DEQUE_PROGRAM_H

#include <deque>
#include <string>

class deque_program
{
public:
    deque_program();
    ~deque_program();
    void print_deque(const std::deque<std::string>& deque);
};

#endif // DEQUE_PROGRAM_H
