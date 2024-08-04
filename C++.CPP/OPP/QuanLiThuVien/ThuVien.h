#pragma once
#include"DocGiaNguoiLon.h"
#include"DocGiaTreEm.h"
#include<vector>

class CThuVien{
    private:
        vector<CDOCGIA *> ds_docgia;
    public:
        void Input();
        void Output();
        int tinh_tong_tien_lam_the();
        CThuVien(){};
        ~CThuVien(){};
};

void CThuVien::Input(){
    int luachon;
    while(1){
        system("cls");
        cout<<"\n\n\t\t========>> Thu Vien <<========";
        cout<<"\n\t 1. Doc gia tre em ";
        cout<<"\n\t 2. Doc gia nguoi lon ";
        cout<<"\n\t 0. thoat ";
        cout<<"\n\n\t\t======== END ========";
        cout<<"\nNhap lua chon: ";
        cin>>luachon;
        CDOCGIA *x;
        if(luachon==1){
            x=new CDocGiaTreEm;
            cout<<"\n\n\t\t NHAP THONG TIN DOC GIA \n";
            x->Input();
            x->Setter_KT(true);// tre em 
            ds_docgia.push_back(x);
        }
        else if(luachon==2){
            x = new CDocGiaNguoiLon;
            x->Input();
            x->getter_KT(false);//nguoi lon
            ds_docgia.push_back(x);
        }
        else if(luachon==0){
            break;
        }
        else{
            cout<<"\nLua chon khong hop le.Xin kiem tra lai ";
            system("pause");
        }
    }
}
void CThuVien::Output(){
    cout<<"\n\n\t\t ==== DANH SACH DOC GIA ====\n";
    for(int i=0;i<ds_docgia.size();i++){
        if(ds_docgia[i]->getter_KT()==true){
            cout<<"\n\n\t\tTHONG TIN DOC GIA TRE EM THU "<<i+1<<endl;
            ds_docgia[i]->Output();
        }else{
            cout<<"\n\n\t\tTHONG TIN DOC GIA NGUOI LON THU "<<i+1<<endl;
            ds_docgia[i]->Output();
        }
    }
};
// tinh tong tien lam the

int CThuVien::tinh_tong_tien_lam_the(){
    int sum=0;
    for(int i=0;i<ds_docgia.size();i++){
        sum+=ds_docgia[i]->tinh_tien_lam_the();
    }
    return sum;
};




