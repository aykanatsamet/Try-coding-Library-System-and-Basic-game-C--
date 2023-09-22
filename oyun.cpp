#include <iostream>
using namespace std;
void tahtayi_cizme(char oyun_tahtasi[3][3]) 
{
    
    cout << "   0   1   2  " <<endl;
    cout << " ┌───┬───┬───┐" <<endl;
    for (int satir = 0; satir < 3; satir++) 
    {
        cout << satir << "│ ";
        for (int sutun = 0; sutun < 3; sutun++) 
        {
            cout << oyun_tahtasi[satir][sutun] << " │ ";
        }
        cout << endl;
        if (satir != 2) 
        {
            cout << " ├───┼───┼───┤" << endl;
        }
    }
    cout << " └───┴───┴───┘" << endl;
}

bool hamle_kontrol(char oyun_tahtasi[][3], int satir, int sutun) 
{
    if(satir < 0 || satir > 2 || sutun < 0 || sutun > 2) 
    {
        return false;
    }
    if(oyun_tahtasi[satir][sutun] != ' ') 
    {
        return false;
    }
    return true;
}

bool kazanan_kontrol(char oyun_tahtasi[][3], char oyuncu) 
{
    for(int satir = 0; satir < 3; satir++) 
    {
        if(oyun_tahtasi[satir][0] == oyuncu && oyun_tahtasi[satir][1] == oyuncu && oyun_tahtasi[satir][2] == oyuncu) 
        {
            return true;
        }
        if(oyun_tahtasi[0][satir] == oyuncu && oyun_tahtasi[1][satir] == oyuncu && oyun_tahtasi[2][satir] == oyuncu) 
        {
            return true;
        }
    }
    if(oyun_tahtasi[0][0] == oyuncu && oyun_tahtasi[1][1] == oyuncu && oyun_tahtasi[2][2] == oyuncu) {
        return true;
    }
    if(oyun_tahtasi[0][2] == oyuncu && oyun_tahtasi[1][1] == oyuncu && oyun_tahtasi[2][0] == oyuncu) {
        return true;
    }
    return false;
}

int main() 
{
    char oyun_tahtasi[3][3] = { { ' ', ' ', ' ' },
                                { ' ', ' ', ' ' },
                                { ' ', ' ', ' ' } };

    int satir, sutun, sayac = 0;
    char oyuncu = 'X';
    bool kazanan = false, beraberlik = false;

    cout << "Tic Tac Toe oyununa hoşgeldiniz!" << endl;
    cout << "Oyuncu 1: X" << endl;
    cout << "Oyuncu 2: O" << endl;

    while(!kazanan && !beraberlik) 
    {
        tahtayi_cizme(oyun_tahtasi);
        cout << "Oyuncu " << (sayac % 2) + 1 << ", Satir giriniz (0-2): ";
        cin >> satir;
        cout << "Oyuncu " << (sayac % 2) + 1 << ", Sütun giriniz (0-2): ";
        cin >> sutun;
        if(hamle_kontrol(oyun_tahtasi, satir, sutun)) 
        {
            oyun_tahtasi[satir][sutun] = oyuncu;
            if(kazanan_kontrol(oyun_tahtasi, oyuncu)) 
            {
                kazanan = true;
                cout << "Kazanan " << "oyuncu " <<(sayac % 2) + 1 <<"!"<<endl;
            }
            if (oyuncu == 'X')
                oyuncu = 'O';
            else 
            {
                oyuncu = 'X';
            }
            sayac++;
            if(sayac == 9) 
            {
                beraberlik = true;
                cout << "Maç berabere!" << endl;
            }
        }
        else 
        {
            cout << "Yanlış hamle.Tekrar oynayınız." << endl;
        }
    }

    tahtayi_cizme(oyun_tahtasi);
    return 0;
}