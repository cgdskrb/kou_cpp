#include <iostream>
#include <locale>
#include <unistd.h>
#include <iomanip>
using namespace std;

// İç içe struct yapıları
struct Adres {
    string il;
    string ilce;
    string mahalle;
    int postaKodu;
    
    void yazdir() {
        cout << mahalle << " Mah., " << ilce << "/" << il << " (" << postaKodu << ")" << endl;
    }
};

struct Iletisim {
    string telefon;
    string email;
    Adres adres;  // İç içe struct
    
    void yazdir() {
        cout << "Tel: " << telefon << " | Email: " << email << endl;
        cout << "Adres: ";
        adres.yazdir();
    }
};

struct Notlar {
    float matematik;
    float fizik;
    float kimya;
    
    float ortalama() {
        return (matematik + fizik + kimya) / 3.0;
    }
    
    void yazdir() {
        cout << fixed << setprecision(1);
        cout << "Mat: " << matematik << " | Fiz: " << fizik << " | Kim: " << kimya;
        cout << " | Ort: " << ortalama() << endl;
    }
    
    string basariDurumu() {
        float ort = ortalama();
        if (ort >= 85) return "Takdir";
        else if (ort >= 70) return "Teşekkür";
        else if (ort >= 50) return "Geçti";
        else return "Kaldı";
    }
};

struct Ogrenci {
    int no;
    string ad;
    string soyad;
    int yas;
    string sinif;
    Iletisim iletisim;  // İç içe struct
    Notlar notlar;      // İç içe struct
    
    void tamAdYazdir() {
        cout << "=== " << ad << " " << soyad << " ===" << endl;
    }
    
    void detayliYazdir() {
        cout << "\n";
        cout << "╔═════════════════════════════════════════╗" << endl;
        cout << "║            ÖĞRENCİ BİLGİLERİ            ║" << endl;
        cout << "╠═════════════════════════════════════════╣" << endl;
        cout << "║ No: " << setw(4) << no << "                              ║" << endl;
        cout << "║ Ad Soyad: " << setw(25) << left << (ad + " " + soyad) << "  ║" << endl;
        cout << "║ Yaş: " << setw(2) << yas << "   Sınıf: " << setw(15) << left << sinif << "   ║" << endl;
        cout << "╠═════════════════════════════════════════╣" << endl;
        cout << "║ İLETİŞİM BİLGİLERİ                      ║" << endl;
        cout << "║ Tel: " << setw(15) << left << iletisim.telefon << "              ║" << endl;
        cout << "║ Email: " << setw(25) << left << iletisim.email << "  ║" << endl;
        cout << "║ Adres: " << setw(27) << left << (iletisim.adres.mahalle + " Mah.") << " ║" << endl;
        cout << "║        " << setw(27) << left << (iletisim.adres.ilce + "/" + iletisim.adres.il) << " ║" << endl;
        cout << "╠═════════════════════════════════════════╣" << endl;
        cout << "║ NOTLAR VE BAŞARI DURUMU                 ║" << endl;
        cout << "║ Matematik: " << setw(5) << fixed << setprecision(1) << notlar.matematik << "                      ║" << endl;
        cout << "║ Fizik:     " << setw(5) << notlar.fizik << "                      ║" << endl;
        cout << "║ Kimya:     " << setw(5) << notlar.kimya << "                      ║" << endl;
        cout << "║ Ortalama:  " << setw(5) << notlar.ortalama() << "                      ║" << endl;
        cout << "║ Durum: " << setw(8) << left << notlar.basariDurumu() << "                     ║" << endl;
        cout << "╚═════════════════════════════════════════╝" << endl;
    }
    
    void ozet() {
        cout << setw(4) << no << " | " 
             << setw(15) << left << (ad + " " + soyad) << " | "
             << setw(8) << sinif << " | "
             << setw(5) << fixed << setprecision(1) << notlar.ortalama() << " | "
             << notlar.basariDurumu() << endl;
    }
};

// Struct array için yardımcı fonksiyonlar
void baslikYazdir() {
    cout << "\n╔═════════════════════════════════════════════════════════╗" << endl;
    cout << "║                  ÖĞRENCİ LİSTESİ                        ║" << endl;
    cout << "╠═════════════════════════════════════════════════════════╣" << endl;
    cout << "║  No |      Ad Soyad      |  Sınıf  | Ort. | Durum      ║" << endl;
    cout << "╠═════════════════════════════════════════════════════════╣" << endl;
}

