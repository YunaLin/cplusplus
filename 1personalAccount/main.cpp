/* from younglee..
 * guys! enjoy your journey of c plus plus, against all odds!
 */
#include<iostream>
#include "PersonalAccount.h"
using namespace std;

int main() {
    // test input here..
    int a, b;
    cin >> a >> b;

    // declare a object and it's balance is 0.
    PersonalAccount pa;

    // add a dollar into user's account..
    pa.add(a);

    // deduct b dollar from user's account..
    pa.subtract(b);

    // show balance..
    pa.getBalance();
}
 
