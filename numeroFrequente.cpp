// dato un'array di massimo 50 restituire il valore che compare più volte, se più elementi compaiono più volte restituire il più piccolo
#include <iostream>
using namespace std;

int main(){
    int tot;
    cout << "inserisci la grandezza dell'array (max 50)" << endl;
    cin >> tot;
    while(tot > 50 || tot < 0){
        cout << "reinserisci la grandezza dell'array (max 50)" << endl;
        cin >> tot;
    }
    int array[tot];
    for(/*variabili da inizializzare*/int i = 0; /*condizione*/i < tot; /*incremento */i++){
        cout << "inserisci il " << i+1 << "° elemento" << endl;
        cin >> array[i];
    }
    int count[tot];
    for(int i=0;i<tot;i++){
        count[i] = 0;
    }
    for(int i=0;i<tot;i++){
        for(int j=0;j<tot;j++){
            if(array[i] == array[j]){
                count[i]++;
            }
        }
    }
    for(int i=0;i<tot;i++){
        cout << array[i] << "\t e' presente " << count[i] << " volte" << endl;
    }
    int max = 0; //quante volte viene ripetuto il/i numeri ripetuti più volte
    for(int i=0;i<tot;i++){
        if(count[i] > max){
            max = count[i];
        }
    }
    int totParziale = 0; // quanti numeri vengono ripetuti max volte
    for(int i=0;i<tot;i++){
        if(count[i] == max){
            totParziale++;
        }
    }
    int result; // numero che compare più volte
    if(totParziale == max){
        for(int i=0;i<tot;i++){
            if(count[i] == max){
                result = array[i];
            }
        }
    }else{
        int arrayParziale[totParziale];
        for(int i=0, j=0;i<tot;i++){
            if(count[i] == max){
                arrayParziale[j] = array[i];
                j++;
            }
        }
        int min = arrayParziale[0];
        for(int i=1;i<totParziale;i++){
            if(arrayParziale[i] < min){
                min = arrayParziale[i];
            }
        }
        result = min;
    }
    cout << "il numero piu' piccolo che compare piu' volte e' " << result << endl;
}