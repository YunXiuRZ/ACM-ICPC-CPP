#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>

using namespace std;

ofstream fout("result.txt");
#define out cout

struct Node{
    char name;
    Node *right;
    Node *left;

    Node(char c):name(c){}
};

string preord, inord;
vector<Node> nodes;
int n = 0;

Node* recover_tree(char *root_letter, char *inord_begin, int length);
void print_tree(Node *root);

int main(){
    while(cin>>preord>>inord){
        Node *root = recover_tree(&preord[0], &inord[0], preord.length());
        print_tree(root);
    }
}

Node* recover_tree(char *root_letter, char *inord_begin, int length){
    Node n = Node(*root_letter);
    nodes.push_back(n);
    Node *root = &nodes[nodes.size()-1];
    if(length == 1){
        return root;
    }
    char *p = strchr(inord_begin, *root_letter);
    int lLength = p - inord_begin;
    int rLength = length - lLength - 1;
    root->left = recover_tree(root_letter+1, inord_begin, lLength);
    root->right = recover_tree(root_letter+lLength+1, p+1, rLength);
    return root;
}

void print_tree(Node *root){
    if(root == nullptr){
        return;
    }
    print_tree(root->left);
    print_tree(root->right);
    out<<root->name;
}
