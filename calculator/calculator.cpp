#include "calculator.h"


bool Calculator::Execute( Input& input )
{
	int token = input.Token();
	bool status = false;

	if(token == Input::tokError ){
		cout <<"Unknown token " << endl;
	}
	else if(token == Input::tokNumber){
		if(_stack.IsFull()){
			cout <<"Stack is full " << endl;
		}
		else{
			_stack.Push(input.Number());
			status = true;
		}
	}
	else if (token == Input::tokBool){
		if (_stack.IsFull()){
			cout << "Stack is full " << endl;
		}
		else{
			_stack.Push(input.Bool());
			status = true;
		}
	}
	else if (token == 'x'){
		status = true;
	}
	else if (token == 'r'){
		_stack.Reset();
		status = true;
	}
	else if(token == 'q'){
		status = false;
	}
	else{
		assert(token == '+' ||token == '-' ||token == '*' ||token == '/' || token == '&' || token =='|' || token == '^'
			|| token == '!');
		if(_stack.IsEmpty()){
			cout <<"Stack is empty " << endl;
		}
		else{
			int num2 = _stack.Pop();
			int num1 =0;
			if(_stack.IsEmpty())
				num1 = num2;
			else 
				num1 = _stack.Pop();

			if (_type == NUMBER_CALC)
				_stack.Push(Calculate(num1, num2, token));
			else
				_stack.Push(Calculate((bool)num1, (bool)num2, token));
			status = true;
		}
	}

	return status;
}

int Calculator::Calculate( int num1,int num2,char token )
{
	int result;
	if(token == '+'){
		result = num1 + num2;
	}
	else if(token == '-'){
		result = num1 - num2;
	}
	else if(token == '*'){
		result = num1 * num2;
	}
	else if(token == '/'){
		if(num2 == 0){
			cout <<"Division by zero" << endl;
			result = 0;
		}
		else 
			result = num1 / num2;
	}
	else if (token == '&'){
		result = num1 & num2;
	}
	else if (token == '|'){
		result = num1 | num2;
	}
	else if (token == '^'){
		result = num1 ^ num2;
	}

	return result;
}

bool Calculator::Calculate(bool t, bool f, char token)
{
	bool result;
	if (token == '&'){
		result = t & f;
	}
	else if (token == '|'){
		result = t | f;
	}
	else if (token == '!'){
		result = !f;
	}
	return result;
}

Input::Input()
{
	memset(_buf, 0, sizeof(_buf));
	cin >> _buf;
	int c = _buf[0];
	if (isdigit(c)){
		_token = tokNumber;
	}
	else if (c == '+' || c == '*' || c == '/' || c == '&' || c == '|' || c== '^' || c == 'x' || c== 'r' || c=='q'){
		_token = c;
	}
	else if (strcmp(_buf, "true") == 0 || strcmp(_buf, "false") == 0){
		_token = tokBool;
	}
	else if(c=='-'){
		if (isdigit(_buf[1])){
			_token = tokNumber;
		}
		else
			_token = c;
	}
	else{
		_token = tokError;
	}
}