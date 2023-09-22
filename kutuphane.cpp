#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Kitap 
{
    string ad;
    string yazar;
    string yayinevi;
    int yil;
};

int AdminSifre()
{
    char s1[]="elhampashaei";
    char s2[20];
    
    
    cout << "Kullanıcı Şifresini Giriniz: "<<endl;
    cin >> s2;
    
    if(strcmp(s1, s2) == 0)
    {
        cout << "Şifre Doğrulandı.."<<endl;
        return 1;
    }
    else
    {
        cout << "Geçersiz Şifre!!"<<endl;
        AdminSifre();
    }
}

void kitapEkle() 
{
    Kitap kitap;
    cout << "Kitap adı: ";
    cin.ignore();
    getline(cin, kitap.ad);

    cout << "Yazar: ";
    getline(cin, kitap.yazar);

    cout << "Yayınevi: ";
    getline(cin, kitap.yayinevi);

    cout << "Yıl: ";
    cin >> kitap.yil;

    fstream dosya;
    dosya.open("kutuphane.txt", ios::app);
    dosya << kitap.ad << " | " << kitap.yazar << " | " << kitap.yayinevi << " | " << kitap.yil << "\n";
    dosya.close();

    cout << "Kitap başarıyla eklendi!" << endl;
}

void kitapSil() 
{
    string arananAd;
    cout << "Silinecek kitabın adını girin: ";
    cin.ignore();
    getline(cin, arananAd);

    fstream dosya, geciciDosya;
    dosya.open("kutuphane.txt", ios::in);
    geciciDosya.open("gecici.txt", ios::out);

    string satir;
    while (getline(dosya, satir)) 
    {
        string ad = satir.substr(0, satir.find(" |"));

        if (ad != arananAd) 
        {
            geciciDosya << satir << "\n";
        }
    }

    dosya.close();
    geciciDosya.close();

    remove("kutuphane.txt");
    rename("gecici.txt", "kutuphane.txt");

    cout << "Kitap başarıyla silindi!" << endl;
}

void kitapBilgisiGoster() {
    fstream dosya;
    dosya.open("kutuphane.txt", ios::in);

    string satir;
    while (getline(dosya, satir)) {
        cout << satir << endl;
    }

    dosya.close();
}

void kitapBilgisiDuzenle() 
{
    string arananAd;
    cout << "Düzenlenecek kitabın adını girin: ";
    cin.ignore();
    getline(cin, arananAd);

    fstream dosya, geciciDosya;
    dosya.open("kutuphane.txt", ios::in);
    geciciDosya.open("gecici.txt", ios::out);

    string satir;
    while (getline(dosya, satir)) 
    {
        string ad = satir.substr(0, satir.find(" |"));

        if (ad == arananAd) 
        {
            Kitap kitap;
            cout << "Yeni kitap adı: ";
            getline(cin, kitap.ad);

            cout << "Yazar: ";
            getline(cin, kitap.yazar);

            cout << "Yayınevi: ";
            getline(cin, kitap.yayinevi);

            cout << "Yıl: ";
            cin >> kitap.yil;

            geciciDosya << kitap.ad << " | " << kitap.yazar << " | " << kitap.yayinevi << " | " << kitap.yil << "\n";
        } 
        else
        {
            geciciDosya << satir << "\n";
        }
    }

    dosya.close();
    geciciDosya.close();

    remove("kutuphane.txt");
    rename("gecici.txt", "kutuphane.txt");

    cout << "Kitap başarıyla düzenlendi!" << endl;
}

void kitapAra() {
    string arananAd;
    cout << "Aranacak kitabın adını girin: ";
    cin.ignore();
    getline(cin, arananAd);

    fstream dosya;
    dosya.open("kutuphane.txt", ios::in);

    string satir;
    bool bulundu = false;
    while (getline(dosya, satir)) 
    {
        string ad = satir.substr(0, satir.find(" |"));

        if (ad == arananAd) 
        {
            cout << satir << endl;
            bulundu = true;
            break;
        }
    }

    dosya.close();

    if (!bulundu) 
    {
        cout << "Kitap bulunamadı!" << endl;
    }
}

int main() 
{
    int secim,i=0;
    int sonuc=AdminSifre();
    
    while (i==0) // sonsuz döngü
    {
        cout << "\n--- KÜTÜPHANE PROGRAMI ---" << endl;
        cout << "1. Kitap Ekle" << endl;
        cout << "2. Kitap Sil" << endl;
        cout << "3. Kitap Bilgisini Göster" << endl;
        cout << "4. Kitap Bilgisini Düzenle" << endl;
        cout << "5. Kitap Ara" << endl;
        cout << "6. Çıkış" << endl;
        cout << "Seçiminizi yapın: ";
        cin >> secim;

        switch (secim) 
        {
            case 1:
                kitapEkle();
                break;
            case 2:
                kitapSil();
                break;
            case 3:
                kitapBilgisiGoster();
                break;
            case 4:
                kitapBilgisiDuzenle();
                break;
            case 5:
                kitapAra();
                break;
            case 6:
                cout << "Programdan çıkılıyor..." << endl;
                return 0;
            default:
                cout << "Geçersiz seçim! Tekrar deneyin." << endl;
                
        }
    }

    return 0;
}