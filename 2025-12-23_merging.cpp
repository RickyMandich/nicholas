//scrivi del codice che considera 2 array di interi e ottiene un unico array composto dall'unione dei due
//ATTENZIONE:
// gli array di input saranno ordinati
// l'array finale dev'essere ordinato
using namespace std;
#include <iostream>

int main(){
    int tot = 10;
    int a1[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int a2[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int a3[tot * 2];

    cout<<"array di partenza";
    cout << "arr1" << "\tarr2" << endl;
    for(int i = 0;i<tot;i++){
        cout << a1[i] << "\t" << a2[i] << endl;
    }
    for(int i1 = 0, i2 = 0, i3 =0; i3 <=tot*2; i3++){
        if(i1 < tot && i2 < tot){
            if(a1[i1]<a2[i2]){
                a3[i3]=a1[i1++];
            }else{
                a3[i3]=a2[i2++];
            }
        }else{
            if(i1 == tot){
                a3[i3] = a2[i2++];
            }else{
                a3[i3] = a1[i1++];
            }
        }
    }
    cout<<"array finale:\n";
    for(int i=0;i<tot*2;i++){
        cout << a3[i] << endl;
    }
    
    return 0;
}