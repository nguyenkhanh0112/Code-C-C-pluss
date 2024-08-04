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
        }
        ~nguoi(){};
};
class sinhvien:public nguoi{
    private:
        string masv;
        float dtb;
    public:
        sinhvien(){};
        sinhvien(string masv,string hoten,int namsinh,float dtb){
            this->masv=masv;
            this->hoten=hoten;
            this->namsinh=namsinh;
            this->dtb=dtb;
        }
        ~sinhvien(){};
        void nhapsinhvien(sinhvien&);
        void xuatsinhvien(sinhvien);
        void nhapnsinhvien(sinhvien*,int);
        void xuatnsinhvien(sinhvien*,int);
        void xapxepsinhvien(sinhvien*,int);
};

 void sinhvien::nhapsinhvien(sinhvien &sv){
            cout<<"\nnhap masv: ";getline(cin,sv.masv);
            cout<<"\nnhap hoten: ";getline(cin,sv.hoten);
            cout<<"\nnhap nam sinh: ";cin>>sv.namsinh;
            cout<<"\nnhap dtb: ";cin>>sv.dtb;
        };
void sinhvien::xuatsinhvien(sinhvien sv){
            cout<<"\nmasv: "<<sv.masv;
            cout<<"\nhoten: "<<sv.hoten;
            cout<<"\nnamsinh: "<<sv.namsinh;
            cout<<"\ndiemtb: "<<sv.dtb;
        }
void sinhvien::nhapnsinhvien(sinhvien *sv,int n){
    for(int i=0;i<n;i++){
        cout<<"nhap sinh vien thu: "<<i+1;
            cin.ignore();
            sv->nhapsinhvien(sv[i]);
    }
}
void sinhvien::xuatnsinhvien(sinhvien *sv,int n){
    for(int i=0;i<n;i++){
        cout<<"\nxuat sinh vien thu: "<<i+1;
            sv->xuatsinhvien(sv[i]);
    }
}
void sinhvien::xapxepsinhvien(sinhvien *sv,int n){
    sinhvien temp;
    cout<<"==>>Danh Sach Sinh Vien xap xep Tang Dan<<=="<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(sv[i].dtb<sv[j].dtb){
                temp=sv[i];
                sv[i]=sv[j];
                sv[j]=temp;
            }
        }
    }
}
int main(){
    int n;
    cout<<"nhap vao n sinh vien: ";
    cin>>n;
    sinhvien *sv=new sinhvien[n];
    sv->nhapnsinhvien(sv,n);
    sv->xapxepsinhvien(sv,n);
    sv->xuatnsinhvien(sv,n);
    return 0;
}










