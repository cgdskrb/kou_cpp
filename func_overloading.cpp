#include <iostream>
#include <locale>
#include <unistd.h>
using namespace std;

// void versiyon comb (sonucu direkt yazdırır)
void comb(int a, int b)
{
    if (a < 0 || b < 0 || a < b)
    {
        cout << "Hata: a >= b >= 0 olmalı" << endl;
        return;
    }
    
    if (b == 0 || b == a)
    {
        cout << "comb(" << a << ", " << b << ") = 1" << endl;
        return;
    }
    
    // C(n,k) hesaplama
    long long result = 1;
    if (b > a - b) 
        b = a - b; // C(n,k) = C(n,n-k)
    
    for (int i = 0; i < b; i++)
    {
        result = result * (a - i) / (i + 1);
    }
    
    cout << "comb(" << a << ", " << b << ") = " << result << endl;
}

// comb int dönüş değeri olan versiyon (function overloading)
int comb(double a, double b)
{
    int intA = static_cast<int>(a);
    int intB = static_cast<int>(b);
    
    if (intA < 0 || intB < 0 || intA < intB)
    {
        return -1; // hata kodu
    }
    
    if (intB == 0 || intB == intA)
    {
        return 1;
    }
    
    // C(n,k) hesaplama
    long long result = 1;
    if (intB > intA - intB) 
        intB = intA - intB;
    
    for (int i = 0; i < intB; i++)
    {
        result = result * (intA - i) / (i + 1);
    }
    
    return static_cast<int>(result);
}

// Permütasyon hesaplama
int perm(int a, int b)
{
    if (a < 0 || b < 0 || a < b)
    {
        return -1; // hata kodu
    }
    
    if (b == 0)
    {
        return 1;
    }
    
    // P(n,k) = n * (n-1) * ... * (n-k+1)
    long long result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= (a - i);
    }
    
    return static_cast<int>(result);
}

int main()
{
    setlocale(LC_ALL, "Turkish");
    
    int x, y;
    
    cout << "****** KOMBİNASYON HESAPLAMA ******" << endl;
    usleep(500000); // 0.5 saniye bekle
    
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    
    usleep(500000);
    cout << "\n****** VOID DÖNÜŞLÜ KOMBİNASYON FONKSİYONU ******" << endl;
    usleep(500000);
    cout << "comb(" << x << ", " << y << ") çağrılıyor:" << endl;
    usleep(500000);
    comb(x, y); // void olan çağrılır.
    
    usleep(500000);
    cout << "\n****** INT DÖNÜŞLÜ KOMBİNASYON FONKSİYONU ******" << endl;
    usleep(500000);
    cout << "comb(double a, double b) çağrılıyor:" << endl;
    usleep(500000);
    int result = comb(static_cast<double>(x), static_cast<double>(y));
    if (result != -1)
    {
        cout << "Dönen değer: " << result << endl;
        usleep(500000);
        cout << "comb(" << x << ", " << y << ") = " << result << endl;
    }
    else
    {
        cout << "Hata: Geçersiz parametreler" << endl;
    }
    
    usleep(500000);
    cout << "\n****** PERMÜTASYON HESAPLAMA ******" << endl;
    usleep(500000);
    int permX, permY;
    cout << "Permütasyon hesabı için x gir: ";
    cin >> permX;
    cout << "Permütasyon hesabı için y gir: ";
    cin >> permY;
    
    usleep(500000);
    int permResult = perm(permX, permY);
    if (permResult != -1)
    {
        cout << "Perm(" << permX << ", " << permY << ") = " << permResult << endl;
    }
    else
    {
        cout << "Hata: Permütasyon hesaplanamadı (x >= y >= 0 olmalı)" << endl;
    }
    
    return 0;
}