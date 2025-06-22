#include<iostream>
#include<locale> 
#include<unistd.h>
using namespace std;  

int main(){ 
    setlocale(LC_ALL,"Turkish");
    
    // Program açıklaması
    cout << "Bu program 2x2 boyutundaki A ve B matrislerinin çarpımını hesaplar." << endl;
    cout << "C = A x B şeklinde çarpım matrisi elde edilecektir." << endl;
    cout << "Lütfen bekleyiniz..." << endl;
    
    usleep(1500000);
    
    int A[2][2], B[2][2], C[2][2]; 
    int i, j, k;
    
    // A matrisinin elemanlarını kullanıcıdan alma.
    cout << "\nA matrisinin elemanlarını giriniz:" << endl;
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    
    // B matrisinin elemanlarını kullanıcıdan alma
    cout << "\nB matrisinin elemanlarını giriniz:" << endl;
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }
    
    // Matris çarpımı hesaplama (C = A x B)
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            C[i][j] = 0;
            for(k=0; k<2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    // A matrisini yazdırma
    cout << "\nA Matrisi:" << endl;
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    
    // B matrisini yazdırma
    cout << "\nB Matrisi:" << endl;
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    
    // C çarpım matrisini yazdırma
    cout << "\nC = A x B Çarpım Matrisi:" << endl;
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}