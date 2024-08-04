#include<iostream>

using namespace std;


class nguoi{
    protected:
        string hoten;
        int namsinh;
    public:
        nguoi(){};
        nguoi(string hoten,int namsinh){
            this->hoten=hoten;
            this->namsinh=namsinh;
        };
        ~nguoi(){};
};
class sinhvien: public nguoi{
    private:
        string masv;
        float dtb;
    public:
        sinhvien(){}
        sinhvien(string masv,string hoten,int namsinh,float dtb){
            this->masv=masv;
            this->hoten=hoten;
            this->namsinh=namsinh;
            this->dtb=dtb;
        }
        void nhapsinhvien(sinhvien&);
        void nhapnsinhvien(sinhvien*,int);
        void xuatsinhvien(sinhvien);
        void xuatnsinhvien(sinhvien*,int);
        void timkiem(sinhvien*,int,string);
            ~sinhvien(){}
};
void sinhvien::nhapsinhvien(sinhvien &sv){
    cout<<"\nnhap masv: ";getline(cin,sv.masv);
    cout<<"\nnhap hoten: ";getline(cin,sv.hoten);
    cout<<"\nnhap namsinh: ";cin>>sv.namsinh;
    cout<<"\nnhap dtb: ";cin>>sv.dtb;
}
void sinhvien::xuatsinhvien(sinhvien sv){
    cout<<"masv: "<<sv.masv<<"\n";
    cout<<"hoten: "<<sv.hoten<<"\n";
    cout<<"namsinh: "<<sv.namsinh<<"\n";
    cout<<"dtb: "<<sv.dtb<<"\n";
}
void sinhvien::nhapnsinhvien(sinhvien *sv,int n){
    for(int i=0;i<n;i++){
        cout<<"\nnhap thong tin sinh vien thu: "<<i+1;
        cin.ignore();
        sv->nhapsinhvien(sv[i]);
    }
}
void sinhvien::xuatnsinhvien(sinhvien *sv,int n){
     cout<<"\n==>>Thong Tin Sinh Vien<<==\n";
     for(int i=0;i<n;i++){
        sv->xuatsinhvien(sv[i]);
     }
}
void sinhvien::timkiem(sinhvien *sv,int n,string x){
    for(int i=0;i<n;i++){
        if(sv->hoten==x){
            sv->xuatsinhvien(sv[i]);
            break;
        }
        if(sv->masv==x){
            sv->xuatsinhvien(sv[i]);
            break;
        }
    }
    cout<<"\nkhong tim thay xinh vien ";
}




int main(){
    int n;
    cin>>n;
    sinhvien *sv=new sinhvien[n];
    sv->nhapnsinhvien(sv,n);
    cout<<"nhap masv hoac ho ten can tim kiem: ";
    sv->xuatnsinhvien(sv,n);
    cout<<"\nnhap masv/hoten sinh vien can tim kiem: ";
    string x;
    cin.ignore();
    getline(cin,x);
    sv->timkiem(sv,n,x);
    return 0;
}