#ifndef __CALC_H__
#define __CALC_H__

#include <iostream>
using namespace std;

class IStack {};

class StackSeq
{
public:
	StackSeq(const IStack& stack):_stack(stack),_done(false) {
		cout <<"create stack sequencer " << endl;
	}
	bool AtEnd() const {
		return _done;
	}
	void Advance(){
		_done = true;
	}

	int GetNum(){
		return 13;
	}

private:
	const IStack& _stack;
	bool _done;
};


class Input
{
public:
	Input(){
		cout <<"create input " << endl;
	}
};

class Calculator
{
public:
	Calculator():_done(false){
		cout <<"create calculator " <<endl;
	}
	bool Execute(Input& input){
		cout <<"Calculator::Execute " << endl;
		return !_done;
	}
	const IStack& GetStack() {
		_done = true;
		return _stack;
	}
private:
	IStack _stack;
	bool _done;
};



#endif