/* There are nn concert tickets available, each with a certain price. Then, mm customers arrive, one after another.

Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
Input

The first input line contains integers nn and mm: the number of tickets and the number of customers.

The next line contains nn integers h1,h2,…,hnh1​,h2​,…,hn​: the price of each ticket.

The last line contains mm integers t1,t2,…,tmt1​,t2​,…,tm​: the maximum price for each customer in the order they arrive.
Output

Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.

If a customer cannot get any ticket, print −1−1.
Constraints

    1≤n,m≤2⋅1051≤n,m≤2⋅105
    1≤hi,ti≤1091≤hi​,ti​≤109 */


#include <bits/stdc++.h>
using namespace std;

int main(){
    int numTickets, numCostumers;
    cin >> numTickets >> numCostumers;

    multiset<int> tickets;

    for (int i = 0; i < numTickets; i++){
        int value = 0;
        cin >> value;

        tickets.insert(value);
    }

    for (int i = 0; i < numCostumers; i++){
        int value = 0;
        cin >> value; 

        auto upperBoundIt = tickets.upper_bound(value);

        if (upperBoundIt == tickets.begin())
            cout << "-1" << endl;
        else {
                --upperBoundIt; 
                cout << *upperBoundIt << endl;
                tickets.erase(upperBoundIt);
        }
    }

    return 0;
}