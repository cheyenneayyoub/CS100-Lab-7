#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

using namespace std;

class Base {
    public:
        /* Constructors */
        Base() { }

        virtual ~Base() {}
    
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual string stringify() = 0;
};

#endif 
