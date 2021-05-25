#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "base.hpp"

#include <iostream>
#include <string>
#include <queue>
#include <stack>


using namespace std;

class Base;

class Factory {

    public:

      Factory(){ };
      
	Base* parse(char** input, int length){ //single public method
        	queue<char*> q;
        	stack<char*> s;
        	string oper; 
	
	for (int i = 1; i < length; ++i){
           oper = static_cast<string>(input[i]);
          if (isdigit(oper.at(0))){
            q.push(input[i]);
          }
        
	  else if (oper == "+" || oper  == "-" || oper  == "*" || oper  == "/" || oper  == "**"){
            while(!s.empty()){
              q.push(s.top());
              s.pop();
            }
            s.push(input[i]);
          }
        
	  else{
            cout << "Invalid input" << endl;
          	return nullptr;
          }
        }

        while(!s.empty()){
          q.push(s.top());
          s.pop();
        }
        
	queue<Base*> q2;
        Base* temp1;
        Base* temp2;
        Base* temp3;
        double temp4;
        
	while(!q.empty()){
          oper = static_cast<string>(q.front());
         
	  if (oper == "+"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Add(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
         
	  else if (oper == "-"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Sub(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
         
	  else if (oper == "*"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Mult(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
       
	  else if (oper == "/"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Div(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
      
	  else if (oper == "**"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Pow(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
          
	 else{
            temp4 = stod(oper); //string double
            temp1 = new Op(temp4);
            q.pop();
            q2.push(temp1);
          }

        }
	int answer = q2.front();
	delete() q2;
	return answer;        
      }

};

#endif
