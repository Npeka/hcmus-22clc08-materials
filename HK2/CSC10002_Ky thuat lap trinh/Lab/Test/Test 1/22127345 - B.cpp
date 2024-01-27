#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define N 100

struct People{
    string name;
    int year;
    float height; // <cm>
    float weight; // <kg>
};

/*
Cho ma trận vuông kích thước N * N. 
Hãy tính hiệu của tổng của tích của các số nằm trên các đường chéo chính trừ tổng của tích các số trên các đường chéo phụ. Biết:
- Đường chéo chính là đường chéo chứa các số nằm trên đường chéo từ TRÁI sang PHẢI của ma trận.
- Đường chéo phụ là đường chéo chứa các số nằm trên đường chéo từ PHẢI sang TRÁI của ma trận.

VD: Xét ma trận A

1 2 3
4 5 6
7 8 9

solution_ex01(A, 3) = (1*5*9 + 2*6 + 3 + 4*8 + 7) - (3*5*7 + 2*4 + 1 + 4*8 + 7) = -54 
*/
int solution_ex01(int matrix[][N], int n){
    // TODO
    return -2;
}

/*
Xét chuỗi S có nội dung là HAI phép tính (cộng hoặc trừ hoặc nhân) trên số thực cho trước. 
Hãy cho biết phép tính này có đúng hay không.

VD:
S1 = "10.21 + 2.8 * 2.5 = 17.21"
S2 = "10.21 * 2.8 - 3.4 = 25.188"

solution_ex02(S1) = true
solution_ex02(S2) = false
*/
int solution_ex02(string s){
    // TODO
    return -2;
}

/*
Xét cấu trúc People được định nghĩa ở phía trên.
Mỗi dòng trong file filename cho trước có chứa thông tin của một người (People),
với mỗi trường thông tin cách nhau bở dấu ",". (Xem file "data.txt" đính kèm)

Chỉ số BMI = Cân nặng <kg> / (Chiều cao <m> * 2)
Một người được coi là suy dinh dưỡng khi BMI < 18.5

Hãy viết hàm đọc một file cho trước và cho biết trong file co bao nhiêu người suy dinh dưỡng có tên cho trước.

VD:

solution_ex03("data.txt", "Ti") = 1. 
*/

int solution_ex03(string filename, string firstname){
    // TODO
    return -2;
}

void main_debug(){
    // Main function for student 

}










// DO NOT CHANGE ANYTHING FROM HERE
int main(int argc, char **argv){
    if (argc == 1) {
        main_debug();
    }
    else {
        int idx_argv = 1;
        int n = stoi(argv[idx_argv++]);
        int matrix[N][N];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = stoi(argv[idx_argv++]);
            }
        }
        string s = argv[idx_argv++];
        string filename = argv[idx_argv++];
        string name = argv[idx_argv++];

        cout << "ex01:" << solution_ex01(matrix, n) << "\n";
        cout << "ex02:" << solution_ex02(s) << "\n";
        cout << "ex03:" << solution_ex03(filename, name) << "\n";
    }
    return 0;
}