#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Mahasiswa{
    int NIM;
    string Nama;
    string JenisKelamin;
    string TanggalLahir; // format : tanggal bulan tahun contoh (20 Mei 2006)
    int Semester;
    string Prodi;
    string Fakultas;
    double IPK;
};

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
bool cek_nim_duplikat(int nim){
    ifstream file("src/data.csv");
    if(file.fail()){
        cout<<"Gagal membuka file!"<<endl;
        return false;
    }
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string nim_pada_file;
        getline(ss, nim_pada_file, ','); // Ambil NIM
        if(stoi(nim_pada_file) == nim){ // cek apakah ada NIM yang sama
            file.close();
            return true; 
        }
    }
    file.close();
    return false; // NIM tidak ditemukan, tidak duplikat
}

void input_data(){
    ofstream file("src/data.csv", ios::app);
    if(file.fail()){
        cout<<"Gagal membuka file!"<<endl;
        return;
    }
    Mahasiswa temp;
    bool duplikasi_nim = false;
    do{
        cout<<"Masukkan NIM : ";
        cin>>temp.NIM;
        duplikasi_nim = cek_nim_duplikat(temp.NIM);
        if(duplikasi_nim){
            system("cls");
            cout<<"NIM sudah ada, silakan masukkan NIM yang berbeda!"<<endl;
            system("pause");
        }
    }while(duplikasi_nim);
    cin.ignore();
    cout<<"Masukkan Nama : ";
    getline(cin, temp.Nama);
    cout<<"Masukkan Jenis Kelamin (Laki-Laki/Perempuan): ";
    getline(cin, temp.JenisKelamin);
    cout<<"Masukkan Tanggal Lahir (20 Mei 2006): ";
    getline(cin, temp.TanggalLahir);
    cout<<"Masukkan Semester : ";
    cin>>temp.Semester;
    cin.ignore();
    cout<<"Masukkan Program Studi : ";
    getline(cin, temp.Prodi);
    cout<<"Masukkan Fakultas : ";
    getline(cin, temp.Fakultas);
    cout<<"Masukkan IPK : ";
    cin>>temp.IPK;
    file<<temp.NIM<<","<<temp.Nama<<","<<temp.JenisKelamin<<","<<temp.TanggalLahir<<","<<temp.Semester<<","<<temp.Prodi<<","<<temp.Fakultas<<","<<temp.IPK<<endl;   
    file.close();
    cout<<"Data berhasil disimpan!"<<endl;
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
                input_data();
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