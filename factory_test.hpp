#ifndef FACTORY_TEST_HPP
#define FACTORY_TEST_HPP

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

TEST(FactoryTest, Addn){
	char* arr[4]; arr[0] = "./calculator";arr[1] = "15";arr[2] = "+";arr[3] = "2"; 
	Factory* fact = new Factory();
	Base* test = fact->parse(arr,4);
	string str = test->stringify();
	double eval = test->evaluate();
	EXPECT_EQ("(15.000000+2.000000)", str);
	EXPECT_EQ(17, eval);
}

TEST(FactoryTest, Subn){
        char* arr[4]; arr[0] = "./calculator";arr[1] = "15";arr[2] = "-";arr[3] = "2";
        Factory* fact = new Factory();
        Base* test = fact->parse(arr,4);
        string str = test->stringify();
        double eval = test->evaluate();
	EXPECT_EQ("(15.000000-2.000000)", str);
	EXPECT_EQ(13, eval);
}

TEST(FactoryTest, Mult){
        char* arr[4]; arr[0] = "./calculator";arr[1] = "15";arr[2] = "*";arr[3] = "2";
        Factory* fact = new Factory();
        Base* test = fact->parse(arr,4);
        string str = test->stringify();
        double eval = test->evaluate();
        EXPECT_EQ("(15.000000*2.000000)", str);
        EXPECT_EQ(30, eval);
}

TEST(FactoryTest, Div){
        char* arr[4]; arr[0] = "./calculator";arr[1] = "15";arr[2] = "/";arr[3] = "3";
        Factory* fact = new Factory();
        Base* test = fact->parse(arr,4);
        string str = test->stringify();
        double eval = test->evaluate();
        EXPECT_EQ("(15.000000/3.000000)", str);
        EXPECT_EQ(5, eval);
}


TEST(FactoryTest, Pow){
        char* arr[4]; arr[0] = "./calculator";arr[1] = "15";arr[2] = "**";arr[3] = "2";
        Factory* fact = new Factory();
        Base* test = fact->parse(arr,4);
        string str = test->stringify();
        double eval = test->evaluate();
        EXPECT_EQ("(15.000000**2.000000)", str);
        EXPECT_EQ(225, eval);
}



TEST(FactoryTest, Many){
	char* arr[8]; arr[0] = "./calculator";arr[1] = "15";arr[2] = "/"; arr[3]= "3"; arr[4] = "**"; arr[5] = "2"; arr[6] = "-"; arr[7] = "10";
	Factory* fact = new Factory();
	Base* test = fact->parse(arr,8);
	EXPECT_EQ("(((15.000000/3.000000)**2.000000)-10.000000)",test->stringify());
	EXPECT_EQ(15, test->evaluate());
}
#endif

