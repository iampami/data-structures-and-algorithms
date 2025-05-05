#include <iostream>
using namespace std;

class tagNode{
    friend class BinarySearchTree;
private:
    long Data;
    tagNode* Left;
    tagNode* Right;

public:
    //ham tao voi gia tri mac dinh
    tagNode(long d = 0){
        Left = Right = NULL;
        Data = d;
    }
};
typedef tagNode* BSTree;
class BinarySearchTree{
    friend class tagNode;
    
public:
    
    BSTree Root;
    //khoi tao cay nhi phan
    BinarySearchTree(){
        Root=NULL;
    }

    void NLR(BSTree T){
        if(T){
            std::cout<<"Tham goc"<<T->Data<<" "<<endl;
            NLR(T->Left);
            NLR(T->Right);
        }
    }

    void LRN(BSTree T){
        if(T){
            
            LRN(T->Left);
            LRN(T->Right);
            cout<<"Tham goc"<<T->Data<<" "<<endl;
        }
    }

    void LNR(BSTree T){
        if(T){
            
            LNR(T->Left);
            cout<<"Tham goc "<<T->Data<<" "<<endl;
            LNR(T->Right);
        }
    }

    //ham de quy xoa toan bo cay
    void destroyTree(BSTree T){
        if(T){
            destroyTree(T->Left);
            destroyTree(T->Right);
            delete T;
        }
    }

    //Kiểm tra 01 node có phải là node lá không ?
    bool isLeaf(BSTree T){
        return (T && T->Left==NULL && T->Right==NULL);
    }

    //them 1 phan tu 
    int InsertNode(BSTree &T, long x){
        if(!T) {
            T = new tagNode(x);
        }

        if(T->Data==x) return 0;

        if(x<T->Data){
            return InsertNode(T->Left, x);
        } else {
            return InsertNode(T->Right,x);
        }

        

        return 1;
    }

    void SearchStandFor(BSTree &p, BSTree &q){
        if(q->Left){ //neu con cay con ben trai, tiep tuc tim
            return SearchStandFor(p, q->Left);
        } else {
            p->Data = q->Data; // gan gia tri nut nho nhat q vao nut can xoa p
            p = q; //p->q can xoa
            q = q->Right;//cap nhat cay, bo q
        }
    }

    int deleteNode(BSTree &T, long x){
        if(!T) return 0;
        
        if(T->Data>x){
            return deleteNode(T->Left, x);
        } 
        if(T->Data<x) {
            return deleteNode(T->Right,x);
        } else {
            //neu tim thay nut can xoa
            tagNode *p = T;
            if(!T->Left) T = T->Right;//neu khong co con trai
            else {
                if(!T->Right) T = T->Left;//neu khong co con phai
                else SearchStandFor(p, T->Right);//neu co ca 2 con, tim con nho nhat ben phai de thay the
            }
            delete p;
            return 1;
        }
    }

    int countLeaf(BSTree T){
        if(!T) return 0; //cay rong thi dem 0
        if(!T->Left && !T->Right) return 1; //neu la thi dem 1
        return countLeaf(T->Left) + countLeaf(T->Right);
    }
};

int main(){
    BinarySearchTree tree;
    tree.InsertNode(tree.Root, 10);
    tree.InsertNode(tree.Root, 5);
    tree.InsertNode(tree.Root, 3);
    tree.InsertNode(tree.Root, 15);
    tree.InsertNode(tree.Root, 13);
    tree.InsertNode(tree.Root, 12);

    cout<<"Duyet LRN: "<<endl;
    tree.LRN(tree.Root);
    cout<<endl;

    cout<<"Dem la: "<<tree.countLeaf(tree.Root);

    // cout<<"Duyet LNR: "<<endl;
    // tree.LNR(tree.Root);
    // cout<<endl;

    // tree.deleteNode(tree.Root, 13);
    // cout<<"Duyet NLR sau khi xoa 13: "<<endl;
    // tree.NLR(tree.Root);
    return 0;
}