void altCizgi() {
    cout << "╚═════════════════════════════════════════════════════════╝" << endl;
}

int main() {
    setlocale(LC_ALL, "Turkish");
    
    cout << "*** STRUCT YAPILARI DEMONSTRASYONu ***" << endl;
    cout << "*** (Bu bir demo programdır - veriler gerçek değildir) ***" << endl;
    usleep(1000000);
    
    // Öğrenci array'i oluştur
    Ogrenci ogrenciler[3];
    
    // 1. öğrenci
    ogrenciler[0].no = 101;
    ogrenciler[0].ad = "Ahmet";
    ogrenciler[0].soyad = "Yılmaz";
    ogrenciler[0].yas = 17;
    ogrenciler[0].sinif = "11-A";
    ogrenciler[0].iletisim.telefon = "0532-123-4567";
    ogrenciler[0].iletisim.email = "ahmet@email.com";
    ogrenciler[0].iletisim.adres.il = "İstanbul";
    ogrenciler[0].iletisim.adres.ilce = "Kadıköy";
    ogrenciler[0].iletisim.adres.mahalle = "Fenerbahçe";
    ogrenciler[0].iletisim.adres.postaKodu = 34726;
    ogrenciler[0].notlar.matematik = 85.5;
    ogrenciler[0].notlar.fizik = 92.0;
    ogrenciler[0].notlar.kimya = 78.5;
    
    // 2. öğrenci
    ogrenciler[1].no = 102;
    ogrenciler[1].ad = "Zeynep";
    ogrenciler[1].soyad = "Kaya";
    ogrenciler[1].yas = 16;
    ogrenciler[1].sinif = "10-B";
    ogrenciler[1].iletisim.telefon = "0543-987-6543";
    ogrenciler[1].iletisim.email = "zeynep@email.com";
    ogrenciler[1].iletisim.adres.il = "Ankara";
    ogrenciler[1].iletisim.adres.ilce = "Çankaya";
    ogrenciler[1].iletisim.adres.mahalle = "Kızılay";
    ogrenciler[1].iletisim.adres.postaKodu = 06420;
    ogrenciler[1].notlar.matematik = 95.0;
    ogrenciler[1].notlar.fizik = 88.5;
    ogrenciler[1].notlar.kimya = 91.0;
    
    // 3. öğrenci
    ogrenciler[2].no = 103;
    ogrenciler[2].ad = "Mehmet";
    ogrenciler[2].soyad = "Demir";
    ogrenciler[2].yas = 17;
    ogrenciler[2].sinif = "11-C";
    ogrenciler[2].iletisim.telefon = "0555-111-2233";
    ogrenciler[2].iletisim.email = "mehmet@email.com";
    ogrenciler[2].iletisim.adres.il = "İzmir";
    ogrenciler[2].iletisim.adres.ilce = "Konak";
    ogrenciler[2].iletisim.adres.mahalle = "Alsancak";
    ogrenciler[2].iletisim.adres.postaKodu = 35220;
    ogrenciler[2].notlar.matematik = 65.0;
    ogrenciler[2].notlar.fizik = 72.5;
    ogrenciler[2].notlar.kimya = 58.0;
    
    // Öğrenci listesini göster
    baslikYazdir();
    for (int i = 0; i < 3; i++) {
        cout << "║ ";
        ogrenciler[i].ozet();
        usleep(500000);
    }
    altCizgi();
    
    usleep(1000000);
    
    // Detaylı bilgileri göster
    cout << "\n=== DETAYLI ÖĞRENCİ BİLGİLERİ ===" << endl;
    for (int i = 0; i < 3; i++) {
        usleep(1000000);
        ogrenciler[i].detayliYazdir();
    }
    
    usleep(1000000);
    cout << "\n=== BAŞARI DURUMU ANALİZİ ===" << endl;
    int takdir = 0, tesekkur = 0, gecti = 0, kaldi = 0;
    
    for (int i = 0; i < 3; i++) {
        string durum = ogrenciler[i].notlar.basariDurumu();
        if (durum == "Takdir") takdir++;
        else if (durum == "Teşekkür") tesekkur++;
        else if (durum == "Geçti") gecti++;
        else kaldi++;
    }
    
    cout << "Takdir: " << takdir << " öğrenci" << endl;
    cout << "Teşekkür: " << tesekkur << " öğrenci" << endl;
    cout << "Geçti: " << gecti << " öğrenci" << endl;
    cout << "Kaldı: " << kaldi << " öğrenci" << endl;
    
    return 0;
}