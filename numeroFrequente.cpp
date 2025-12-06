// dato un'array di massimo 50 restituire il valore che compare più volte, se più elementi compaiono più volte restituire il più piccolo
#include <iostream>
using namespace std;

int main(){
    int tot;
    cout << "inserisci la grandezza dell'array (max 50)" << endl;
    cin >> tot;
    cout << tot << endl;
    while(tot > 50 || tot < 0){
        cout << "reinserisci la grandezza dell'array (max 50)" << endl;
        cin >> tot;
        cout << tot << endl;
    }
    int a1[tot];
    for(/*variabili da inizializzare*/int i = 0; /*condizione*/i < tot; /*incremento */)
    
}