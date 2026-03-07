//scrivi del codice che calcola la somma delle cifre di un numero preso in input
using namespace std;
#include <iostream>

int main(){

    // input: 153
    // output: 9
    int num1;
    int numfinale =0;

    cout<<"inserisci un numero "<<endl;
    cin>>num1;

    // while:   NON SO quanti giri faccio
    // for:     SO quanti giri faccio

    while(num1 != 0){
        //x%y = resto di x/y
        numfinale += num1%10; // 3
        num1 /= 10;
    }
    cout << "la somma delle cifre e':\t" << (numfinale > 0 ? numfinale : -numfinale) << endl;
    return 0;
}