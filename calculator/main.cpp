#include "calculator.h"

int main()
{
	Calculator TheCalc;
	bool stauts;
	do 
	{
		cout << "> ";
		Input input;
		stauts = TheCalc.Execute(input);
		if(stauts)
		{
			for (StackSeq seq(TheCalc.GetStack());!seq.AtEnd();seq.Advance())
			{
				cout << " " << seq.GetNum() << endl;
			}
		}
	} while (stauts);
}