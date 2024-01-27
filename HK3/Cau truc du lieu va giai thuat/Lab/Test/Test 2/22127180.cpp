#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

struct Player
{
    string name;
    int day, month, year;
    int height_cm;
    int weight_kg;
    string nationality;
    string club_name;
};
struct Node
{
    Player base;
    Node* left;
    Node* right;
};
void insertNode(Node*& root, Node* newNode)
{
    if (root == NULL)
        root = newNode;
    else if (root->base.name > newNode->base.name)
        insertNode(root->left, newNode);
    else
        insertNode(root->right, newNode);
}
Node* createPlayerTree(string filename)
{
    ifstream infile(filename.c_str());
    string line; Node* root = NULL;
    getline(infile, line, '\n');
    while (getline(infile, line, '\n'))
    {
        Player a;
        stringstream ss(line);
        getline(ss, a.name, ',');
        ss >> a.day; ss.ignore();
        ss >> a.month; ss.ignore();
        ss >> a.year; ss.ignore();
        ss >> a.height_cm; ss.ignore();
        if (a.height_cm < 175)
            continue;
        ss >> a.weight_kg; ss.ignore();
        getline(ss, a.nationality, ',');
        getline(ss, a.club_name, '\n');
        Node* newNode = new Node{a, NULL, NULL};
        insertNode(root, newNode);
    }
    infile.close();
    return root;
}

int levelNode(Node* root, Node* node)
{
    if (root == node)
        return 0;

    int level = 0;
    Node* cur = root;
    while (cur != node)
    {
        if (cur->base.name > node->base.name)
            cur = cur->left;
        else
            cur = cur->right;
        level++;
    }
    return level;
}
void PlayerTreeTraversal(Node* pRoot)
{
    if (pRoot == NULL)
        return;
    queue <Node*> q;
    q.push(pRoot);
    while (!q.empty())
    {
        Node* cur = q.front();
        cout << levelNode(pRoot, cur) << " - " << cur->base.name << '\n';
        if (cur->left != NULL) q.push(cur->left);
        if (cur->right != NULL) q.push(cur->right);
        q.pop();
    }
}

void removeNode(Node*& root, Player a)
{
    if (root == NULL)
        return;
    else if (root->base.name > a.name)
        removeNode(root->left, a);
    else if (root->base.name < a.name)
        removeNode(root->right, a);
    else{
        if (root->left == NULL){
            Node* del = root;
            root = root->right;
            delete del;
        }
        else if (root->right == NULL){
            Node* del = root;
            root = root->left;
            delete del;
        }
        else{
            Node* cur = root->right;
            while (cur->left != NULL)
                cur = cur->left;
            root->base = cur->base;
            removeNode(root->right, cur->base);
        }
    }
}
void removePlayer(Node* &root, char C)
{
    if (root == NULL)
        return;
    removePlayer(root->left, C);
    removePlayer(root->right, C);
    if (root->base.name[0] == C)
        removeNode(root, root->base);
}
void removePlayers(Node* &pRoot, vector <char> C)
{
    for (int i = 0; i < C.size(); i++){
        removePlayer(pRoot, C[i]);
    }
}

void findPlayers(Node* pRoot)
{
    if (pRoot == NULL)
        return;
    findPlayers(pRoot->left);
    if (pRoot->left != NULL && pRoot->right != NULL)
    {
        if (pRoot->base.year < pRoot->left->base.year && pRoot->base.year < pRoot->right->base.year)
        {
            cout << pRoot->base.name << '\n';
        }
        else if (pRoot->base.year == pRoot->left->base.year && pRoot->base.year == pRoot->right->base.year)
        {
            if (pRoot->base.month < pRoot->left->base.month && pRoot->base.month < pRoot->right->base.month)
                cout << pRoot->base.name << '\n';
            else if (pRoot->base.month == pRoot->left->base.month && pRoot->base.month == pRoot->right->base.month)
            {
                if (pRoot->base.day < pRoot->left->base.day && pRoot->base.day < pRoot->right->base.day)
                    cout << pRoot->base.name << '\n';
            }
        }
    }
    findPlayers(pRoot->right);
}
int main()
{
    Node* root = createPlayerTree("Players.csv");
    //PlayerTreeTraversal(root);

    vector <char> c;
    c.push_back('A');c.push_back('C');
    //removePlayers(root, c);
    //PlayerTreeTraversal(root);
    findPlayers(root);
    return 0;
}
