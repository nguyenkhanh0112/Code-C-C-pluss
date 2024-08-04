#include<iostream>
#include<fstream>

using namespace std;

int main(){
    //====================== DOC FILE =============================
    // cu phap: ifstream<ten bien file>;
    // BUOC 1: KHAI BAO RA BIEN DE DOC FILE 
    // BUOC 2: MO FILE CAN DOC DU LIEU
    // open(<TEN DUONG DAN DEN FILE CAN MO- DE DOC DU LIEU>,<CHE DO LAM VIEC VOI FILE>)
    ifstream filein; // khai bao mot bien filenin de doc du lieu 
    filein.open("C:\\Users\\Admin\\OneDrive\\Desktop\\New Text Document.txt",ios_base::in);
    if(filein.fail()==true){
        cout<<"\nfile ko ton tai "<<endl;
        system("pause");
        return 0;
    }
    // BUOC 3: XU LI FILE -DOC DU LIEU TU FILE RA TRUONG CHINH 
    int x,y;
    //cin>>x;
    filein>>x;// doc du lieu so nguyen tu file

    //cin>>y;
    filein>>y;// doc du lieu so nguyen tiep theo tu
    
    // BUOC 4 DONG  FILE LAI SAU KHU SU LI 
    filein.close();// dong file lai sau khi xu li
    //====================== GHI FILE =============================
    // cu phap: ofstream<TEN BIEN FILE>;
    ofstream fileout;
    fileout.open("C:\\Users\\Admin\\OneDrive\\Desktop\\OUTPUT.txt",ios_base::out);
    fileout << x + y;// ghi du lieu lay x + y roi ghi vao file  New Text Document.txt
    fileout<<20;

    fileout.close();

    system("pause");
    return 0;
}
/*================================ CAC CHE DO MO TEP TIN <FILE> =======================
    ios::in                        Mo mot tep tin de doc
    ios::out                       Mo mot tep tin co san de ghi 
    ios::app                       Mo tep tin co san de them du lieu vao cuoi tep      
    ios::ate                       Mo tep tin va dat con tro tep tin vao cuoi tep 
    ios::trunc                     Neu tep tin co san thi du lieu cua no se bi mat
    ios::nocreate                  Mo tep tin, tep tin nay bat buoc phai ton tai
    ios::noreplace                 Chi mo tep tin khi tep tin chua ton tai 
    ios::binary                    Mo mot tep tin o che do nhi phan.Khi ma file duoc mo ra,
    o che do nay thi du lieu se duoc doc hay ghi tu 1 dinh dang nguyen thuy nhi phan 
    ios::text                      Mo mot tep tin o che do van ban
*/