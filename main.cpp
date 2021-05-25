#include <iostream>
#include <vector>
#include <list>
#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "factory.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

using namespace std;

int main(int argv, char** argc){
	Factory* fact = new Factory();
	Base* out = fact->parse(argc, argv);
	if(out != NULL){
		cout << "Evaluate: " << out->evaluate() << endl;
		cout << "String: " << out->stringify() << endl;
	}
	else{
		cout << "NULL" << endl;
	}

return 0;
}
