#pragma once // tranh tinh trang dong do thu vien- trong moi tinh huong
#include<iostream>
#include<string>
using namespace std;

class CDOCGIA{
    protected:
        string hoten;
        string ngaylapthe;
        int sothangcohieuluccuathe;
        bool KT;
    public:
       bool getter_KT(){
        return KT;
       }
       void Setter_KT(bool KT){
        KT=KT;
       }
       virtual void Input();
       virtual void Output();
       virtual int tinh_tien_lam_the()=0;
       CDOCGIA();
       ~CDOCGIA();
};

void CDOCGIA::Input(){
    cin.ignore();
    cout<<"nhap ho ten doc gia: ";
    getline(cin,hoten);
    cout<<"nhap ngay lap the(dd/mm/yyyy): ";
    getline(cin,ngaylapthe);
    cout<<"nhap so thang con hieu luc cua the: ";
    cin>>sothangcohieuluccuathe;
}
void CDOCGIA::Output(){
    cout<<"ho ten doc gia: "<<hoten<<endl;
    cout<<"ngay lap the(dd/mm/yyyy): "<<ngaylapthe<<endl;
    cout<<"so thang co hieu luc cua the: "<<sothangcohieuluccuathe<<endl;
}
CDOCGIA::CDOCGIA(){};
CDOCGIA::~CDOCGIA(){};