#include <bits/stdc++.h>
using namespace std;

struct sinhVien {
	string mssv, hoTen, ngaySinh, lop, email, password;
	float gpa;

	sinhVien(string m = "", string h = "", string ns = "", string l = "", float g = 0)
		: mssv(m), hoTen(h), ngaySinh(ns), lop(l), email(""), password(""), gpa(g) {}
};



sinhVien nhap(unordered_map<string, int>& MSSV, map<string, sinhVien>& msv_sv);

void nhapDs(vector<sinhVien> &ds, int n, unordered_map<string, int>& MSSV, map<string, sinhVien>& msv_sv); // 1, 8

void print(sinhVien sv); // 2, 6

void inDs(const vector<sinhVien>& ds); // 2

void reformatNames(vector<sinhVien>& ds);

void generateEmailAndPassword(vector<sinhVien>& ds, unordered_map<string, int>& emailHeader, map<string, sinhVien>& msv_sv); // 4

void descendingSortGPA(vector<sinhVien>& ds); // 5

void findAndPrint(string msv, map<string, sinhVien>& msv_sv); // 6

void timTheoTen(const vector<sinhVien>& ds); // 7



int main(){
	int n;
	vector<sinhVien> ds;
	unordered_map<string, int> emailHeader, MSSV;
	map<string, sinhVien> msv_sv; // 6
	
	while(true){
		cout << "---------------oOo---------------------\n";
		cout << " 1. Them danh sach sinh vien\n";
		cout << " 2. In ra danh sach nha vien\n";
		cout << " 3. Chuan hoa ten tat ca sinh vien\n";
		cout << " 4. Tao email va mat khau cho sinh vien\n"; //Nguyen Van Manh => manhnv@edu.com
		cout << " 5. Sap xep sinh vien theo GPA giam dan\n";
		cout << " 6. Tim kiem sinh vien theo MSSV\n";
		cout << " 7. Tim kiem sinh vien theo ten\n";
		cout << " 8. Them 1 sv vao danh sach\n";
		cout << " 9. Thoat he thong\n";
		cout << "---------------oOo---------------------\n";
		cout << "Moi nhap lua chon: ";
		int lc;
		cin >> lc;
		if(lc == 1){
			cout << "Nhap so luong sinh vien: ";
			cin >> n;//du enter
			nhapDs(ds,n, MSSV, msv_sv);
		}                
		else if(lc == 2){
			inDs(ds);
		}
		else if(lc == 3){
			reformatNames(ds);
		}
		else if(lc == 4){
			generateEmailAndPassword(ds, emailHeader, msv_sv);
		}
		else if(lc == 5){
			descendingSortGPA(ds);
		}
		else if(lc == 6){
			cin.ignore();
			cout << "Nhap ma sinh vien can tra cuu: ";
			string msv;
			getline(cin, msv);
			findAndPrint(msv, msv_sv);
		}
		else if(lc == 7){
			timTheoTen(ds);
		}
		else if(lc == 8){
			nhapDs(ds, 1, MSSV, msv_sv);
		}
		else {
			break;//Thoat he thong
		}
	}
	cout << "Ket thuc(.)";	
}




sinhVien nhap(unordered_map<string, int>& MSSV, map<string, sinhVien>& msv_sv){
	sinhVien input;
	
	cout << "Nhap ma sv: ";
	string maSV;
	getline(cin, maSV);
	while (MSSV.count(maSV)){
		cout << "Ma sinh vien da ton tai, vui long nhap ma khac!\n" 
			 << "Nhap lai ma SV: ";
		getline(cin, maSV);
	}
	input.mssv = maSV;
	MSSV.insert({maSV, 1});
	
	
	cout << "Nhap ho va ten sv: ";
	getline(cin, input.hoTen);
	
	cout << "Nhap ngay sinh cua sv(dd/mm/yy): ";
	getline(cin, input.ngaySinh);
	
	cout << "Nhap lop cua sv: ";
	getline(cin, input.lop);
	
	cout << "Nhap diem cua sv: ";
	cin >> input.gpa;
	
	
	msv_sv.insert({maSV, input});
	
	return input;
}

void nhapDs(vector<sinhVien> &ds, int n, unordered_map<string, int>& MSSV, map<string, sinhVien>& msv_sv){
	for(int i = 0; i < n; i++){
		cin.ignore();
		cout << "Nhap thong tin sinh vien " << i + 1 << ": \n";
		sinhVien sv = nhap(MSSV, msv_sv);
		ds.push_back(sv);
	}
}

