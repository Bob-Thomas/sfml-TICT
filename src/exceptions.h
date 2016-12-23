//
// Created by endargon on 12/14/16.
//

#ifndef SFML_DEMO_EXCEPTIONS_H
#define SFML_DEMO_EXCEPTIONS_H

#include <exception>
#include <ostream>

class unknown_file : public std::exception {
    public:
        unknown_file(const std::string &name) :
                s{std::string{"unknown file ["} + name + "]"} { }

        virtual const char *what() const throw() { return s.c_str(); }


    private:
        std::string s;
};

class unknown_color : public std::exception {
    public:
        unknown_color(const std::string &name) :
                s{std::string{"unknown color ["} + name + "]"} { }

        virtual const char *what() const throw() { return s.c_str(); }


    private:
        std::string s;
};

class unknown_color_type : public std::exception {
    public:
        unknown_color_type() :
                s("unknown color type") { }

        virtual const char *what() const throw() { return s.c_str(); }


    private:
        std::string s;
};

class unknown_shape : public std::exception {
    public:
        unknown_shape(const std::string &name) :
                s{std::string{"unknown shape ["} + name + "]"} { }


        virtual const char *what() const throw() { return s.c_str(); }


    private:
        std::string s;
};

class invalid_position : public std::exception {
    public:
        invalid_position(char pos) :
                s{std::string{"invalid position ["} + pos + "]"} { }


        virtual const char *what() const throw() { return s.c_str(); }


    private:
        std::string s;
};

class end_of_file : public std::exception {
    public:
        end_of_file() :
                s("End of file reached") { }


        virtual const char *what() const throw() { return s.c_str(); }


    private:
        std::string s;
};

class invalid_character : public std::exception {
    private:
        std::string msg;

    public:
        invalid_character(const char &c) : msg("Invalid character " + std::to_string(c) + "\n") {}
        virtual const char *what() const throw()  { return msg.c_str(); }
};

#endif //SFML_DEMO_EXCEPTIONS_H