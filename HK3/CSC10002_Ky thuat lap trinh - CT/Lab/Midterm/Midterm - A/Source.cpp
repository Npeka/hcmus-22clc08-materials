#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
struct HocSinh
{
	char* hoTen;
	char* maSo;
	double diemTB;
};
struct Option
{
	int min, max;
};
double GenerateRandom(const Option& opt)
{
	double x = rand() % (opt.max - opt.min + 1) + opt.min + (rand() % 10) / 8.0;
	if (x > opt.max) x--;
	return x;
}
void ExtractInfo(const char* strInput, char*& pHT, char*& pMS)
{
	string input(strInput);
	stringstream ss(input);
	string pht, pms;
	getline(ss, pht, '-');
	getline(ss, pms);

	pHT = new char[pht.size() + 1];
	pMS = new char[pms.size() + 1];

	strcpy_s(pHT, pht.size() + 1, pht.c_str());
	strcpy_s(pMS, pms.size() + 1, pms.c_str());
}
HocSinh* CreateHocSinh(const char* strInput, const int& dtbMin, const int& dtbMax)
{
	HocSinh* hs = new HocSinh;
	ExtractInfo(strInput, hs->hoTen, hs->maSo);
	hs->diemTB = GenerateRandom({ dtbMin, dtbMax });
	return hs;
}
void FreeHocSinh(HocSinh* pHS)
{
	delete pHS->hoTen;
	delete pHS->maSo;
}
char* HocSinhToString(const HocSinh* pHS)
{
	string s = (string)pHS->hoTen + " - " + (string)pHS->maSo + " [" + to_string(pHS->diemTB) + "]";
	char* line = new char[s.size() + 1];
	strcpy_s(line, s.size() + 1, s.c_str());
	return line;
}
void Load(const char* path, HocSinh**& data, int& nCol, int& nRow)
{
	ifstream infile(path);
	infile >> nCol >> nRow;
	infile.ignore();

	string line;
	data = new HocSinh * [nRow];
	for (int i = 0; i < nRow; i++){
		data[i] = new HocSinh[nCol];
		for (int j = 0; j < nCol; j++){
			getline(infile, line, '\n');
			HocSinh* tmp = CreateHocSinh(line.c_str(), 1, 10);
			data[i][j] = *tmp;
			delete tmp;
		}
	}
	infile.close();
}
void FreeData(HocSinh**& data, const int& nCol, const int& nRow)
{
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			FreeHocSinh(&data[i][j]);
		}
		delete[] data[i];
	}
	delete data;
}
void PrintData(HocSinh** data, const int& nCol, const int& nRow)
{
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			char* tmp = HocSinhToString(&data[i][j]);
			cout << tmp << '\t';
			delete[] tmp;
		}
		cout << '\n';
	}
}
//void PrintTheBestHocSinh(data, nCol, nRow);
void main()
{
	srand(7103);
	const char* path = "data.txt";
	HocSinh** data = NULL;
	int nCol = 0, nRow = 0;
	Load(path, data, nCol, nRow);
	PrintData(data, nCol, nRow);
	cout << endl << endl;
	/// xuất ra màn hình Học sinh có điểm trung bình lớn nhất
	/// cần thông tin vị trí của Học sinh
	//PrintTheBestHocSinh(data, nCol, nRow);
	FreeData(data, nCol, nRow);
	system("pause");
}