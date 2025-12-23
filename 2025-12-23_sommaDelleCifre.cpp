//scrivi del codice che calcola la somma delle cifre di un numero preso in input
using namespace std;
#include <iostream>

int main(){

    cout << "inserisci un numero in input" << endl;
    int tot = 0;
    int n = 0;
    cin >> n;
    while(n>0){
        tot += n%10;
        n /= 10;
    }

    cout << "la somma delle cifre e' " << tot;
    
    return 0;
}