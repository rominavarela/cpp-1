#include <cstdlib>//legacy stdlib.h and time.h
#include <iostream>
#include <ctime>

using namespace std;

//legacy #define
const int NSIDES= 6;

//compiler directive, function code costs, inline is economic
inline int dropDice() { return rand() % NSIDES + 1; }

int main() {
  //init rand
  srand(clock());
  int dice = dropDice();

  if(dice%2==0)
    std::cout << "Dice is even ( " << dice << " )" << endl;
  else
    std::cout << "Dice is odd ( " << dice << " )" << endl;
}
