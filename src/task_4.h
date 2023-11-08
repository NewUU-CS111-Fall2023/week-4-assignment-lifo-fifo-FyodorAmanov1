#include <iostream>
#include <vector>

using namespace std;

int main() {
   int n;
   cin >> n;

   vector<vector<int>> stacks(n);
   for (int i = 0; i < n; ++i) {
       int ki;
       cin >> ki;

       for (int j = 0; j < ki; ++j) {
           int type;
           cin >> type;

           stacks[i].push_back(type);
       }
   }

   // Check if the containers are initially properly stacked
   bool isInitiallyProper = true;
   for (int i = 0; i < n; ++i) {
       for (int j = 0; j < stacks[i].size(); ++j) {
           if (stacks[i][j] != i) {
               isInitiallyProper = false;
               break;
           }
       }
   }

   if (isInitiallyProper) {
       // Containers are initially properly stacked, so do nothing
   } else {
       // Containers need to be rearranged
       while (true) {
           bool hasMovedContainers = false;

           for (int i = 0; i < n; ++i) {
               if (stacks[i].empty()) {
                   continue;
               }

               int topType = stacks[i].back();

               if (topType != i) {
                   // Find a stack to place the container with the top type
                   int targetStack = topType;

                   if (!stacks[targetStack].empty()) {
                       // If the target stack is not empty, check if the top container has the same type
                       // as the top container of the current stack
                       if (stacks[targetStack].back() == topType) {
                           // Both containers have the same type, so no need to move them
                           continue;
                       }
                   }

                   // Move the container to the target stack
                   int fromStack = i;

                   cout << fromStack + 1 << " " << targetStack + 1 << endl;

                   int container = stacks[fromStack].back();
                   stacks[fromStack].pop_back();
                   stacks[targetStack].push_back(container);

                   hasMovedContainers = true;
                   break;
               }
           }

           if (!hasMovedContainers) {
               // No containers were moved, so the problem has no solution
               cout << 0 << endl;
               break;
           }
       }
   }

   return 0;
}