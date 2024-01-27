#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

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
        return src == other.src && hours * 60 + mins == other.hours * 60 + other.mins && des == other.des;
    }
    bool operator > (const Flight& other) const {
        if (src > other.src)
            return true;
        if (src == other.src){
            if (hours * 60 + mins > other.hours * 60 + other.mins)
                return true;
            if (hours * 60 + mins == other.hours * 60 + other.mins && des > other.des)
                return true;
        }
        return false;
    }
    bool operator < (const Flight& other) const {
        if (src < other.src)
            return true;
        if (src == other.src) {
            if (hours * 60 + mins < other.hours * 60 + other.mins)
                return true;
            if (hours * 60 + mins == other.hours * 60 + other.mins && des < other.des)
                return true;
        }
        return false;
    }
};
struct Node {
    Flight base;
    Node* left;
    Node* right;
};
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
void insert(Node*& root, Node* newNode)
{
    if (root == NULL)
        root = newNode;
    else if (root->base.src < newNode->base.src)
        insert(root->right, newNode);
    else if (root->base.src > newNode->base.src)
        insert(root->left, newNode);
}
Node* readFlightdata(string flightdata_filename)
{
    ifstream infile(flightdata_filename);
    Node* root = NULL;
    string line;
    while (getline(infile, line, '\n'))
    {
        Flight  f;
        string tmp;
        stringstream ss(line);
        ss.ignore(2);
        getline(ss, f.src, ',');
        getline(ss, f.des, '"');
        if (f.src[0] != f.des[0])
            continue;

        ss.ignore(4);
        getline(ss, f.airliner, '"');
        ss.ignore(3);
        ss >> f.bus;
        ss.ignore();
        getline(ss, tmp, ' ');
        ss >> f.eco;
        getline(ss, tmp, '"');
        getline(ss, tmp, '"');
        if (line.find("hour") != string::npos){
            ss >> f.hours;
            if (line.find("minute") != string::npos){
                getline(ss, tmp, ',');
                ss >> f.mins;
            }
            else {
                f.mins = 0;
            }
        }
        else {
            f.hours = 0;
            ss >> f.mins;
        }
        Node* newNode = new Node{ f, NULL, NULL };
        insert(root, newNode);
    }
    infile.close();
    return root;
}
void readData(string data_filename, string& level_list, char& ch)
{
    ifstream infile(data_filename);
    getline(infile, level_list, '\n');
    infile >> ch;
    infile.close();
}
int levelNode(Node* root, Node* node)
{
    if (root == node)
        return 0;

    int level = 0;
    Node* cur = root;
    while (cur != node)
    {
        if (cur->base > node->base)
            cur = cur->left;
        else
            cur = cur->right;
        level++;
    }
    return level;
}
// cau 2
void printLevel(Node* root, int level){
    if (root == NULL)
        return;
    if (level == 0)
        cout << root->base.src << "," << root->base.des << "," << root->base.airliner << "," << root->base.eco << "," << root->base.bus << "," << root->base.hours << "," << root->base.mins << "\n";
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}
void LevelOrder(Node* root, string level_list)
{
    stringstream ss(level_list); int level; 
    while (ss >> level){
        printLevel(root, level);
        ss.ignore();
    }
}
void LevelOrder2(Node* root, string level_list)
{
    queue <Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* cur = q.front();
        if (level_list.find(to_string(levelNode(root, cur))) != string::npos) {
            cout << levelNode(root, cur) << " ";
            cout << cur->base.src << "," << cur->base.des << "," << cur->base.airliner << "," << cur->base.eco << "," << cur->base.bus << "," << cur->base.hours << "," << cur->base.mins << "\n";
        }
        if (cur->left != NULL) q.push(cur->left);
        if (cur->right != NULL) q.push(cur->right);
        q.pop();
    }
}
// cau 3
void removeNode(Node*& root, Flight f)
{
    if (root == NULL)
        return;
    if (root->base > f)
        removeNode(root->left, f);
    else if (root->base < f)
        removeNode(root->right, f);
    else
    {
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if (root->left != NULL && root->right != NULL) {
            Node* cur = root->right;
            while (cur->left != NULL)
                cur = cur->left;
            root->base = cur->base;
            removeNode(root->right, cur->base);
        }
        else if (root->left != NULL) {
            Node* del = root;
            root = root->left;
            delete del;
        }
        else {
            Node* del = root;
            root = root->right;
            delete del;
        }
    }
}
void removeNode2(Node*& pRoot, Flight f) {
    if (pRoot == NULL)
        return;
    if (pRoot->base < f)
        removeNode2(pRoot->right, f);
    else if (pRoot->base > f)
        removeNode2(pRoot->left, f);
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
            removeNode2(pRoot->right, curNode->base);
        }
    }
}
void isRemove(Node*& root, char ch)
{
    if (root == NULL)
        return;
    isRemove(root->left, ch);
    isRemove(root->right, ch);
    if (root->base.src[0] < ch)
        removeNode2(root, root->base);
}
// cau 4
void findMax(Node* root, int& time)
{
    if (root == NULL)
        return;
    time = max(time, root->base.hours * 60 + root->base.mins);
    findMax(root->left, time);
    findMax(root->right, time);
}
int Height(Node* root)
{
    if (root == NULL)
        return 0;
    int left = Height(root->left);
    int right = Height(root->right);
    if (left > right)
        return left + root->base.bus + root->base.eco;
    else
        return right + root->base.bus + root->base.eco;
}
void ex4(Node* root)
{
    cout << Height(root);
}
void todo(string flightdata_filename, string data_filename)
{
    string level_list; char ch;
    readData(data_filename, level_list, ch);
    Node* root = readFlightdata(flightdata_filename);
    //print_preorder(root);
    //LevelOrder2(root, level_list);
    cout << "==========\n";
    isRemove(root, ch);
    //LevelOrder(root, level_list);
    cout << "==========\n";
    ex4(root);
    del_tree(root);
}
int main()
{
    todo("g1.v2.jl", "data.txt");
}