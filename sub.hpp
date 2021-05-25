#ifndef SUB_HPP_
#define SUB_HPP_

#include "base.hpp"

using namespace std;

class Sub : public Base{
	private:
		Base* lhs;
		Base* rhs;
	public:
		Sub(Base* left, Base* right) : Base() {
			lhs = left;
			rhs = right;
		}
		double evaluate() {
			return (lhs->evaluate() - rhs->evaluate());
		}
		string stringify(){
			return "(" + lhs->stringify() + "-" + rhs->stringify() + 			")";
		}   

};

#endif
