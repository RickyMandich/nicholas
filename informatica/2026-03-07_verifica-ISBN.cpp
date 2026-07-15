#include <iostream>
#include <cmath>
using namespace std;

int main(){

    // un ISBN è composto da 13 cifre ed è verificato quando:
    // la somma delle cifre in posizione dispari +
    // il triplo della somma delle crifre in posizione pari
    // è divisibile per 10

    // somma dispari + (somma pari * 3) % 10 == 0

    long isbn;
    int sommapari = 0;
    int sommadispari = 0;
    cout<<"inserisci un isbn da 13 cifre"<<endl;
    cin>>isbn;
    if(!((int) (isbn / pow(10, 12)) != 0 && (int) (isbn / pow(10, 13)) == 0)){
        cout << "ISBN non valido" << endl;
        return 1;
    }

    for(int i=13;isbn > 0;i--){
        cout << "aggiungo " << isbn%10 << " ai ";
        if(i%2 ==0){
            cout << "pari\t\t";
            cout << sommapari << " + " << isbn%10 << " = "; 
            sommapari += isbn % 10;
            cout << sommapari << "\t\t";
        }
        else{ 
            cout << "dispari\t\t";
            cout << sommadispari << " + " << isbn%10 << " = "; 
            sommadispari += isbn % 10;
            cout << sommadispari << "\t\t";
        }
        isbn /= 10;
        cout << "ISBN:\t" << isbn << endl;
    }
    cout << "somma pari:\t\t\t\t" << sommapari << endl;
    cout << "somma dispari:\t\t\t\t" << sommadispari << endl;
    cout << "somma dispari + (somma pari *3):\t" << sommadispari + (sommapari *3) << endl;
    cout << "somma dispari + (somma pari *3) % 10:\t" << (sommadispari + (sommapari *3)) % 10<< endl << endl << endl;
    if((sommadispari + (sommapari * 3)) % 10 == 0){
        cout<<"ISBN valido"<<endl;

    }
    else{
        cout<<"ISBN invalido"<<endl;
    }

    return 0;
}