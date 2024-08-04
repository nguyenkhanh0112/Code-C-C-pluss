#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Xe{
    protected:
        string hoten;
        int giothue;
    public:
        void nhap();
        void xuat();
};
void Xe::nhap(){
    cin.ignore();
    cout<<"nhap ho ten: ";
    getline(cin,hoten);
    cout<<"nhap gio thue: ";    
    cin>>giothue;
}
void Xe::xuat(){
    cout<<"ho ten: "<<hoten<<endl;
    cout<<"so gio thue: "<<giothue<<endl;
}


class Xedap : public Xe{
    private:
    public:
        float tien_thue_xe_dap(){
            return 10000+(giothue-1)*8000;
        }
        void xuatxedap(){
            Xe::xuat();
            cout<<"tien thue xe: "<<tien_thue_xe_dap()<<endl;
        }
};
class Xemay : public Xe{
    private:
        int loaixe;
        string bienso;
    public:
    int gettet_loaixe(){
        return loaixe; 
    }
    void nhapxemay(){
        Xe::nhap();
        cin.ignore();
        cout<<"nhap bien so: ";
        getline(cin,bienso);
        cout<<"nhap loai xe(100-250): ";
        cin>>loaixe;
    }
    float tien_thue_xe_may(){
        if(loaixe==100)
            return 150000+(giothue-1)*100000;
        else if(loaixe==250)
            return 200000+(giothue-1)*100000;
    }
    void xuatxemay(){
        Xe::xuat();
        cout<<"bien so: "<<bienso<<endl;
        cout<<"loai xe: "<<loaixe<<endl;
        cout<<"tien thue xe may: "<<tien_thue_xe_may();
    }
};
void xuat_tat_ca_thong_tin_thue_xe(Xedap ds_xedap[],int n,Xemay ds_xemay[],int m){
    cout<<"\n\n\t\t DANH SACH THUE XE DAP\n";
    for(int i=0;i<n;i++){
        cout<<"\n\tTHONG TIN THUE XE DAP THU "<<i+1<<endl;
        ds_xedap[i].xuatxedap();
        
    }
     cout<<"\n\n\t\t DANH SACH THUE XE MAY\n";
    for(int i=0;i<m;i++){
        cout<<"\n\tTHONG TIN THUE XE MAY THU "<<i+1<<endl;
        ds_xemay[i].xuatxemay();
    }
}
float tinh_tong_tien_thuexe(Xedap ds_xedap[],int n,Xemay ds_xemay[],int m){
    float tong=0;
    for(int i=0;i<n;i++){
        tong+=ds_xedap[i].tien_thue_xe_dap();
    }
    for(int i=0;i<m;i++){
        tong+=ds_xemay[i].tien_thue_xe_may();
    }
    return tong;
}
float tinh_tong_tien_thue_xemayloai250(Xemay ds_xemay[],int m){
    float tong=0;
    for(int i=0;i<m;i++){
        if(ds_xemay[i].gettet_loaixe()==250){
            tong+=ds_xemay[i].tien_thue_xe_may();
        }
    }
    return tong;
}
void menu(Xedap ds_xedap[],int n,Xemay ds_xemay[],int m){
    int luachon;
    while(1){
        cout<<"\n\n\t\t====== QUAN LY XE ======";
        cout<<"\n\t1. Nhap danh sach thue xe dap va xe may ";
        cout<<"\n\t2. Xuat tat ca thong tin thue xe ";
        cout<<"\n\t3. Tinh tong so tien cho thue xe dap va xe may ";
        cout<<"\n\t4. Xuat tat ca cac thong tin lien quan den viec cho thue xe dap ";
        cout<<"\n\t5. Tinh tong so tien cho thue xe may loai 250 phan khoi ";
        cout<<"\n\t0. Ket thuc";
        cout<<"\n\n\t\t===================END======================";
        cout<<"\nNhap lua chon: ";
        cin>>luachon;
            if(luachon==1){
                int chon;
                while(1){
                    system("cls");
                    cout<<"\n1. Thue xe dap";
                    cout<<"\n2. Thue xe may";
                    cout<<"\n0. Ket thuc";

                    cout<<"\nNhap lua chon: ";
                    cin>>chon;
                    if(chon==1){
                        cout<<"\n\n\t\tNHAP THONG TIN THUE XE DAP\n ";
                        Xedap x;
                        x.nhap();
                        ds_xedap[n]=x;
                        n++;
                    }
                    else if(chon==2){
                        Xemay x;
                        cout<<"\n\n\t\tNHAP THONG TIN XE MAY\n ";
                        x.nhapxemay();
                        ds_xemay[m]=x;
                        m++; 
                    }
                    else {
                        break;
                    }
                }
            }else if(luachon==2){
                xuat_tat_ca_thong_tin_thue_xe(ds_xedap,n,ds_xemay,m);
                system("pause");
            }else if(luachon==3){
                cout<<"\n\n\t\tTong tien thue xe la: "<<tinh_tong_tien_thuexe(ds_xedap,n,ds_xemay,m);
                system("pause");
            }else if(luachon==4){
                cout<<"\n\n\t\t CAC THONG TIN LIEN QUAN DEN VIEC DI XE DAP\n ";
                for(int i=0;i<n;i++){
                    ds_xedap[i].xuatxedap();
                }
                system("pause");
            }else if(luachon==5){
                cout<<"\n\n\t\tTONG TIEN THUE XE MAY LOAI 250\n";
                cout<<tinh_tong_tien_thue_xemayloai250(ds_xemay,m);
                system("pause");
            }else if(luachon==0){
                break;             
            }
    }
}
int main(){
    int n=0,m=0;
    Xemay ds_xemay[100];
    Xedap ds_xedap[100];
    menu(ds_xedap,n,ds_xemay,m);
    system("pause");
    return 0;
}