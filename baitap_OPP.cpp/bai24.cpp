/*Câu 24: 
Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (lớn hơn), + (cộng).
3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng là các phân số (tối đa 10 phần tử). Tìm phân số có giá trị lớn nhất, tính tổng các phân số trong danh sách có giá trị lớn hơn 1/4.
Câu 25: Viết chương trình thực hiện các yêu cầu sau:
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class PS1{
	protected:
		int tuso,mauso;
	public:
		PS1(){
			this->tuso=0;
			this->mauso=1;
		}
		PS1(int tuso,int mauso){
			this->tuso=tuso;
			this->mauso=mauso;
		}
		void importps(PS1&);
		void exportps(PS1);
		PS1 rutgon(PS1&);
};

void PS1::importps(PS1 &ps){
	cout<<"\timport tuso: ";cin>>ps.tuso;
	cout<<"\tmport mauso: ";cin>>ps.mauso;
}

void PS1::exportps(PS1 ps){
	if(ps.mauso==1)
		cout<<ps.tuso<<endl;
	else 
		cout<<ps.tuso<<"/"<<ps.mauso<<endl;
}

int gcd(int a,int b){
	a=abs(a);
	b=abs(b);
	if(a==0||b==0)
		return a+b;
	return gcd(b,a%b);
}

PS1 PS1::rutgon(PS1 &ps){
	int x=gcd(ps.tuso,ps.mauso);
	ps.tuso/=x;
	ps.mauso/=x;
	return ps;
}
class PS2:public PS1{
	public:
		void operator=(const PS2&);
		bool operator>(const PS2&);
		PS2 operator+(const PS2&);
		void psmax(PS2 [],int);
		void cacpscogiatrilonhon1phantu(PS2 [],int);
};

PS2 PS2::operator+(const PS2 &ps){
	PS2 tong;
	tong.tuso=this->tuso*ps.mauso+this->mauso*ps.tuso;
	tong.mauso=this->mauso*ps.mauso;
	return tong;
}
bool PS2::operator>(const PS2 &ps){
	return (1.0*this->tuso/this->mauso)>(1.0*ps.tuso/ps.mauso);
}
void PS2::psmax(PS2 ps[],int n){
	float max=0;
	int dem;
	for(int i=0;i<n;i++){
		float ans=1.0*ps[i].tuso/ps[i].mauso;
		if(ans>max){
			max=ans;
			dem=i;
		}
	}
	ps[dem].exportps(ps[dem]);
}
void PS2::cacpscogiatrilonhon1phantu(PS2 ps[],int n){
	float sum=0;
	float x=1.0/4;
	for(int i=0;i<n;i++){
		if((1.0*ps[i].tuso/ps[i].mauso)>x)
			sum+=1.0*ps[i].tuso/ps[i].mauso;
	}
	cout<<sum<<endl;
}


int main(){
	int n;
	do{
		cout<<"NHAP SO LUONG PHAN SO:";
		cin>>n;
		if(n<=0&&n>10)
			cout<<"yeu cau lap lai"<<endl;
	}while(n<=0&&n>10);
	PS2 ps[n];
	cout<<"--------------------------------\n";
	for(int i=0;i<n;i++){
		cout<<"NHAP PHAN SO THU "<<i+1<<endl;
		ps[i].importps(ps[i]);
	}
	cout<<"-----------------------------------\n";
	cout<<"DANH SACH PHAN SO DA NHAP"<<endl;
	for(int i=0;i<n;i++){
		ps[i].exportps(ps[i]);
	}
	cout<<"DANH SACH PHAN SO SAU KHI RUT GON"<<endl;
	for(int i=0;i<n;i++){
		ps[i].rutgon(ps[i]);
	}
	for(int i=0;i<n;i++){
		ps[i].exportps(ps[i]);
	}
	cout<<"MAX:";
	ps->psmax(ps,n);
	cout<<"tong cac phan tu lon 1/4"<<endl;
	ps->cacpscogiatrilonhon1phantu(ps,n);
	return 0;
}











