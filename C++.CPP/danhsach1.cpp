#include<iostream>

using namespace std;

class sinhvien{
	public:
		string name;
		int ngaysinh;
		string gioitinh;
		string diachi;
		string lop;
		void nhap(){
			cout<<"nhap name ";
			getline(cin,name);
			cout<<"nhap ngay sinh ";
			cin>>ngaysinh;
			cin.ignore();
			cout<<"nhap dia chi ";
			getline(cin,diachi);
			cout<<"nhap lop ";
			getline(cin,lop);
	}
		void xuat(){
			cout<<"name "<<name<<endl;
			cout<<"ngay sinh "<<ngaysinh<<endl;
			cout<<"dia chi "<<diachi<<endl;
			cout<<"lop "<<lop<<endl;
		}
	int getNgaysinh(){
		return ngaysinh;
	}
};
void check(sinhvien sv[],int n){
	int tmp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(sv[i].ngaysinh>sv[j].ngaysinh){
				tmp=sv[i].ngaysinh;
				sv[i].ngaysinh=sv[j].ngaysinh;
				sv[j].ngaysinh=tmp;
			}
		}	
	}
}
int main(){
	int n;
	cin>>n;
	cin.ignore(32767,'\n');
	sinhvien sv[n];
	for(int i=0;i<n;i++){
		cout<<"thi sinh thu "<<i+1<<endl;
		sv[i].nhap();
	}
	check(sv,n);
	cout<<"sx tang theo ngay sinh"<<endl;
	for(int i=0;i<n;i++){
		sv[i].xuat();
	}
	return 0;
}
