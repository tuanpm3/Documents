//Tinh UCLN bang phuong phap Brute Force
#include<iostream>
using namespace std;

int gcd(int a, int b){
	int result = min(a,b); // gan result la so nho nhat trong hai so a va b
	while(result > 0){
		if(a % result == 0 && b % result == 0) { //neu a va b cung chia het cho result thi dung lai
			break;
		}
		result--;        // neu khong se giam result cho den khi ca a va b deu chia het cho result
	}
	return result;
}

int main(){
	int a,b;
	cout<<"Nhap hai so nguyen a va b: ";
	cin>> a >> b;
	cout <<"Tim uoc chung lon nhat cua " << a << " va " << b << " la " << gcd(a,b);
	
	return 0;
}

