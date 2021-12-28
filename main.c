#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

typedef struct Node{
    struct Node* right;
    struct Node* left;
    int data;
};

typedef struct BTree{
    struct Node root;
};


int* copyArr(int toBCopied[], int s){
    int newArray[s];
    for (int i = 0; i < s; ++i) {
        newArray[i] = toBCopied[i];
    }
    return newArray;
}

struct Node* newNode(struct Node *parent,char dir){
    if (dir == 'l'){
        parent->left = (struct Node*)malloc(sizeof(struct Node));
        return parent->left;
    } else {
        parent->right = (struct Node *) malloc(sizeof(struct Node));
        return parent->right;
    }
}


struct Node recBin(int inArr[]){
    int size = sizeof(inArr)/sizeof(int);
    int left[size/2];
    int right[size/2];
    struct Node subBinTree = {left,right,inArr[size]};
    for (int i = 0; i < size; ++i) {
        if (i < size/2){
            left[i] = inArr[i];
        }
        if (i > size/2){
            right[i] = inArr[i];
        }
    }
    return subBinTree;
}

struct BTree binSort(int srtdArr[]){
    int mid = SIZE/2;
    struct Node root = {malloc(sizeof(int)*mid), malloc(sizeof(int)*mid),srtdArr[mid]};
    //allocate right and left with memory so while loop runs
    struct Node* nodeCrsr = &root;
    struct BTree theBinTree = {root};
    while (sizeof(nodeCrsr->left) > sizeof(int)*2 && sizeof(nodeCrsr->right) > sizeof(int)*2){
        *nodeCrsr = recBin(srtdArr);
    }

    return theBinTree;
}

int main() {

    int inArr_A4[] = {0,1,2,3,4,5,6,7,8,9};// the sorted array
    struct BTree binTree = binSort(inArr_A4);


    return 0;
}




