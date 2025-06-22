#include <iostream>
#include <locale>
#include <unistd.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Turkish");
    
    int i, n;
    string months[12]; // 12 elemanlı bir string dizisi
    
    cout << "****** AYLAR DİZİSİ (string array) ******" << endl;
    usleep(500000);
    
    // Dizi elemanlarını atama
    months[0] = "Ocak";
    months[1] = "Şubat";
    months[2] = "Mart";
    months[3] = "Nisan";
    months[4] = "Mayıs";
    months[5] = "Haziran";
    months[6] = "Temmuz";
    months[7] = "Ağustos";
    months[8] = "Eylül";
    months[9] = "Ekim";
    months[10] = "Kasım";
    months[11] = "Aralık";
    
    // Kullanıcıdan kaç ay yazdırmak istediğini al
    cout << "Kaç ay yazdırmak istiyorsunuz? (1-12): ";
    cin >> n;
    
    // Geçerli aralıkta olup olmadığını kontrol et
    if (n < 1 || n > 12) {
        cout << "Geçersiz sayı! 1-12 arasında bir sayı giriniz." << endl;
        return 1;
    }
    
    usleep(500000);
    cout << "\nİlk " << n << " ay:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << months[i] << endl;
        usleep(300000); // Daha kısa bekleme.
    }
    
    usleep(500000);
    cout << "\n****** YILLAR DİZİSİ (int array) ******" << endl;
    usleep(500000);
    
    int years[5];
    
    // Bundan sonraki ilk 5 yılı ata
    for (i = 0; i < 5; i++)
    {
        years[i] = 2025 + i;
    }
    
    cout << "Bundan sonraki ilk 5 yıl:" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << years[i] << endl;
        usleep(300000);
    }
    
    usleep(500000);
    cout << "\n****** GÜNLER DİZİSİ (const char* array) ******" << endl;
    usleep(500000);
    
    const char* days[7] = {"Pazartesi", "Salı", "Çarşamba", "Perşembe", "Cuma", "Cumartesi", "Pazar"};
    
    cout << "Haftanın günleri:" << endl;
    for (i = 0; i < 7; i++)
    {
        cout << days[i] << endl;
        usleep(300000);
    }
    
    usleep(500000);
    cout << "\n****** ALFABE DİZİSİ (char array) ******" << endl;
    usleep(500000);
    
    char alphabet[26];
    int letterCount;
    
    // Alfabeyi oluştur.
    for (i = 0; i < 26; i++)
    {
        alphabet[i] = 'A' + i;
    }
    
    // Kullanıcıdan kaç harf yazdırmak istediğini al.
    cout << "Alfabenin ilk kaç harfini yazdırmak istiyorsunuz? (1-26): ";
    cin >> letterCount;
    
    // Geçerli aralıkta olup olmadığını kontrol et
    if (letterCount < 1 || letterCount > 26) {
        cout << "Geçersiz sayı! 1-26 arasında bir sayı giriniz." << endl;
        return 1;
    }
    
    usleep(500000);
    cout << "\nAlfabenin ilk " << letterCount << " harfi:" << endl;
    for (i = 0; i < letterCount; i++)
    {
        cout << alphabet[i] << endl;
        usleep(300000);
    }
    
    return 0;
}