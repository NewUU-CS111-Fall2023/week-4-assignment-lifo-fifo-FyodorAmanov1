#include <iostream>
using namespace std;
int towerOfHanoi(int j) {
   if (j == 1) {
       return 1;
   }

   return 2 * towerOfHanoi(j - 1) + 1;
}

int main() {
   int j = 8;
   int minMoves = towerOfHanoi(j);
   cout << minMoves << endl;

   return 0;
}