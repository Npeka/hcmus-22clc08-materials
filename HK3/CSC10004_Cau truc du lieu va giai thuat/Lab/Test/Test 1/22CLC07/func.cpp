#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

struct Flight {
    string src; // source 
    string des; // destination
    int hours; 
    int mins;
};
struct Node {
    Flight base;
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};

void todo(string flightdata_filename, string data_filename);
void printmatrix2d(char** matrix, int d1, int d2);
void printlist(List& list);
void deleverything_matrix2d(int** &matrix2d, int m, int n);
void deleverything_list(List& list);
void main_debug()
{

}


int main(int argc, char **argv){
    if (argc == 1) {
        main_debug();
    }
    else {
        int idx_argv = 1;
        string flightdata_filename = argv[idx_argv++];
        string data_filename = argv[idx_argv++];
        todo(flightdata_filename, data_filename);
    }
    cout << "\n";
    return 0;
}
void printmatrix2d(char** matrix, int d1, int d2) {
    for (int i = 0; i < d1; i++){
        for (int j = 0; j  < d2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
void printlist(List& list){
    for (Node* node = list.head; node != NULL; node = node->next){
        cout << node->base.src << "," << node->base.des << "," << node->base.hours << "," << node->base.mins << "\n";
    }
}
void deleverything_matrix2d(char** &matrix2d, int m, int n){
    for (int i = 0; i < m ; i++) {
        delete[] matrix2d[i];
    }
    delete[] matrix2d;
}
void deleverything_list(List& list){
    for (Node *head = list.head; list.head != NULL; head = list.head) {
        list.head = head->next;
        delete head; head = NULL;
    }
}