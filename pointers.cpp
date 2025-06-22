#include <iostream>
#include <unistd.h>
using namespace std;

struct Telefon {
    string marka;
    int yil;
    double fiyat;
};

int main() {
    Telefon telefonlar[5]; // Maksimum 5 telefon
    int telefonSayisi = 0;
    int secim;
    
    cout << "Telefon Pointer Egzersizi" << endl;
    
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Telefon ekle" << endl;
        cout << "2. Telefonlari listele (normal erisim)" << endl;
        cout << "3. Telefonlari listele (pointer erisim)" << endl;
        cout << "4. Telefon guncelle (pointer ile)" << endl;
        cout << "5. Pointer adreslerini goster" << endl;
        cout << "0. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;
        
        switch(secim) {
            case 1: {
                if(telefonSayisi >= 5) {
                    cout << "Maksimum 5 telefon ekleyebilirsiniz!" << endl;
                    break;
                }
                
                cout << "Marka: ";
                cin >> telefonlar[telefonSayisi].marka;
                cout << "Yil: ";
                cin >> telefonlar[telefonSayisi].yil;
                cout << "Fiyat: ";
                cin >> telefonlar[telefonSayisi].fiyat;
                
                telefonSayisi++;
                cout << "Telefon eklendi!" << endl;
                usleep(500000); // 0.5 saniye bekle
                break;
            }
            
            case 2: {
                cout << "\n--- NORMAL ERISIM (. operatoru) ---" << endl;
                usleep(500000); // 0.5 saniye bekle
                for(int i = 0; i < telefonSayisi; i++) {
                    cout << i+1 << ". " << telefonlar[i].marka 
                         << " - " << telefonlar[i].yil 
                         << " - " << telefonlar[i].fiyat << " TL" << endl;
                    usleep(500000); // Her telefon arasında bekle
                }
                break;
            }
            
            case 3: {
                cout << "\n--- POINTER ERISIM (-> operatoru) ---" << endl;
                usleep(500000); // 0.5 saniye bekle
                for(int i = 0; i < telefonSayisi; i++) {
                    Telefon* tPtr = &telefonlar[i];
                    cout << i+1 << ". " << tPtr->marka 
                         << " - " << tPtr->yil 
                         << " - " << tPtr->fiyat << " TL" << endl;
                    usleep(500000); // Her telefon arasında bekle
                }
                break;
            }
            
            case 4: {
                if(telefonSayisi == 0) {
                    cout << "Henuz telefon yok!" << endl;
                    break;
                }
                
                cout << "Hangi telefonu guncellemek istiyorsunuz? (1-" << telefonSayisi << "): ";
                int index;
                cin >> index;
                
                if(index < 1 || index > telefonSayisi) {
                    cout << "Gecersiz secim!" << endl;
                    break;
                }
                
                Telefon* tPtr = &telefonlar[index-1];
                
                cout << "Mevcut: " << tPtr->marka << " - " << tPtr->yil << " - " << tPtr->fiyat << endl;
                cout << "Yeni marka: ";
                cin >> tPtr->marka;
                cout << "Yeni yil: ";
                cin >> tPtr->yil;
                cout << "Yeni fiyat: ";
                cin >> tPtr->fiyat;
                
                cout << "Guncellendi!" << endl;
                usleep(500000); // 0.5 saniye bekle
                break;
            }
            
            case 5: {
                cout << "\n--- POINTER ADRESLERI ---" << endl;
                usleep(500000); // 0.5 saniye bekle
                for(int i = 0; i < telefonSayisi; i++) {
                    Telefon* tPtr = &telefonlar[i];
                    cout << i+1 << ". Telefon adresi: " << tPtr << endl;
                    usleep(300000); // 0.3 saniye bekle
                    cout << "   Marka: " << tPtr->marka << " (adres: " << &tPtr->marka << ")" << endl;
                    usleep(300000); // 0.3 saniye bekle
                    cout << "   Yil: " << tPtr->yil << " (adres: " << &tPtr->yil << ")" << endl;
                    usleep(500000); // Her telefon arasında bekle
                }
                break;
            }
            
            case 0:
                cout << "Cikiliyor..." << endl;
                break;
                
            default:
                cout << "Gecersiz secim!" << endl;
        }
        
    } while(secim != 0);
    
    return 0;
}