// prendendo in input l'investimento iniziale calcola quanti hanno ci vogliono per raddoppiarlo avendo un'aumento del 5% annuo

#include <iostream>
using namespace std;

int main(){

    double inv;
    cout << "inserisci l'investimento iniziale\t";
    cin >> inv;
    double obiettivo = 2*inv;
    int anni=0;

    while(obiettivo > inv){

        inv = inv + inv/20;
        anni = anni + 1;
        cout << "anno:\t" << anni << "\tinvestimento:\t" << inv << "\tobbiettivo:\t"<< obiettivo << endl;
    }

    cout << "ci si mettono " <<anni<<" anni, con un ricavo di "<<inv<<endl;
}