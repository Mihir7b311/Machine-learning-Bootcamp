/*avl*/


#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
node* root=NULL;

bool searchKey(node* temp, int key) {
    if (temp == NULL)
        return false;
    else {
        if (key == temp->data)
            return true;
        else if (key < temp->data)
            return searchKey(temp->left, key);
        else
            return searchKey(temp->right, key);
    }
}


node *RightRotate(node * temp){
    node *x=temp->left;
    node *temp1=x->right;

    x->right=temp;
    temp->left=temp1;

    return x;
}

node *LeftRotate(node * temp){
    node *y=temp->right;
    node *temp1=y->left;

    y->left=temp;
    temp->right=temp1;

    return y;
}

int height(node *r){
    if(r==NULL)
        return 0;
    else{
        int leftheight=height(r->left);
        int rightheight=height(r->right);

        if(leftheight>rightheight)
            return (leftheight+1);
        else
            return (rightheight+1);
    }
}

int BalanceFactor(node* n){
    if(n==NULL)
        return -1;
    else
        return height(n->left)-height(n->right);
}

node *Insert_into_Tree(node *temp,node *new_node){
    if(temp==NULL){
        temp=new_node;
        return temp;
    }

    if(new_node->data < temp->data){
        temp->left=Insert_into_Tree(temp->left,new_node);
    }
    else if(new_node->data > temp->data){
        temp->right=Insert_into_Tree(temp->right,new_node);
    }
    else{
        cout<<"NO DUPLICATE VALUES ARE ALLOWED!"<<endl;
        return temp;
    }

    int bf=BalanceFactor(temp);

    // Left Left

    if(bf>1 && new_node->data < temp->left->data)
        return RightRotate(temp);

    // Right Right

    if(bf<-1 && new_node->data > temp->right->data)
        return LeftRotate(temp);

    // Left Right

    if(bf>1 && new_node->data > temp->left->data){
        temp->left=LeftRotate(temp->left);
        return RightRotate(temp);
    }

    // Right Left

    if(bf<-1 && new_node->data < temp->right->data){
        temp->right = RightRotate(temp->right);
        return LeftRotate(temp);
    }
    return temp;

}

