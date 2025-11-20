#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int equalPathDepth(Node * root);

bool equalPaths(Node * root)
{
    // Add your code below
    
    int depth = equalPathDepth(root);
    return depth != -1;

}

int equalPathDepth(Node * root){
    int Ldepth = 0;
    int Rdepth = 0;
    if (root == nullptr){
        return 0;
    }
    if (root->left==nullptr && root->right == nullptr){
        return 1;
    }
    else {
        if (root->left != nullptr){
            Ldepth = equalPathDepth(root->left);
        }
        if (root->right != nullptr){
            Rdepth = equalPathDepth(root->right);
        }
    }
    if (Ldepth == -1 || Rdepth == -1){
        return -1;
    }
    if (root->left==nullptr){
        return Rdepth +1;
    }
    if (root->right== nullptr){
        return Ldepth+1; 
    }

    if (Ldepth != Rdepth){
        return -1;
    } //else {return 1;}

    return Ldepth +1;

}

