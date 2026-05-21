#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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
    Mahasiswa mhs;
    bool duplikasi_nim = false;
    do{
        cout<<"Masukkan NIM : ";
        cin>>mhs.NIM;
        duplikasi_nim = cek_nim_duplikat(mhs.NIM);
        if(duplikasi_nim){
            system("cls");
            cout<<"NIM sudah ada, silakan masukkan NIM yang berbeda!"<<endl;
            system("pause");
        }
    }while(duplikasi_nim);
    cin.ignore();
    cout<<"Masukkan Nama : ";
    getline(cin, mhs.Nama);
    cout<<"Masukkan Jenis Kelamin (Laki-Laki/Perempuan): ";
    getline(cin, mhs.JenisKelamin);
    cout<<"Masukkan Tanggal Lahir (20 Mei 2006): ";
    getline(cin, mhs.TanggalLahir);
    cout<<"Masukkan Semester : ";
    cin>>mhs.Semester;
    cin.ignore();
    cout<<"Masukkan Program Studi : ";
    getline(cin, mhs.Prodi);
    cout<<"Masukkan Fakultas : ";
    getline(cin, mhs.Fakultas);
    cout<<"Masukkan IPK : ";
    cin>>mhs.IPK;
    file<<mhs.NIM<<","<<mhs.Nama<<","<<mhs.JenisKelamin<<","<<mhs.TanggalLahir<<","<<mhs.Semester<<","<<mhs.Prodi<<","<<mhs.Fakultas<<","<<mhs.IPK<<endl;   
    file.close();
    cout<<"Data berhasil disimpan!"<<endl;
}

void load_data(Mahasiswa mhs[], int &banyak_data){
    ifstream file("src/data.csv");
    if(file.fail()){
        cout<<"Gagal membuka file!"<<endl;
        return;
    }
    string line;
    while(getline(file, line)){
        if(!line.empty()){
            stringstream ss(line);
            string nim_str, semester_str, ipk_str;
            getline(ss, nim_str, ',');
            getline(ss, mhs[banyak_data].Nama, ',');
            getline(ss, mhs[banyak_data].JenisKelamin, ',');
            getline(ss, mhs[banyak_data].TanggalLahir, ',');
            getline(ss, semester_str, ',');
            getline(ss, mhs[banyak_data].Prodi, ',');
            getline(ss, mhs[banyak_data].Fakultas, ',');
            getline(ss, ipk_str);
            
            mhs[banyak_data].NIM = stoi(nim_str);
            mhs[banyak_data].Semester = stoi(semester_str);
            mhs[banyak_data].IPK = stod(ipk_str);
            
            banyak_data++;
        }
    }
    file.close();
}

string status(int semester, double ipk){
    return semester >= 5 && ipk >= 3.25 ? "Lolos" : "Tidak Lolos";
}

void tampilkan_seluruh_data(){
    Mahasiswa mhs[100];
    int banyak_data = 0;
    load_data(mhs, banyak_data);
    cout<<left 
        <<setw(12)<<"NIM" 
        <<setw(20)<<"Nama" 
        <<setw(15)<<"Gender" 
        <<setw(18)<<"Tanggal Lahir" 
        <<setw(10)<<"Semester" 
        <<setw(20)<<"Prodi" 
        <<setw(20)<<"Fakultas" 
        <<setw(6)<<"IPK"
        <<setw(8)<<"Status"<<endl;
    for(int i = 0; i < banyak_data; i++){
        cout<<left 
            <<setw(12)<<mhs[i].NIM 
            <<setw(20)<<mhs[i].Nama 
            <<setw(15)<<mhs[i].JenisKelamin 
            <<setw(18)<<mhs[i].TanggalLahir
            <<setw(10)<<mhs[i].Semester 
            <<setw(20)<<mhs[i].Prodi 
            <<setw(20)<<mhs[i].Fakultas 
            <<setw(6)<<mhs[i].IPK
            <<setw(8)<<status(mhs[i].Semester, mhs[i].IPK)<<endl;
        
    }
    
}

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
                tampilkan_seluruh_data();
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