node *SearchNode(int x){
    if(root==NULL){
        return root;
    }
    else{
        node *temp=root;
        while(temp!=NULL){
            if(x==temp->data){
                return temp;
            }
            else if(x<temp->data){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        return NULL;
    }
}

void PreorderTraversal(node* temp){
    if(temp==NULL)
        return;
    cout<<temp->data<<" ";
    PreorderTraversal(temp->left);
    PreorderTraversal(temp->right);
}

void InorderTraversal(node * temp){
    if(temp==NULL)
        return;
    InorderTraversal(temp->left);
    cout<<temp->data<<" ";
    InorderTraversal(temp->right);
}

void PostorderTraversal(node *temp){
    if (temp==NULL)
        return;
    PostorderTraversal(temp->left);
    PostorderTraversal(temp->right);
    cout<<temp->data<<" ";
}

node *minValueNode(node *x){
    node *current=x;

    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

node *delete_from_Tree(node *temp,int v){
    if(temp==NULL){
        return NULL;
    }
    else if(v<temp->data){
        temp->left=delete_from_Tree(temp->left,v);
    }
    else if(v>temp->data){
        temp->right=delete_from_Tree(temp->right,v);
    }
    else{
        if(temp->left==NULL){
            node *temp1=temp->right;
            delete temp;
            return temp1;
        }
        else if(temp->right==NULL){
            node *temp1=temp->left;
            delete temp;
            return temp1;
        }
        else{
            node *temp1=minValueNode(temp->right);
            temp->data=temp1->data;
            temp->right=delete_from_Tree(temp->right,temp1->data);
        }
    }

    int bf=BalanceFactor(temp);

    // Left Left

    if(bf==2 && BalanceFactor(temp->left)>=0)
        return RightRotate(temp);

    // Left Right

    else if(bf==2 && BalanceFactor(temp->left)==-1){
        temp->left=LeftRotate(temp->left);
        return RightRotate(temp);
    }

    // Right Right

    else if(bf==-2 && BalanceFactor(temp->right)<=-0)
        return LeftRotate(temp);

    // Right Left

    else if(bf==-2 && BalanceFactor(temp->right)==1){
        temp->right=RightRotate(temp->right);
        return LeftRotate(temp);
    }

    return temp;
}

int32_t main(){
    int n,x;
    cout<<"Enter the number of Nodes to be inserted: ";
    cin>>n;
    cout<<'\n';
    if(n>0){
        cout<<"Enter the node-values: ";
        for(int i=0;i<n;i++){
            cin>>x;
            node* temp=new node();
            temp->left=NULL;
            temp->right=NULL;
            temp->data=x;
            root=Insert_into_Tree(root,temp);
        }
        cout<<'\n';
        cout<<"Pre-Order traversal: ";
        PreorderTraversal(root);
        cout<<'\n';
        cout<<"Post-Order traversal: ";
        PostorderTraversal(root);
        cout<<'\n';
        cout<<"In-Order traversal: ";
        InorderTraversal(root);
        cout<<'\n';
        cout<<'\n';
    }
    cout<<"Enter the number of nodes to be deleted: ";
    cin>>n;
    if(n>0){
        cout<<"Enter the node-values to be deleted: ";
        for(int i=0;i<n;i++){
            cin>>x;
            root=delete_from_Tree(root,x);
        }
        cout<<'\n';
        cout<<"Pre-Order Traversal: ";
        PreorderTraversal(root);
        cout<<'\n';
        cout<<"Post-Order Traversal: ";
        PostorderTraversal(root);
        cout<<'\n';
        cout<<"In-Order Traversal: ";
        InorderTraversal(root);
        cout<<'\n';
        cout<<'\n';
    }
    
    cout << "Enter the key to search: ";
    cin >> x;
    if (searchKey(root, x)) {
        cout << "Key " << x << " is present in the tree." << endl;
    } else {
        cout << "Key " << x << " is not present in the tree." << endl;
    }

    return 0;
}









/*btree*/









#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MAX 4
#define MIN 2

struct btreeNode {
    int val[MAX + 1], count;
    btreeNode *link[MAX + 1];
};

btreeNode *root;

/* creating new node */
btreeNode * createNode(int val, btreeNode *child) {
    btreeNode *newNode = new btreeNode;
    newNode->val[1] = val;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}

/* Places the value in appropriate position */
void addValToNode(int val, int pos, btreeNode *node, btreeNode *child) {
    int j = node->count;
    while (j > pos) {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->val[j + 1] = val;
    node->link[j + 1] = child;
    node->count++;
}

/* split the node */
void splitNode(int val, int *pval, int pos, btreeNode *node,btreeNode *child, btreeNode **newNode) {
    int median,j;

    if (pos>MIN)
        median=MIN + 1;
    else
        median = MIN;

    *newNode=new btreeNode;
    j=median+1;
    while(j<=MAX){
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN) {
        addValToNode(val, pos, node, child);
    }
    else {
        addValToNode(val, pos - median, *newNode, child);
    }
    *pval = node->val[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}

/* sets the value val in the node */
int setValueInNode(int val, int *pval,btreeNode *node, btreeNode **child) {

    int pos;
    if(!node){
        *pval = val;
        *child = NULL;
        return 1;
    }

    if(val<node->val[1]){
        pos = 0;
    }
    else{
        for (pos = node->count;
            (val < node->val[pos] && pos > 1); pos--);
        if (val == node->val[pos]) {
            cout<<"Duplicates not allowed\n";
            return 0;
        }
    }
    if (setValueInNode(val, pval, node->link[pos], child)) {
        if (node->count < MAX) {
            addValToNode(*pval, pos, node, *child);
        }
        else {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

/* insert val in B-Tree */
void insert_into_Btree(int val) {
    int flag,i;
    btreeNode *child;

    flag=setValueInNode(val, &i, root, &child);
    if (flag)
        root=createNode(i, child);
}

/* copy successor for the value to be deleted */
void copySuccessor(btreeNode *temp,int pos) {
    btreeNode *temp1;
    temp1=temp->link[pos];

    for (;temp1->link[0]!= NULL;)
        temp1=temp1->link[0];
    temp->val[pos]=temp1->val[1];

}

/* removes the value from the given node and rearrange values */
void removeVal(btreeNode *temp, int pos) {
    int i=pos+1;
    while(i<=temp->count){
        temp->val[i - 1]=temp->val[i];
        temp->link[i - 1]=temp->link[i];
        i++;
    }
    temp->count--;
}

/* shifts value from parent to right child */
void doRightShift(btreeNode *temp,int pos) {
    btreeNode *x=temp->link[pos];
    int j=x->count;

    while(j>0){
        x->val[j+1]=x->val[j];
        x->link[j+1]=x->link[j];
    }
    x->val[1]=temp->val[pos];
    x->link[1]=x->link[0];
    x->count++;

    x = temp->link[pos - 1];
    temp->val[pos]=x->val[x->count];
    temp->link[pos]=x->link[x->count];
    x->count--;
    return;
}

/* shifts value from parent to left child */
void doLeftShift(btreeNode *temp,int pos) {
    int j=1;
    btreeNode *x=temp->link[pos - 1];

    x->count++;
    x->val[x->count]=temp->val[pos];
    x->link[x->count]=temp->link[pos]->link[0];

    x=temp->link[pos];
    temp->val[pos]=x->val[1];
    x->link[0]=x->link[1];
    x->count--;

    while(j<=x->count) {
        x->val[j]=x->val[j + 1];
        x->link[j]=x->link[j + 1];
        j++;
    }
    return;
}

/* merge nodes */
void mergeNodes(btreeNode *temp,int pos) {
    int j = 1;
    btreeNode *x1=temp->link[pos],*x2=temp->link[pos - 1];

    x2->count++;
    x2->val[x2->count]=temp->val[pos];
    x2->link[x2->count]=temp->link[0];

    while(j<=x1->count){
        x2->count++;
        x2->val[x2->count] = x1->val[j];
        x2->link[x2->count] = x1->link[j];
        j++;
    }
    j = pos;
    while(j<temp->count){
        temp->val[j]=temp->val[j + 1];
        temp->link[j]=temp->link[j + 1];
        j++;
    }
    temp->count--;
    free(x1);
}

/* adjusts the given node */
void adjustNode(btreeNode *temp, int pos) {
    if(!pos){
        if(temp->link[1]->count > MIN) {
            doLeftShift(temp,1);
        }
        else{
            mergeNodes(temp,1);
        }
    }
    else{
        if(temp->count!=pos) {
            if(temp->link[pos - 1]->count > MIN){
                doRightShift(temp,pos);
            }
            else{
                 if(temp->link[pos + 1]->count > MIN) {
                    doLeftShift(temp,pos + 1);
                }
                else{
                    mergeNodes(temp,pos);
                }
            }
        }
        else{
            if(temp->link[pos - 1]->count > MIN)
                doRightShift(temp,pos);
            else
                mergeNodes(temp,pos);
        }
    }
}

/* delete val from the node */
int delValFromNode(int val,btreeNode *temp){
    int pos,flag = 0;
    if (temp){
        if(val < temp->val[1]){
            pos=0;
            flag=0;
        }
        else{
            for(pos=temp->count;(val < temp->val[pos] && pos > 1);pos--);
            if (val==temp->val[pos]){
                flag=1;
            }
            else{
                flag=0;
            }
        }
        if(flag){
            if(temp->link[pos - 1]) {
                copySuccessor(temp,pos);
                flag=delValFromNode(temp->val[pos],temp->link[pos]);
                if(flag==0){
                    cout<<"Given data is not present in B-Tree\n";
                }
            }
            else{
                removeVal(temp,pos);
            }
        }
        else{
            flag=delValFromNode(val,temp->link[pos]);
        }
        if(temp->link[pos]) {
            if(temp->link[pos]->count < MIN)
                adjustNode(temp,pos);
        }
    }
    return flag;
}

/* delete val from B-tree */
void DELETION(int val,btreeNode *temp) {
    btreeNode *tmp;
    if (!delValFromNode(val,temp)) {
        cout<<"Given value is not present in B-Tree\n";
        return;
    }
    else{
        if(temp->count==0) {
            tmp=temp;
            temp=temp->link[0];
            free(tmp);
        }
    }
    root=temp;
    return;
}

/* search val in B-Tree */
void SEARCHING(int val, int *pos,btreeNode *temp) {
    if (!temp) {
        return;
    }

    if (val<temp->val[1]) {
        *pos=0;
    }
    else{
        for(*pos=temp->count;(val<temp->val[*pos] && *pos>1);(*pos)--);
        if(val==temp->val[*pos]){
            cout<<"Given data is Found\n";
            return;
        }
    }
    SEARCHING(val,pos,temp->link[*pos]);
    return;
}

/* B-Tree Traversal */
void TRAVERSAL(btreeNode*temp) {
    int i;
    if(temp!=NULL){
        for(i=0;i<temp->count;i++) {
            TRAVERSAL(temp->link[i]);
            cout<<temp->val[i + 1]<<' ';
        }
        TRAVERSAL(temp->link[i]);
    }
}

int32_t main(){
  int x,c;
  cout<<"ENTER ORDER: ";
  cin>>x;
  int n;
  cout<<"Enter the number of keys: ";
  cin>>n;
  cout<<"ENTER THE KEY-VALUES: ";
  for(int i=0;i<n;i++){
      cin>>x;
      insert_into_Btree(x);
  }
  cout<<"Traversal: ";
  TRAVERSAL(root);

    return 0;
}







/*bst */






#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node* left, *right;
};

Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->key);
        }
        inorder(root->right);
    }
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

Node* deleteNode(Node* root, int k) {
    if (root == NULL)
        return root;
    if (root->key > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else {
        Node* succParent = root;
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->key = succ->key;
        delete succ;
        return root;
    }
}

// Function to search for a key in the tree
bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->key == key)
        return true;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int n;
    cout << "Enter the number of nodes to be inserted\n";
    cin >> n;
    cout << "Enter the values of nodes \n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    printf("Leaf nodes from left to right are: ");
    inorder(root);
    cout << endl;

    int del;
    printf("Enter the value of the node which needs to be deleted:");
    cin >> del;

    // Search for the key before deleting
    if (search(root, del))
        cout << "Node with key " << del << " is present in the tree.\n";
    else
        cout << "Node with key " << del << " is not present in the tree.\n";

    root = deleteNode(root, del);

    printf("Leaf nodes from left to right are: ");
    inorder(root);

    return 0;
}






/*max heap*/



#include <bits/stdc++.h>
using namespace std;
const int n=1000;
int arr[n];
int p=0;
void swapnum(int *x,int *y){
    int b;
    b=*x;
    *x=*y;
    *y=b;
}
int maxnum(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
void Heapify(int arr[],int p,int i){
    if(2*i+1==p-1){
        int l=maxnum(arr[i],arr[2*i+1]);
        if(l==arr[2*i+1]){
            swapnum(&arr[i],&arr[2*i+1]);
            Heapify(arr,p,2*i+1);
        }
    }
    else if(2*i+1<p-1){
        int l=maxnum(arr[i],maxnum(arr[2*i+1],arr[2*i+2]));
        if(l==arr[2*i+1]){
            swapnum(&arr[i],&arr[2*i+1]);
            Heapify(arr,p,2*i+1);
        }
        else if(l==arr[2*i+2]){
            swapnum(&arr[i],&arr[2*i+2]);
            Heapify(arr,p,2*i+2);
        }
    }
}
void Maxheap(int arr[],int p){
    for(int i=floor(p/2);i>=0;i--){
        Heapify(arr,p,i);
    }
}
int Delete(int arr[],int p){
    if(p<0){
        cout<<"Tree is empty"<<'\n';
        return 0;
    }
    else{
        int a=arr[0];
        swapnum(&arr[0],&arr[p-1]);
        p--;
        Maxheap(arr,p);
        return a;
    }
}
int INSERT(int a[],int p,int data){
    if(p>n){
        cout<<"TREE IS FULL"<<endl;
    }
    else{
        p++;
        arr[p-1]=data;
        Maxheap(arr,p);
    }
    return p;
}
void DISPLAY(int arr[],int p){
    for(int i=0;i<p;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    char c;
    cout<<"Do u want to add a number?(Y/N):";
    cin>>c;
    while(1){
        if(c=='Y'){
            cout<<"Enter your data"<<'\n';
            cin>>arr[p];
            p++;
        }
        else if(c=='N'){
            break;
        }
        else{
            cout<<"invalid choice"<<'\n';
        }
        cout<<"Do u want to add a number?(Y/N):";
        cin>>c;
    }
    int k;
    cout<<"Enter your value k:"<<'\n';
    cin>>k;
    Maxheap(arr,p);
    for(int i=1;i<=k;i++){
        cout<<Delete(arr,p)<<" ";
        p--;
        Maxheap(arr,p);
    }
    cout<<'\n';
    cout<<"do u want to insert a number into the maxheap(Y/N):";
    char ch;
    cin>>ch;
    while(ch=='Y'){
        cout<<"the number u want to insert:";
        int x;
        cin>>x;
        INSERT(arr,p,x);
        p++;
        DISPLAY(arr,p);
        cout<<"do u want to insert a number into the maxheap(Y/N):";
        cin>>ch;

    }

    return 0;
}


