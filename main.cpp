#include <iostream>
using namespace std;

void subMenuOutput(){
    int pilihan;
    do{
        system("cls");
        cout<<"======= Menu Output Data ======="<<endl;
        cout<<"1. Tampilkan (seluruh data)"<<endl;
        cout<<"2. Cari Data (NIM)"<<endl;
        cout<<"3. Kembali (ke menu utama)"<<endl;
        cout<<"Masukkan pilihan: ";
        cin>>pilihan;
        switch(pilihan){
            case 1: 
                system("cls");
                cout<<"Tampilkan seluruh data"<<endl;
                system("pause");
                break;
            case 2:
                system("cls");
                cout<<"Cari data berdasarkan NIM"<<endl;
                system("pause");
                break;
            case 3:
                system("cls");
                cout<<"Kembali ke menu utama"<<endl;
                break;
            default:
                system("cls");
                cout<<"Pilihan tidak valid"<<endl;
                system("pause");
        }
        
    }while(pilihan != 3);
}

int main() {
    int pilihan;
    do{
        system("cls");
        cout<<"======= Menu ======="<<endl;
        cout<<"1. Input data"<<endl;
        cout<<"2. Output data"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Masukkan pilihan: ";
        cin>>pilihan;
        switch(pilihan){
            case 1: 
                system("cls");
                cout<<"Input data"<<endl;
                system("pause");
                break;
            case 2:
                system("cls");
                subMenuOutput();
                system("pause");
                break;
            case 3:
                system("cls");
                cout<<"Thank you!"<<endl;
                break;
            default:
                system("cls");
                cout<<"Pilihan tidak valid"<<endl;
                system("pause");
        }
        
    }while(pilihan != 3);
    
    return 0;
}