void print(sinhVien sv){
	cout << "MSSV: " << sv.mssv << " | " << "HoTen: " << sv.hoTen << " | " 
	 	 << "NgaySinh: " << sv.ngaySinh << " | " << "Lop: " << sv.lop << " | " << "GPA: ";
	printf("%.1f", sv.gpa); 
	if (sv.email != "") cout << " | Email: " << sv.email; 
	if (sv.password != "") cout << " | " << "Password: " << sv.password;
	cout << endl;
}

void inDs(const vector<sinhVien>& ds){
//	for(const sinhVien& sv : ds){
//		print(sv);
//	}
	
	cout << "+----------+------------------------------+------------+----------+------+----------------------+--------------+\n";
    cout << "|    MSSV  |             Ho ten           |  Ngay sinh |    Lop   |  GPA |         Email        |   Password   |\n";
    cout << "+----------+------------------------------+------------+----------+------+----------------------+--------------+\n";
    
    for (const sinhVien& sv : ds){
    	cout << "| " << setw(8) << right << sv.mssv
    		 << " | " << setw(28) << right << sv.hoTen
			 << " | " << setw(10) << right << sv.ngaySinh 
			 << " | " << setw(8) << right << sv.lop
             << " | " << fixed << setprecision(1) << setw(4) << right << sv.gpa
             << " | " << setw(20) << right << sv.email
             << " | " << setw(12) << right << sv.password << " |\n";
	}
	cout << "+----------+------------------------------+------------+----------+------+----------------------+--------------+\n";
}

void reformatNames(vector<sinhVien>& ds){
	if (ds.empty()) {
		cout << "Chua co Sinh Vien nao!\n";
		return;
	}

	for (sinhVien& sv : ds){
		stringstream ss(sv.hoTen);
		string word = "", newName = "";
		while (ss >> word){
			word[0] = toupper(word[0]);
			for (int i = 1; i < (int)word.size(); i++){
				word[i] = tolower(word[i]);
			}
			newName = newName + word + " ";
		}
		newName = newName.substr(0, (int)newName.size() - 1);
		sv.hoTen = newName;
	}
	cout << "Da chuan hoa ten cho toan bo SV\n";
}

void generateEmailAndPassword(vector<sinhVien>& ds, unordered_map<string, int>& emailHeader, map<string, sinhVien>& msv_sv){
	if (ds.empty()) {
		cout << "Chua co Sinh Vien nao!\n";
		return;
	}
	
	
	for (sinhVien& sv : ds){
		
	// email
		if (sv.email == "" && sv.password == ""){
			stringstream ss(sv.hoTen);
			string curr = "", last = "", head = "";
			while (ss >> curr){
				last += tolower(curr[0]);
			}
			last = last.substr(0, (int)last.length() - 1);
			head = curr;
			for (char& c : head) c = tolower(c);
			head = head + last;
			if (emailHeader.count(head) && emailHeader[head] > 1){
				head += to_string(emailHeader[head]);
			}else emailHeader[head]++;
			
			sv.email = head + "@gmail.com";
		
		
	// password	
			ss.clear(); curr = "";
			ss.str(sv.ngaySinh);
			string pass = "";
			while (getline(ss, curr, '/')){
				pass += curr;
			}
			sv.password = pass;
			
			msv_sv[sv.mssv] = sv;
		}
	}
	cout << "Da tao email va mat khau cho SV!\n";
}

void findAndPrint(string msv, map<string, sinhVien>& msv_sv){
	if (!msv_sv.count(msv)){
		cout << "Khong tim thay Sinh Vien nao co MSV: " << msv << "!\n";
	}else print(msv_sv[msv]);
}



void descendingSortGPA(vector<sinhVien>& ds){
	int n = ds.size();
	if (n <= 1) return;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (ds[j].gpa < ds[j + 1].gpa){
				sinhVien tmp = ds[j];
				ds[j] = ds[j + 1];
				ds[j + 1] = tmp;
			}
		}
	}
	cout << "Da sap xep danh sach theo thu tu giam dan GPA\n";
}

void timTheoTen(const vector<sinhVien>& ds){
	if (ds.empty()){
		cout << "Chua co Sinh Vien nao!\n";
		return;
	}
	
	cin.ignore();
	cout << "Nhap ten hoac mot phan ten can tim: ";
	string keyword;
	getline(cin, keyword);
	for (char& c : keyword) c = tolower(c);
	
	bool found = false;
	for (const sinhVien& sv : ds){
		string lowerName = sv.hoTen;
		for (char& c : lowerName) c = tolower(c);
		
		if (lowerName.find(keyword) != string::npos){
			print(sv);
			found = true;
		}
	}
	
	if (!found) cout << "Khong tim thay Sinh Vien :<\n";
}