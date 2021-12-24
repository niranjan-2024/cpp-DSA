#include <iostream>
using namespace std;

int main() {
  double numerator, denominator, result;
  cout << "Enter first number: ";
  cin >> numerator;
  cout << "Enter second number: ";
  cin >> denominator;

  try {

    if (denominator == 0)
      throw 0;

    // These statements are not executed if denominator is 0
    result = numerator / denominator;
    cout << numerator << "/" << denominator << " = " << result << endl;
  }

  catch (int num_exception) {
    cout << "Exception: Cannot divide by " << num_exception;
  }

  return 0;
}
