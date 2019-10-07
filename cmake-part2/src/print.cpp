#include <iostream>
#include "print.hpp"

using namespace std;

void say_hello () {
  cout << "Hello there!" << endl;
}

void print_separation (double separation) {
  cout << "The angular separation between Andromeda and the Horsehead nebula is "
  << separation << " degrees." << endl;
}
