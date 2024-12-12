#include <string>

class RecursiveParser
{
    private:
        int result = 0;
        int result_better = 0;
        int first = 0;
        int second = 0;
        int index = 0;
        bool should_multiply = true;
        bool should_disable_multiply = false;
        std::string input {""};

        char get_next();
        void process_m();
        void process_u();
        void process_l();
        void process_open_bracket();
        void process_first_number(std::string num);
        void process_second_number(std::string num);
        void process_comma();
        void process_close_bracket();
        void process_d();
        void process_o();
        void process_open_bracket_modifier();
        void process_close_bracket_modifier();
        void process_n();
        void process_quote();
        void process_t();
        void process_invalid();
    public:
        void start();
        int get_result();
        int get_result_better();
        RecursiveParser(std::string input) : input(input) {}
};