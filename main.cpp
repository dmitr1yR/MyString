#include <string.h>
#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
  int newCount = 11;
  MyString firstString;
  firstString.SetCount(newCount);
  cout << firstString.GetCount() << "\n";
  cin >> firstString;

  MyString secondString;
  cin >> secondString;
  cout << secondString.GetCount() << "\n";
  cout << secondString[2] << "\n";

  cout << firstString + secondString << "\n";

  cout << (firstString == secondString) << "\n";
  cout << (firstString > secondString) << "\n";

  cout << firstString.CopyFromIndex(secondString, 0, 2) << "\n";
  cout << secondString.FindChar('a') << "\n";
  secondString.FindString("se");
  return 0;
}
