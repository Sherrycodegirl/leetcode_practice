#include<iostream>
#include<string>

using namespace std;
class BST{
    int data;
    BST *left, *right;
public:
    BST();
    BST(int);
    BST* Insert(BST*, int);

    void Inorder(BST*);
    BST* deletenode(BST*, int);
    BST* searchnode(BST*, int);
    BST* minimum_val(BST*);

};
BST::BST()
{
    data = 0;
    left = NULL,
    right= NULL;

}

BST::BST(int value)
{
    data = value;
    left = NULL;
    right = NULL;
}

BST* BST::Insert(BST* root, int val){
    if (!root)
    {
        return new BST(val); // new operator returns a unique pointer
    }

    if (val > root->data){
        root->right = Insert(root->right,val);
    }
    else{
        root->left = Insert(root->left,val);
    }
    return root;

}
void BST::Inorder(BST* root){
    if (!root){
        return ;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);

}

BST* BST::minimum_val(BST* root){
    if(root->left == NULL){
        return root;
    }
    else{
        return minimum_val(root->left);
        }

}

BST* BST::searchnode(BST* root, int key){
    if (!root){
        cout << "not find " << key << endl;
        return root;
    }
    if (root->data > key){
        return searchnode(root->left, key); // search a node use return iteration.
    }
    else if (root->data < key){
        return searchnode(root->right, key);
    }
    else { cout << "key" << " = " << root->data<<endl;
        return root;
    }

}
BST* BST::deletenode(BST* root, int key)
{
    if (root == NULL){
        return root;
    }
    if (root->data > key){
        root->left = deletenode(root->left, key);
    }
    else if(root->data < key){
        root->right = deletenode(root->right,key); //edit a node use = iteration.
    } 
    else{ if(root->left ==NULL && root->right ==NULL){ // leaf node
        root = NULL;
    }
    else if (root->left == NULL){                   // has only a right child.
        root = root->right;
    }
    else if (root->right == NULL){                  //has only a left child.
        root = root->left;

    }
    else{
        BST* minimum_node = minimum_val(root->right); //if a node has 2 children, replace key of this node with the
                                                    // key of the minimum node on the right path. Delete the minimum node on the right.
        if (minimum_node){
            root->data = minimum_node->data;
            root->right = deletenode(root->right, minimum_node->data);
        }   

    }
 }
 return root; 
}

int main()
{
    BST b, *root,*s,*minimum, *t = NULL;
    root = b.Insert(root,50);
    root->Insert(root,30);
    root->Insert(root,20);
    root->Insert(root,40);
    root->Insert(root,70);
    root->Insert(root,60);
    root->Insert(root,80);
    /*root = b.Insert(root,50);
    root = root->Insert(root,30);
    root->Insert(root,20);*/
    cout << "root inorder \n" << endl;
    root->Inorder(root);
    //s= root->searchnode(root,30);
    //cout << "s inorder \n" << endl;
    //s->Inorder(s);
    //cout << "minimum node in root \n" << endl;
    //minimum = root->minimum_val(root);
    //minimum->Inorder(minimum);
    cout << "delete node \n" << endl;
    t = root->deletenode(root,80);
    t->Inorder(t);
    
    

return 0;
}


