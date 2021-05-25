#ifndef ADD_HPP_
#define ADD_HPP_

#include "base.hpp"

using namespace std;

class Add : public Base{
	private:
		Base* lhs;
		Base* rhs;
	public:
		Add(Base* left, Base* right){
			lhs = left;
			rhs = right;
		}
		double evaluate() {
			return lhs->evaluate() + rhs->evaluate();
		}
		string stringify(){
			return "(" + lhs->stringify() + "+" + rhs->stringify() + 			")";
		}   

};

#endif
