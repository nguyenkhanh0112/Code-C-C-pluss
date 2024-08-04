/*
1. vector ban chat la 1 mang 1 chieu - cu the no la 1 cai mang dong - 1 cái siêu mảng động 
TAI SOA NO LÀ SIÊU MANG ĐỘNG 
+vector có hết tất cả các tính chất mà mảng 1 chiều (mảng tĩnh và mảng động) và có thêm 1 số tính chất riêng của nó nữa
+nếu nhu chúng ta dùng mảng tĩnh hay mảng động thì khai báo kích thước của mảng cần thao tác 
trước 
còn vector khoong càn khai báo trước số lượng phần tử cần dùng- bởi vì nó được hỗ trợ cái cơ chế tự động thêm phần tử vào cuối (push_back());
+ tự động giải phogns vùng nhớ khi chương trình kết thúc 
+ các thao tác thêm. xóa , sửa ,tìm kiếm ,sắp xếp bên mảng 1 chiều (tĩnh hay động )thì chúng ta phỉa đi cài đặt còn bên vector sẽ hỗ trợ chugnx ta các hàm xử lí tương tự 

nhược điểm 
    - tốn bọ nhớ hơn mảng tĩnh và mảng động (do cơ chế containẻ buộc phait tạo ra thêm các vùng nhớ riêng để quản lí chặt chẽ hơn)
    vector:thuộc thư viện chuẩn của c++-STL(Standard Template Library)
*/

#include<iostream>
#include<vector>

using namespace std;

/*CÚ PHÁP: vector<T><tên vector>
T: kiểu dữ liệu của mảng 1 chiều vector
vector<int> arr; // khia bao mang vector chua cac so nguyen
*/
void xuat(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr.at(i)<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr;// khai bao mang vector chua cac so nguyen
    for(int i=1;i<=5;i++){
        arr.push_back(i);// them phan tu i vao cuoi mang 
    }
    xuat(arr);
    arr.pop_back();
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;
    //arr.erase(arr.begin()+2);
    //arr.insert(arr.begin()+2,69);
    xuat(arr);
    //arr.clear();// xoa het tat ca ca phan tu trong mang vector
    vector<int> x;
    for(int i=11;i<=15;i++){
        x.push_back(i);
    }
    arr.swap(x);//hoan doi 2 cai mang vector cho nhau 
    xuat(x);
    xuat(arr);
    return 0;
}