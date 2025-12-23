using namespace std;
#include <iostream>
//fare un programma che stampa i numeri da 1 a 100 e che se un numero è multiplo di 3 stampa invece buzz se invece è multiplo di 5 stampa invece fizz, nel caso siano entrambi validi stampa FizzBuzz
int main()
{
    int quant;
    cout<<"Inserisci una quantita' di numeri massima"<<endl;
    cin>>quant;
    for(int i=0 ; i <= quant ; i++){
        if(i % 3  == 0 || i % 5 == 0){
            if(i % 5 == 0){
                cout<<"Fizz";
            }
            if(i % 3 == 0){
                cout<<"Buzz";
            }
            cout<<endl;
        }
        else{
            cout<<i<<endl;
        }
    }
    return 0;
}