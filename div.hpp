#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"
#include "op.hpp"
#include <iostream>
#include <string>

using namespace std;

class Div : public Base {
	public:
        Div(Base* left, Base* right) : Base() {
            if(left == nullptr || right == nullptr) {
			throw invalid_argument("Null argument.")
		;}

            lnode = left; rnode = right;
            if(rnode->evaluate() == 0){
		        throw invalid_argument("Invalid Argument: Divided by zero.");
	        }
        }

        double evaluate() {
            return lnode->evaluate() / rnode->evaluate();
        }

        string stringify() {
            return '(' + lnode->stringify() + "/" + rnode->stringify() + ')';
        }

	private:
        Base *lnode, *rnode;

};

#endif
