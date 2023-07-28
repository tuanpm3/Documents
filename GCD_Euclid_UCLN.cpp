#include<bits/stdc++.h>
using namespace std;


//Hàm tính uoc chung lon nhat (GCD) su dung thuat toan Euclid 
int gcd(int a, int b){
	while (b != 0 ){   //vong lap tinh GCD theo thuat toan Euclid cho den khi bang 0.
		int temp = b;  //luu giu gia tri cua a vao bien tam thoi temp.
		b = a % b;     // gan gia tri a % b vao b.
		a = temp;     // gan gia tri ban dau cua b vao a.
	}
	return a;
}

int main(){
	int a,b;
	cout << "Nhap hai so nguyen duong: ";
	cin >> a >> b;
	int UCLN = gcd(a,b);
	cout << "Uoc chung lon nhat cua " << a << " va " << b << " la " << UCLN;
	
	return 0;
}
