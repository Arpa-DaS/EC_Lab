#include <iostream>
#include <iomanip> 
#include <string>  
using namespace std;

//to extract numeric value from a string
double extractNumeric(const string& str) {
    // if the string is empty or exceeds the maximum length
    if (str.empty() || str.length() > 20) {
        return -999999.99;
    }

    //for parsing
    bool hasSign = false;
    bool hasDecimal = false;
    bool hasDigits = false;
    double number = 0.0;      //store the numeric value
    double decimalPlace = 0.1; //fractional digits

    //lop through the string
    for (size_t i = 0; i < str.length(); i++) {
        char ch = str[i];

        //check for + or - at the beginning
        if ((ch == '+' || ch == '-') && i == 0) {
            hasSign = true;
        }
        //check for digits
        else if (isdigit(ch)) {
            hasDigits = true;
            if (hasDecimal) {
                //the decimal part
                number += (ch - '0') * decimalPlace;
                decimalPlace *= 0.1;
            } else {
                //the integer part
                number = number * 10 + (ch - '0');
            }
        }
        //check for the decimal point
        else if (ch == '.' && !hasDecimal) {
            hasDecimal = true;
        }
        //  return invalid
        else {
            return -999999.99;
        }
    }

    //no digits found it's invalid
    if (!hasDigits) {
        return -999999.99;
    }

    //  the sign if necessary
    if (str[0] == '-') {
        number = -number;
    }

    return number;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
