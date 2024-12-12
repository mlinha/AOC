#include "recursive_parser.h"

char RecursiveParser::get_next()
{
    return input[index];
}

void RecursiveParser::process_m()
{
    first = 0;
    second = 0;
    should_disable_multiply = false;
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == 'u')
    {
        process_u();
    }
    reset_process(next);
}

void RecursiveParser::process_u()
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == 'l')
    {
        process_l();
    }
    reset_process(next);
}

void RecursiveParser::process_l()
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == '(')
    {
        process_open_bracket();
    }
    reset_process(next);
}

void RecursiveParser::process_open_bracket()
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (std::isdigit(next))
    {
        std::string s{next};
        process_first_number(s);
    }
    reset_process(next);
}

void RecursiveParser::process_first_number(std::string num)
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (std::isdigit(next))
    {
        if (num.size() == 3)
        {
            process_invalid();
        }
        else
        {
            std::string s{next};
            process_first_number(num + s);
        }
    }
    else if (next == ',')
    {
        first = std::stoi(num);
        process_comma();
    }
    reset_process(next);
}

void RecursiveParser::process_comma()
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (std::isdigit(next))
    {
        std::string s{next};
        process_second_number(s);
    }
    reset_process(next);
}

void RecursiveParser::process_second_number(std::string num)
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (std::isdigit(next))
    {
        if (num.size() == 3)
        {
            process_invalid();
        }
        else
        {
            std::string s{next};
            process_second_number(num + s);
        }
    }
    else if (next == ')')
    {
        second = std::stoi(num);
        process_close_bracket();
    }
    reset_process(next);
}

void RecursiveParser::process_close_bracket()
{
    result = result + (first * second);
    if (should_multiply)
    {
        result_better = result_better + (first * second);
    }
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    reset_process(next);
}

void RecursiveParser::process_invalid()
{
    first = 0;
    second = 0;
    should_disable_multiply = false;
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    reset_process(next);
}

void RecursiveParser::start()
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == 'm')
    {
        process_m();
    }
    else if (next == 'd')
    {
        process_d();
    }
    else
    {
        process_invalid();
    }
}

void RecursiveParser::process_d()
{
    first = 0;
    second = 0;
    should_disable_multiply = false;
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == 'o')
    {
        process_o();
    }
    reset_process(next);
    
}

void RecursiveParser::process_o()
{
    should_disable_multiply = false;
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == 'n')
    {
        process_n();
    }
    else if (next == '(')
    {
        process_open_bracket_modifier();
    }
    reset_process(next);
}

void RecursiveParser::process_open_bracket_modifier()
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == ')')
    {
        process_close_bracket_modifier();
    }
    reset_process(next);
}

void RecursiveParser::process_close_bracket_modifier()
{
    if (should_disable_multiply)
    {
        should_multiply = false;
    }
    else
    {
        should_multiply = true;
    }
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    reset_process(next);
}

void RecursiveParser::process_n()
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == '\'')
    {
        process_quote();
    }
    reset_process(next);
}

void RecursiveParser::process_quote()
{
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == 't')
    {
        process_t();
    }
    reset_process(next);
}

void RecursiveParser::process_t()
{
    should_disable_multiply = true;
    if (index == input.size())
    {
        return;
    }
    char next = get_next();
    index++;
    if (next == '(')
    {
        process_open_bracket_modifier();
    }
    reset_process(next);
}

void RecursiveParser::reset_process(char next)
{
    if (next == 'm')
    {
        process_m();
    }
    else if (next == 'd')
    {
        process_d();
    }
    else
    {
        process_invalid();
    }
}

int RecursiveParser::get_result()
{
    return result;
}

int RecursiveParser::get_result_better()
{
    return result_better;
}