#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

struct Flight {
    string src; // source 
    string des; // destination
    string airliner; // name of airliner
    int eco; // economy seats
    int bus; // business seats
    int hours;
    int mins;
    bool operator ==(const Flight& other) const {
        if (src == other.src && des == other.des)
            return true;
        else
            return false;
    }
    bool operator > (const Flight& other) const{
        if (src > other.src)
            return true;
        else if (src == other.src && des > other.des)
            return true;
        return false;

    }
    bool operator < (const Flight& other) const {
        if (src < other.src)
            return true;
        else if (src == other.src && des < other.des)
            return true;
        return false;
    }
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

vector<Flight> readFileJL(string fileName) {
    vector<Flight> v;
    ifstream fileIn;
    fileIn.open(fileName.c_str(), ios::in);
    string s;
    while (getline(fileIn, s, '\n')) {
        Flight  f;
        string tmp;
        stringstream ss(s);
        ss.ignore(2);
        getline(ss, f.src, ',');
        getline(ss, f.des, '"');
        ss.ignore(4);
        getline(ss, f.airliner, '"');
        ss.ignore(3);
        ss >> f.bus;
        ss.ignore();
        getline(ss, tmp, ' ');
        ss >> f.eco;
        getline(ss, tmp, '"');
        getline(ss, tmp, '"');
        ss >> f.hours;
        ss.ignore();
        getline(ss, tmp, ' ');
        ss >> f.mins;
        ss.clear();
        v.push_back(f);
    }
    fileIn.close();
    return v;
}
void readFileData(string fileName, string& level_list, int& alpha) {
    ifstream fileIn;
    fileIn.open(fileName.c_str(), ios::in);
    getline(fileIn, level_list, '\n');
    fileIn >> alpha;
    fileIn.close();
}
bool isInTree(string des, int alpha) {
    if (des.size() < alpha)
        return true;
    return false;
}
Node* createNode(Flight f) {
    return new Node{ f, NULL, NULL };
}
void insert(Node*& pRoot, Flight f) {
    if (pRoot == NULL)
        pRoot = createNode(f);
    else if (pRoot->base < f) {
        insert(pRoot->right, f);
    }
    else if (pRoot->base > f) {
        insert(pRoot->left, f);
    }
}
Node* createTree(vector<Flight> f, int alpha) {
    Node* pRoot = NULL;
    for (int i = 0; i < f.size(); i++) {
        if (isInTree(f[i].des, alpha)) {
            insert(pRoot, f[i]);
        }
    }
    return pRoot;
}
void LNR(Node* pRoot) {
    if (pRoot == NULL)
        return;
    LNR(pRoot->left);
    cout << pRoot->base.src << ',' << pRoot->base.des << ',' << pRoot->base.airliner << ' ' << pRoot->base.bus
        << ',' << pRoot->base.eco << ',' << pRoot->base.hours << ',' << pRoot->base.mins << '\n';
    LNR(pRoot->right);
}
void helperPrintLevel(Node* pRoot, int level) {
    if (pRoot == NULL)
        return;
    if (level == 0)
        cout << pRoot->base.src << ',' << pRoot->base.des << ',' << pRoot->base.airliner << ' ' << pRoot->base.bus
        << ',' << pRoot->base.eco << ',' << pRoot->base.hours << ',' << pRoot->base.mins << '\n';
    helperPrintLevel(pRoot->left, level - 1);
    helperPrintLevel(pRoot->right, level - 1);
}
void printLevelList(string level_list, Node* pRoot) {
    stringstream ss(level_list);
    int level;
    while (ss >> level) {
        ss.ignore();
        helperPrintLevel(pRoot, level);
    }
}
bool haveConsonant(string src) {
    if (src.size() <= 0)
        return false;
    if (src[0] == 'A' || src[0] == 'E' || src[0] == 'I' || src[0] == 'O' || src[0] == 'U')
        return true;
    return false;
}
void deleteNode(Node*& pRoot, Flight f) {
    if (pRoot == NULL)
        return;
    if (pRoot->base < f)
        deleteNode(pRoot->right, f);
    else if (pRoot->base > f)
        deleteNode(pRoot->left, f);
    else {
        if (pRoot->left == NULL) {
            Node* resNode = pRoot;
            pRoot = pRoot->right;
            delete resNode;
        }
        else if (pRoot->right == NULL) {
            Node* resNode = pRoot;
            pRoot = pRoot->left;
            delete resNode;
        }
        else {
            Node* curNode = pRoot->right;
            while (curNode->left != NULL)
                curNode = curNode->left;
            pRoot->base = curNode->base;
            deleteNode(pRoot->right, curNode->base);
        }
    }
}
void deleteNodeHaveConsonant(Node*& pRoot) {
    if (pRoot == NULL)
        return;
    deleteNodeHaveConsonant(pRoot->left);
    deleteNodeHaveConsonant(pRoot->right);
    if (haveConsonant(pRoot->base.src))
        deleteNode(pRoot, pRoot->base);
}
void findMaxTime(Node* pRoot, int& maxTime) {
    if (pRoot == NULL)
        return;
    maxTime = max(maxTime, pRoot->base.hours * 60 + pRoot->base.mins);
    findMaxTime(pRoot->left, maxTime);
    findMaxTime(pRoot->right, maxTime);
}
void printMaxTime(Node* pRoot, int maxTime) {
    if (pRoot == NULL)
        return;
    printMaxTime(pRoot->left, maxTime);
    if (pRoot->base.hours * 60 + pRoot->base.mins == maxTime)
        cout << pRoot->base.src << ',' << pRoot->base.des << ',' << pRoot->base.airliner << ' ' << pRoot->base.bus
        << ',' << pRoot->base.eco << ',' << pRoot->base.hours << ',' << pRoot->base.mins << '\n';
    printMaxTime(pRoot->right, maxTime);
}
void todo(string flightdata_filename, string data_filename) {
    vector<Flight> f = readFileJL(flightdata_filename);
    //for (int i = 0; i < f.size(); i++) {
    //    cout << f[i].src << ',' << f[i].des << ',' << f[i].airliner << ' ' 
    //        << f[i].bus << ',' << f[i].eco << ',' << f[i].hours << ',' << f[i].mins << '\n';
    //}
    int alpha; string level_list;
    readFileData(data_filename, level_list, alpha);
    Node* pRoot = createTree(f, alpha);
    print_preorder(pRoot);
    cout << "=====================\n";
    printLevelList(level_list, pRoot);
    cout << "=====================\n";
    deleteNodeHaveConsonant(pRoot);
    print_preorder(pRoot);
    cout << "=====================\n";
    int maxTime = INT_MIN;
    findMaxTime(pRoot, maxTime);
    printMaxTime(pRoot, maxTime);
    del_tree(pRoot);
}
void main_debug() {
    todo("g1.v2.jl", "data.txt");
}



int main(int argc, char** argv) {
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
void print_preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->base.src << "," << root->base.des << "," << root->base.airliner << "," << root->base.eco << "," << root->base.bus << "," << root->base.hours << "," << root->base.mins << "\n";
    print_preorder(root->left);
    print_preorder(root->right);
}
void del_tree(Node*& root) {
    if (root == NULL)
        return;
    del_tree(root->left);
    del_tree(root->right);
    delete root; root = NULL;
}