/* 2019-W02-Exercise_3_10.cpp :

Exercise 3.10
  Schreiben Sie ein Programm, das einen ganz simplen Taschenrechner simuliert. 
  Eingegeben wird ein mathematischer Ausdruck, der Zahlen und die binären Operatoren +,-,* und / enthält. 
  Der Ausdruck wird durch ein Rufzeichen abgeschlossen. 
  Das Programm soll das Ergebnis des Ausdrucks berechnen, wobei die Operationen strikt von links 
  nach rechts durchzuführen sind. (Das heisst, es gilt nicht Punkt- vor Strichrechnung!)
    Z.B.:
          Eingabe: 2+3-4/2*3-1!      Ausgabe: 0.5


Dániel Szöke (11913915)
26.10.2019

*/

#include <iostream>
#include <string> //stol
#include <cmath>

//#include <exception> 

using namespace std;

const string EnabledFirstCharList = "0123456789";
const string EnabledCharList      = "+-/*0123456789!";

inline bool IsEnabledChar(string aString, char c) {
	return std::string(aString).find(c) != std::string::npos;
}


long SimpleCalculator(string mathExpression) {
	double result{ 0.0 }, operand{ 0.0};
	long counter{ 0 };
	string operandString{""}; 
	char operatorSign{ '_' };
	bool IsNextOperand{ false };
	

	if (!IsEnabledChar(EnabledFirstCharList, mathExpression[0]))
		throw("The expression is not valid");

	//Create first number
	while (counter < mathExpression.length() &&
		mathExpression[counter] >= '0' && mathExpression[counter] <= '9') {
		operandString = operandString + mathExpression[counter];
		counter++;
	}
	result = double(stol(operandString));

	while(counter < mathExpression.length()) {
		//Check char[counter] 
		if (!IsEnabledChar(EnabledCharList, mathExpression[counter]))
			throw("The expression contains irregular character");
		
		operatorSign = mathExpression[counter++];
	
		//Create number as operand to an Operation
		operandString = ""; operand = 0.0;

		while (counter < mathExpression.length() &&
			mathExpression[counter] >= '0' && mathExpression[counter] <= '9') {
			operandString = operandString + mathExpression[counter];
			counter++;
		}
		if(operandString != "") operand = double(stol(operandString));
		
		switch (operatorSign) {
			case '+':
				result = result + operand;
				break;
			case '-':
				result = result - operand;
				break;
			case '*':
				result = result * operand;
				break;
			case '/':
				result = result / operand;
				break;
			case '!':
				break;
			default:
				// If the operator is other than +, -, *, / or number, error message is shown
				throw("Error! expression is not correct");
		} //end switch

	}//end while

	return result;
}


int main()
{
	
	
	cout << "------------Test------------" << endl;
	cout << "123!        :  " << SimpleCalculator("123!") << endl;
	cout << "12+50/2!    :  " << SimpleCalculator("12+50/2!") << endl;
	cout << "1+55/2*3+1! :  " << SimpleCalculator("1+55/2*3+1!") << endl;
	cout << endl;

	// Get from the data from user to function
	string realString;
	cout << "This program...\n";
	cout << "Bitte geben Sie hier reelle Zahlen ein: "; cin >> realString;
	cout << "Resultat: " << SimpleCalculator(realString) << endl;
	
	return 0;
}
