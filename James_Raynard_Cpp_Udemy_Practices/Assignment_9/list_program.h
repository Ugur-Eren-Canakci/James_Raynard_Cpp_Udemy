#ifndef LIST_PROGRAM_H
#define LIST_PROGRAM_H
#include <list>
#include <string>

class list_program
{
public:
    list_program();
    ~list_program();
    void print_list(const std::list<std::string>& list);
};

#endif // LIST_PROGRAM_H
