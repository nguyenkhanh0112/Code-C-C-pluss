/*
định dang trong file SINHVIEN.TXT nhu sau:
- dong dau tien la thong tin cua 1 sinh vien:
    + ho ten: toi da 30 ki tu 
    + ma sinh vien: toi da 10 ki tu
    + ngay thang nam sinh: 1 chuoi string dinh dang đ/mm/yyyy
    - dong thu 2 la so luong cac mon hoc
    - cac dong tiep theo la
    + danh sach cac mon hoc va diem tuong un 
yeu cau:
    1.doc du lieu file SINHVIEN.TXT
    2.nhap vao ten sinh vien va in ra man hinh thong itn sinh vien co ten trung voi ten can tim
    3.luu vao file NAMSINH.TXT thong tin cac sinh vien cos nam sinh yyyy nhap tu ban phim 
    4.luu vao file DIEMMAX.TXT thong tin sinh vien va mon hoc co diem cao nhat cua tung sinh vien tuong ung 
    5. doc du lieu tu file  DIEMMAX.TXT va luu vao file DEM.TXT tong so mon hoc hien co cua tat ca sinh vien
*/

#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
//khai bao cau truc mon hoc 
struct MH{
    string tenmonhoc;
    float diem;
};
//khai bao cau truc sinh vien
struct SV{
    string hoten;
    string maso;
    string namsinh;
    vector<MH> DS_MH;
};
// HAM DOC FILE THONG TIN SINH VIEN 
void doc_file_thong_tin_sinhvien(ifstream &filein,SV &sv){
    getline(filein,sv.hoten,',');//doc du lieu den dau ',';
    getline(filein,sv.maso,',');
    getline(filein,sv.namsinh);

}
void doc_file_thong_tin_mon_hoc(ifstream &filein,MH &mon){
    getline(filein,mon.tenmonhoc,'-');
    filein>>mon.diem;
}
// ham doc thong tin sinh vien va danh sach mon hoc tuong ung 
void doc_file(ifstream &filein,vector<SV> &ds_sinhvien){
    // vong lap lap den cuoi file thi dung 
    while(filein.eof()==false){
        SV sv;// khai bao sv de nhan du lieu tu file 
        // buoc 1: doc thong tin cua 1 sv 
        doc_file_thong_tin_sinhvien(filein,sv);
        // buoc 2: doc so luong mon hoc ma sinh vien se hoc 
        int x;// so luong mon hoc 
        filein>>x;// doc du lieu ma so luong mon hoc 
        // buoc 3 doc danh sach mon hoc ma thang sinh vien da hoc 
        string temp;
        getline(filein,temp);
        for(int i=0;i<x;i++){
        MH mon;
        doc_file_thong_tin_mon_hoc(filein,mon);
        getline(filein,temp);
        sv.DS_MH.push_back(mon);// them 1 mon hoc vao cuoi vector 
        }
        // buoc 4: them thong tin sinh vien vao mang 1 chieu vector sinh vien - danh sach sinh vien
        ds_sinhvien.push_back(sv);
    }
}
// ham xuat du lieu CUA 1 SV
void xuat_thong_tin_sinh_vien(SV sv){
    cout<<"\nHO TEN SINH VIEN: "<<sv.hoten;
    cout<<"\nMA SO SINH VIEN: "<<sv.maso;
    cout<<"\nNGAY THANG NAM SINH: "<<sv.namsinh;
}
void xuat_thong_tin_mon_hoc(MH mon){
    cout<<"\nten mon hoc: "<<mon.tenmonhoc;
    cout<<"\ndiem: "<<mon.diem;
}
// ham test xuat du lieu sinh vien
void test(vector<SV>ds){
    for(int i=0;i<ds.size()-1;i++){
        cout<<"\n\t\tSINH VIEN THU: "<<i+1<<endl;
        // goi ham xuat thong tin sv
        xuat_thong_tin_sinh_vien(ds[i]);
        cout<<"\n====== DANH SACH MON HOC TUONG UNG  ======="<<endl;
        // xua ra danh sach ca mon hoc 
        for(int j=0;j<ds[i].DS_MH.size()-1;j++){
            cout<<"\nMON HOC THU: "<<j+1;
            xuat_thong_tin_mon_hoc(ds[i].DS_MH[j]);
        }   
    }
}
// CAU 2 : HAM XUAT TAT CA THONG TIN CUA SINH VIEN CO TEN TRUNG 
void Tim_kiem_sinhvine_the_ten(vector<SV> ds,string hoten){
    for(int i=0;i<ds.size();i++){
        // dung ham so sanh 2 chuoi ko phan biet in hoa in thuong 
        if(stricmp(ds[i].hoten.c_str(),hoten.c_str())==0){
            cout<<"\n\n\t\t\t SINH VIEN THU: "<<i+1;
            //buoc 1: xuat thong tin cua sinh vien
            xuat_thong_tin_sinh_vien(ds[i]);
            // buoc 2: xuat ra danh sach cac mon hoc cu sinh vien tuong ung 
            int n = ds[i].DS_MH.size();// so luong cac mon hoc 
            for(int j=0;j<n;j++){
                cout<<"\n\t\t MON HOC THU: "<<j+1;
                xuat_thong_tin_mon_hoc(ds[i].DS_MH[j]);
            }
        }
    }
}
string Tach_nam_sinh(string str){
    string temp;// chua nam sinh khi tach tu chuoi ngay thang nam 
    for(int i= str.length()-1;i>=0;i--){
        if(str[i]>='0'&&str[i]<='9')
            temp.insert(temp.begin()+0,str[i]);
        else 
            break;
    }
    return temp;
}
//ham ghi thong tin mon hoc
void ghi_thong_tin_mon_hoc(ofstream &fileout,MH mon){
    fileout<<mon.tenmonhoc<<"-"<<mon.diem<<endl;
}
// ham ghi vao file thong tin sinh vine 
void ghi_thong_tin_sinhvien(ofstream &fileout,SV sv){
    fileout<<sv.hoten<<","<<sv.maso<<","<<sv.namsinh<<endl;
    fileout<<sv.DS_MH.size()<<endl;
    for(int i=0;i<sv.DS_MH.size();i++){
        ghi_thong_tin_mon_hoc(fileout,sv.DS_MH[i]);
        cout<<endl;
    }
}
// ham luu thong tin sinh vien vao file NAMSINH.TXT
void luu_file_namsinh(ofstream &fileout ,vector<SV> ds,string namsinh){
    for(int i=0;i<ds.size();i++){
        string temp = Tach_nam_sinh(ds[i].namsinh);
        if(stricmp(temp.c_str(),namsinh.c_str())==0){
            ghi_thong_tin_sinhvien(fileout,ds[i]);
        }
    }
}
int main(){
    ifstream filein;
    filein.open("SINHVIEN.TXT",ios_base::in);
    vector <SV> ds_sinhvien;
    doc_file(filein,ds_sinhvien);
    //cout<<"\nDU LIEU DA DOC THANH CONG "<<endl;
    //test(ds_sinhvien);
    //string hoten;
    //cout<<"\nNHAP HO TEN SINH VIEN CAN TIM KIEM: ";getline(cin,hoten);
    //Tim_kiem_sinhvine_the_ten(ds_sinhvien,hoten);
    ofstream fileout;
    fileout.open("NAMSINH.TXT",ios_base::app);
    string namsinh;
    cout<<"\nnhap nam sinh: ";
    getline(cin,namsinh);
    luu_file_namsinh(fileout,ds_sinhvien,namsinh);
    filein.close();
    fileout.close();
    system("pause");
    return 0;
}