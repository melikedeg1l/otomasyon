#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>


using namespace std;

struct Hali {
    string marka;
    float fiyat;
    
};

void HaliEkle(const Hali& yeniHali) {
    ofstream dosyaYaz("hali_otomasyonu.txt", ios::app);
    dosyaYaz << yeniHali.marka << " " << yeniHali.fiyat << endl;
    cout << "Hali basariyla eklendi!\n" << endl;
    dosyaYaz.close();
}

void HaliListele() {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string marka;
    float fiyat;
    	int i =0;
	cout << "--------listenen halilar--------"  << endl<<endl;
    while (dosyaOku >> marka >> fiyat) {
    
    	cout <<i+1<< ".hali"  << endl;

        cout << "Marka: " << marka << ", Fiyat: " << fiyat << endl;
        i++;
    }

    dosyaOku.close();
}

void HaliSil(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    ofstream tempYaz("temp.txt");

    string tempMarka;
    float tempFiyat;

    bool bulundu = false;
    while (dosyaOku >> tempMarka >> tempFiyat) {
        if (tempMarka != marka) {
            tempYaz << tempMarka << " " << tempFiyat << endl;
        } else {
            bulundu = true;
        }
    }

    dosyaOku.close();
    tempYaz.close();

    if (bulundu) {
        remove("hali_otomasyonu.txt");
        rename("temp.txt", "hali_otomasyonu.txt");
        cout << "Hali basariyla silindi!\n" << endl;
    } else {
        remove("temp.txt");
        cout << "Hali bulunamadi!" << endl;
    }
}
void HaliSat(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    ofstream tempYaz("temp.txt");

    string tempMarka;
    float tempFiyat;
    float toplamFiyat = 0.0;

    bool bulundu = false;
    while (dosyaOku >> tempMarka >> tempFiyat) {
        if (tempMarka != marka) {
            tempYaz << tempMarka << " " << tempFiyat << endl;
        } else {
            bulundu = true;
            toplamFiyat += tempFiyat;
        }
    }

    dosyaOku.close();
    tempYaz.close();
    

    if (bulundu) {
        remove("hali_otomasyonu.txt");
        rename("temp.txt", "hali_otomasyonu.txt");
        cout << "Hali basariyla satildi!" << endl;
        cout << "Toplam fiyat: " << toplamFiyat << endl;
    } else {
        remove("temp.txt");
        cout << "Hali bulunamadi!" << endl;
    }
}

void HaliDuzelt(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    ofstream tempYaz("temp.txt");

    string tempMarka;
    float tempFiyat;

    bool bulundu = false;
    while (dosyaOku >> tempMarka >> tempFiyat) {
        if (tempMarka == marka) {
            cout << "Yeni fiyat: ";
            cin >> tempFiyat;
            tempYaz << tempMarka << " " << tempFiyat << endl;
            bulundu = true;
        } else {
            tempYaz << tempMarka << " " << tempFiyat << endl;
        }
    }

    dosyaOku.close();
    tempYaz.close();

    if (bulundu) {
        remove("hali_otomasyonu.txt");
        rename("temp.txt", "hali_otomasyonu.txt");
        cout << "Hali basariyla duzeltildi!\n" << endl;
    } else {
        remove("temp.txt");
        cout << "Hali bulunamadi!" << endl;
    }
}

void HaliAra(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string tempMarka;
    float tempFiyat;
    bool bulundu = false;

    while (dosyaOku >> tempMarka >> tempFiyat) {
        if (tempMarka == marka) {
            cout << "Marka: " << tempMarka << ", Fiyat: " << tempFiyat << endl;
            bulundu = true;
        }
    }

    dosyaOku.close();

    if (!bulundu) {
        cout << "Hali bulunamadi!" << endl;
    }
}
void FisleriGoster(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string tempMarka;
    float tempFiyat;
    float toplamFiyat = 0.0;
    int fisNumarasi = 1;
cout << "--------Kalan halilarin fisleri-------- "<< endl;
    while (dosyaOku >> tempMarka >> tempFiyat) {
    	
        cout << "Fis Numarasi: " << fisNumarasi << endl;
        cout << "Marka: " <<tempMarka << ", Fiyat: " << tempFiyat<< endl;
        toplamFiyat += tempFiyat;
        fisNumarasi++;
    }
    cout << "\nKalan halilarin Toplam fiyatlari: " << toplamFiyat <<endl<< endl;

    dosyaOku.close();
}


int main() {
	 system("CLS");
    system("color 0A");
    int secim = 0;
    string marka;
    float fiyat;
    int silinecekIndeks;

    while (true) {
        system("cls");
        cout << "----------- Hali Otomasyonu -----------" << endl;
        cout << "|   1. Hali Ekle                      |" << endl;
        cout << "|   2. Hali Listele                   |" << endl;
        cout << "|   3. Hali Sil                       |" << endl;
        cout << "|   4. Hali Sat                       |" << endl;
        cout << "|   5. Hali Duzelt                    |" << endl;
        cout << "|   6. Hali Ara                       |" << endl;
        cout << "|   7. Satilan Halilarin Fisini Goster|" << endl;
        cout << "|   8. Cikis                          |" << endl;
        cout << "---------------------------------------" <<endl;
        cout << "Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
            case 1:
                system("cls");
                cout << "Marka giriniz: ";
                cin >> marka;
                cout << "Fiyat giriniz: ";
                cin >> fiyat;
                HaliEkle({marka, fiyat});
                break;
            case 2:
                system("cls");
                HaliListele();
                break;
            case 3:
                system("cls");
                HaliListele();
                cout << "Silinecek halinin markasini girin: ";
                cin >> marka;
                HaliSil(marka);
                break;
            case 4:
                system("cls");
                HaliListele();
                cout << "Satilacak halinin markasini girin: ";
                cin >> marka;
                HaliSat(marka);
                break;
            case 5:
                system("cls");
                 HaliListele();
                cout << "Duzeltilecek halinin markasini girin: ";
                cin >> marka;
                HaliDuzelt(marka);
                break;
            case 6:
                system("cls");
                cout << "Aranacak halinin markasini girin: ";
                cin >> marka;
                HaliAra(marka);
                break;
            case 7:
                system("cls");
                FisleriGoster(marka);
                break;
            case 8:
                return 0;
            default:
                cout << "Gecersiz secim!" << endl;
        }

        cout << "Devam etmek icin bir tusa basin...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
