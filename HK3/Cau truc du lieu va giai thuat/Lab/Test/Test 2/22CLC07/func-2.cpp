#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

struct Flight {
    string src; // source 
    string des; // destination
    string airliner; // name of airliner
    int eco; // economy seats
    int bus; // business seats
    int hours; 
    int mins;
};
struct Node {
    Flight base;
    Node* left;
    Node* right;
};

void todo(string flightdata_filename, string data_filename);
void print_preorder(Node* root);
void del_tree(Node*& root);
void main_debug();


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
void print_preorder(Node* root){
    if (root == NULL){
        return;
    } 
    cout << root->base.src << "," << root->base.des  << "," << root->base.airliner << "," << root->base.eco << "," << root->base.bus << "," << root->base.hours << "," << root->base.mins << "\n";
    print_preorder(root->left);
    print_preorder(root->right);
}
void del_tree(Node*& root){
    if (root == NULL)
        return;
    del_tree(root->left);
    del_tree(root->right);
    delete root; root = NULL;
}