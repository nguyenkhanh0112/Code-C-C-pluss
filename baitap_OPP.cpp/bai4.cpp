/*	Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp time với các thuộc tính: giờ, phút, giây.
Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng time.
2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng time.
3.	Định nghĩa toán từ ++,-- để tăng, giảm một giây. Thực hiện tăng, giảm một giây và in kết quả ra màn hình (kết quả phải được chuẩn hóa dưới định dạng 24 tiếng hh:mm:ss).
*/


#include<iostream>

using namespace std;


class Time{
    private:
        int hours,minute,seconds;
    public:
        Time();
        Time(int ,int ,int);
        ~Time(){};
        void nhap();
        void TGtruocdo();
        void TGsaudo();
};

Time::Time(){
    this->hours=this->minute=this->seconds=0;
}
Time::Time(int seconds,int minute,int hours){
    this->hours=hours;
    this->minute=minute;
    this->seconds=seconds;
}

void Time:: nhap(){
    
        cout<<"nhap seconds: ";cin>>seconds;
        cout<<"nhap minute: ";cin>>minute;
        cout<<"nhap hours: ";cin>>hours;
}
void Time::TGtruocdo(){
    int newseconds=seconds;
    int newminute=minute,newhours=hours;
    if((newseconds>=0&&newseconds<=59)&&(newminute>=0&&newminute<=59)&&(newhours>=0&&newhours<=23)){
        if(newseconds==59&&newminute<59){
            newseconds=0;  
            newminute++;
        }
        else if(newseconds==59&&newminute==59&&newhours<23){
            newseconds=0;
            newminute=0;
            newhours++;
        }
        else if(newseconds==59&&newminute==59&&newhours==23){
            newseconds=0;
            newminute=0;
            newhours=0;
        }
        else 
            newseconds++;
    }
    if((newseconds>=0&&newseconds<=59)&&(newminute>=0&&newminute<=59)&&(newhours>=0&&newhours<=23)){
        if(newseconds>=10&&newminute>=10&&newhours>=10)
            cout<<"\nTime truoc do: "<<newhours<<":"<<newminute<<":"<<newseconds;
        else if(newseconds<10&&newminute<10&&newhours<10)
            cout<<"\nTime truoc do: "<<"0"<<newhours<<":"<<"0"<<newminute<<":"<<"0"<<newseconds;
        else if(newseconds>=10&&newminute>=10&&newhours<10)
            cout<<"\nTime truoc do: "<<"0"<<newhours<<":"<<newminute<<":"<<newseconds;
        else if(newseconds>=10&&newminute<10&&newhours<10)
            cout<<"\nTime truoc do: "<<"0"<<newhours<<":"<<"0"<<newminute<<":"<<newseconds;
        else if(newseconds<10&&newminute>=10&&newhours>=10)
            cout<<"\nTime truoc do: "<<newseconds<<":"<<newminute<<":"<<"0"<<newseconds;
    }
}
void Time::TGsaudo(){
    int newseconds=seconds;
    int newminute=minute,newhours=hours;
    if((newseconds>=0&&newseconds<=59)&&(newminute>=0&&newminute<=59)&&(newhours>=0&&newhours<=23)){
        if(newseconds==0&&newminute<=59){
            newseconds=59;
            newminute--;
        }
        else if(newseconds==0&&newminute==0&&newhours<=23){
            newseconds=59;
            newminute=59;
            newhours--;
        }
        else if(newseconds==0&&newminute==0&&newhours==1){
            newseconds=59;
            newminute=59;
            newhours=0;
        }
        else 
            newseconds--;
    }
    if((newseconds>=0&&newseconds<=59)&&(newminute>=0&&newminute<=59)&&(newhours>=0&&newhours<=23)){
        if(newseconds>=10&&newminute>=10&&newhours>=10)
            cout<<"\nTime sau do: "<<newhours<<":"<<newminute<<":"<<newseconds;
        else if(newseconds<10&&newminute<10&&newhours<10)
            cout<<"\nTime sau do: "<<"0"<<newhours<<":"<<"0"<<newminute<<":"<<"0"<<newseconds;
        else if(newseconds>=10&&newminute>=10&&newhours<10)
            cout<<"\nTime sau do: "<<"0"<<newhours<<":"<<newminute<<":"<<newseconds;
        else if(newseconds>=10&&newminute<10&&newhours<10)
            cout<<"\nTime sau do: "<<"0"<<newhours<<":"<<"0"<<newminute<<":"<<newseconds;
        else if(newseconds<10&&newminute>=10&&newhours>=10)
            cout<<"\nTime sau do: "<<newseconds<<":"<<newminute<<":"<<"0"<<newseconds;
    }
}

int main(){
    Time h;
    h.nhap();
    h.TGtruocdo();
    h.TGsaudo();
    return 0;
}






