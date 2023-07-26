#include<bits/stdc++.h>
using namespace std;

int main(){
	int so_lan_do;
	cout << "Nhap so lan do: ";
	cin >> so_lan_do;
	cout << endl;

	float cac_lan_do[so_lan_do], tong_cac_lan_do
	, tong_sai_so_cac_lan_do;
	
	cout << "Nhap cac lan do: " << endl;
	for(int i = 0; i < so_lan_do; i++){
		cout << "Lan " << i + 1 << " : ";
		cin >> cac_lan_do[i];
		tong_cac_lan_do += cac_lan_do[i];
	}
	cout << endl;
		
	float sai_so_dung_cu;
	cout << "Nhap sai so dung cu: ";
	cin >> sai_so_dung_cu;
	cout << endl;
	
	float tb_cac_lan_do = tong_cac_lan_do/so_lan_do;
	
	for(int i = 0; i < so_lan_do; i++){
		tong_sai_so_cac_lan_do += abs(cac_lan_do[i] - tb_cac_lan_do);
	}
	
	float tong_sai_so_tb = tong_sai_so_cac_lan_do/so_lan_do;
	
	cout << "Trung binh cac lan do: " << fixed << setprecision(3) << tb_cac_lan_do << endl;
	cout << "Sai so trung binh cac lan do: " << fixed << setprecision(3) << tong_sai_so_tb << endl;
	cout << "Sai so tuyet doi: " << fixed << setprecision(3) << tb_cac_lan_do << " +- " << tong_sai_so_tb + sai_so_dung_cu << endl;
}
