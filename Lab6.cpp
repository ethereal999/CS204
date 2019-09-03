#include <iostream>
#include <bits/stdc++.h>


using namespace std;


struct Node
{
    int key;
    int amount;
    Node *left;
    Node *right;
    int height;


};
int max(int a, int b);


int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}


int max(int a, int b)
{
    return (a > b)? a : b;
}

Node* newNode(int key,int am)
{
    Node* node = new Node();
    node->key = key;
    node->amount = am;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return(node);
}

struct Node* search_key(struct Node* root, int key)
{

    if (root == NULL || root->key == key)
       return root;


    if (root->key < key)
       return search_key(root->right, key);


    return search_key(root->left, key);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    return x;
}


Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;


    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}


int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert_node(Node* node, int key, int am)
{

    if (node == NULL)
        return(newNode(key,am));

    if (key < node->key)
        node->left = insert_node(node->left, key,am);
    else if (key > node->key)
        node->right = insert_node(node->right, key,am);
    else
        return node;


    node->height = 1 + max(height(node->left),
                        height(node->right));


    int balance = getBalance(node);


    if (balance > 1 && key < node->left->key)
        return rightRotate(node);


    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}



int main()
{
    struct Node* root=NULL;
    int n,q;
    cin>>n>>q;
    vector<int> output;
    int maxx[2]={-1,-1};
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op==1){
                int id,am;
                cin>>id>>am;
        struct Node* it = search_key(root,id);
        if(root == NULL){
             root = insert_node(root,id,am);
             if(am> maxx[1]){

                maxx[1]=am;
                maxx[0]=id;
            }
        }
        else{
        if(it == NULL){
             insert_node(root,id,am);
            if(am > maxx[1]){

                maxx[1]=am;
                maxx[0]=id;
            }
        }
        else{
            it->amount = it->amount + am;
            if(it->amount > maxx[1]){
                maxx[1]=it->amount;
                maxx[0]=it->key;
            }
        }


        }
        }
        else {

            output.push_back(maxx[0]);


        }


    }
    for(int j=0;j<output.size();j++){

        if(output[j]==-1){
            cout<<"No Data Available"<<endl;
        }
        else{
            cout<<output[j]<<endl;
        }
    }

}
