#ifndef _MULT_HPP_
#define _MULT_HPP_

#include "base.hpp"
#include "op.hpp"
#include <iostream>
#include <string>

using namespace std;

class Mult : public Base {

    public:
        Mult(Base* left, Base* right) : Base() {
            if(left == nullptr || right == nullptr) 
		{	
			throw invalid_argument("Null argument.");
	}
		   lnode = left; rnode = right;
        }

        double evaluate() {
           return lnode->evaluate() * rnode->evaluate();
        }

        string stringify() {
            return '(' + lnode->stringify() + "*" + rnode->stringify() + ')';
        }
        
    private:
        Base *lnode, *rnode;

};

#endif
