// uas 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
float totalx(int nilaix[], int jumlah) {
	int jumlahx = 0;
	for (int i = 0; i < jumlah; i++) {
		jumlahx = jumlahx + nilaix[i];
	}
	return jumlahx;
}
float totaly(int nilaiy[], int jumlah) {
	int jumlahy = 0;
	for (int i = 0; i < jumlah; i++) {
		jumlahy = jumlahy + nilaiy[i];
	}
	return jumlahy;
}

float totalxy(int nilaix[], int nilaiy[], int jumlah) {
	int jumlahxy = 0;
	for (int i = 0; i < jumlah; i++) {
		jumlahxy = (nilaix[i] * nilaiy[i]);
	}
	return jumlahxy;
}

float totalx2(int nilaix[], int jumlah) {
	int totalxkuadrat = 0;
		for (int i = 0; i < jumlah; i++) {
			totalxkuadrat = totalxkuadrat + (nilaix[i] * nilaix[i]);
		}
		return totalxkuadrat;
}

float totaly2(int nilaiy[], int jumlah) {
	int totalykuadrat = 0;
		for (int i = 0; i < jumlah; i++) {
			totalykuadrat = totalykuadrat + (nilaiy[i] * nilaiy[i]);
		}
		return totalykuadrat;
}

float r(int nilaix[ ], int nilaiy[], int jumlah) {
	float total1 = 0;
	float total2 = 0;
	total1 = (totalxy(nilaix, nilaiy, jumlah) - (totalx(nilaix, jumlah) * totaly(nilaiy, jumlah)));
	total2 = total1 / (sqrt(jumlah * totalx2(nilaix, jumlah) - (totalx(nilaix, jumlah) * totalx(nilaix, jumlah))) * (sqrt(jumlah * (jumlah * totaly2(nilaiy, jumlah))) - (totaly(nilaiy, jumlah) * (totaly(nilaiy, jumlah)))));
	return total2;
}

float k(float r) {
	float hasil;
	hasil = (r * r) * (100 / 1);
	return hasil;
}
	



int main() {
	int x, y, jumlah, f, g, h;
	int nilaix[99];
	int nilaiy[99];
	int i[99];

	cout << "masukan jumlah data : ";
	cin >> jumlah;

	for (int i = 0; i < jumlah; i++) {
		cout << "masukan nilai x" << i << ": ";
		cin >> nilaix[i];
		if (nilaix[i] <= 0) {
			cout << "nilai tidak boleh kurang dari 0 dan sama dengan 0, ";
		}
	}

	for (int i = 0; i < jumlah; i++) {
		cout << "masukkan nilai y" << i << ": ";
		cin >> nilaiy[i];
		if (nilaiy[i] <= 0) {
			cout << "nilai tidak boleh kurang dari 0 dan sama dengan 0, ";
		}
	}

	cout << "nilai total x = " << totalx (nilaix, jumlah) << endl;
	cout << "nilai total y = " << totaly (nilaiy, jumlah) << endl;
	cout << "nilai x kuadrat = " << totalx2 (nilaix, jumlah) << endl;
	cout << "nilai y kuadrat = " << totaly2 (nilaiy, jumlah) << endl;
	cout << "nilai x dan y = " << totalxy(nilaix, nilaiy, jumlah) << endl;
	cout << endl;

	cout << "hasil nilai korelasi = " << r (nilaix, nilaiy, jumlah) << endl;
	cout << "hasil koefisien determinasi = " << k(r(nilaix,nilaiy,jumlah)) << " %" << endl;
	cout << "berdasarkan hubungan nilai korelasi yang didapat maka hubungan nya adalah : " << endl;

	if (r(nilaix, nilaiy, jumlah) < 0) {
		cout << "hubungan korelasi diabaikan, dan korelasi bersifat negatif. dimana hubungan antara x dan y adalah negatif, dimana jika nilai x bertambah, maka nilai y akan mengecil. dan juga sebaliknya.";
	}
	else if (r(nilaix, nilaiy, jumlah) < 0.9) {
		cout << "hubungan korelasi diabaikan, dan korelasi bersifat positif, dimana hubungan antara x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun akan bertambah. dan juga sebaliknya.";
	}
	else if (r(nilaix, nilaiy, jumlah) < 0.29) {
		cout << "hubungan korelasi rendah, dan korelasi bersifat positif, dimana hubungan antara x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun akan bertambah. dan juga sebaliknya.";
	}
	else if (r(nilaix, nilaiy, jumlah) < 0.49) {
		cout << "hubungan korelasi moderat, dan korelasi bersifat positif dimana hubungan antara x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun akan bertambah. dan juga sebaliknya.";
	}
	else if (r(nilaix, nilaiy, jumlah) < 0.70) {
		cout << "hubungan korelasi sedang, dan korelasi bersifat positif dimana hubungan antara x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun akan bertambah. dan juga sebaliknya.";
	}
	else if (r(nilaix, nilaiy, jumlah) > 0.70) {
		cout << "hubungan korelasi sangant kuat, dan korelasi bersifat positif dimana hubungan antara x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun akan bertambah. dan juga sebaliknya.";
	}
	return 0;
	


}

