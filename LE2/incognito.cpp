/* Spies use attributes to disguise themselves to make sure that
they are not recognized. For example, when putting on sun-
glasses, a spy suddenly looks completely different and cannot
be recognized anymore. Every combination of attributes gives
a different appearance, but not all combinations are possible.
For example, a hat and a turban are both headgear and cannot
be used at the same time. Given the list of available attributes,
compute how many distinct disguises can be made.
Input
On the first line one positive number: the number of test cases,
at most 100. After that per test case:
• one line with an integer n (0 ≤ n ≤ 30): the number of
available attributes.
• n lines with two space-separated strings: the name and
the category of the attribute.
All strings consist of at least 1 and at most 20 lowercase letters. Within a test case all names
are distinct.
Output
Per test case:
• one line with an integer: the number of possible distinct disguises that can be made
with the given attributes, such that at most one attribute from each category is used */

#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;

int main(){
    int testCases; 
    cin >> testCases;

    while (testCases--){
        int numAttributes;
        cin >> numAttributes;

        map<string, int> attMap;

        for (int i = 0; i < numAttributes; i++){
            string attName, categoryName;
            cin >> attName >> categoryName;

            attMap[categoryName]++;
        }

        int total = 1;

        for (auto it = attMap.begin(); it != attMap.end(); ++it){
            total *= (it->second+1);
        }

        cout << total - 1 << endl;
    }

    return 0;
}