#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

bool recursive_search(Node *root, int x){
    if(root==NULL)
        return false;
    if(root->key==x)
        return true;
    else if(root->key>x){
        return recursive_search(root->left,x);
    }else{
        return recursive_search(root->right,x);
    }
} 
bool iterative_search(Node *root, int x){
    while(root!=NULL){
        if(root->key==x)
            return true;
        else if(root->key<x)
            root=root->right;
        else
            root=root->left;
    }
    return false;
} 

int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=16;
	
	if(recursive_search(root,x))
	    cout<<"Found";
	else
	    cout<<"Not Found";
	if(iterative_search(root,x))
	    cout<<"Found";
	else
	    cout<<"Not Found";
}