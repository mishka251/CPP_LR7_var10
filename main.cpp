#include <iostream>

class TreeNode{
    TreeNode* left, *right;
    int value;
public:
    TreeNode(int value){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~TreeNode(){
        if(this->right!= nullptr){
            delete this->right;
        }
        if(this->left!= nullptr){
            delete this->left;
        }
    }

    void print(int level=0){
        if(this->right){
            this->right->print(level+1);
        }
        for(int i=0; i<level; i++){
            std::cout<<"  ";
        }
        std::cout<<this->value<<std::endl;
        if(this->left){
            this->left->print(level+1);
        }
    }

    void insert(int value){
        if(value > this->value){
            if(this->right == nullptr){
                this->right = new TreeNode(value);
            }else{
                this->right->insert(value);
            }
        }else{
            if(this->left == nullptr){
                this->left = new TreeNode(value);
            }else{
                this->left->insert(value);
            }
        }
    }

    int getElementsCount(){
        int count = 1;
        if(this->left!= nullptr){
            count += this->left->getElementsCount();
        }
        if(this->right!= nullptr){
            count += this->right->getElementsCount();
        }
        return count;
    }

    int leftCount(){
        if(this->left == nullptr){
            return 0;
        }
        return this->left->getElementsCount();
    }

    int rightCount(){
        if(this->right == nullptr){
            return 0;
        }
        return this->right->getElementsCount();
    }

    void printElementsWithDifferentHeight(){
        if(this->leftCount() != this-> rightCount()){
            std::cout<<this->value<<std::endl;
        }
        if(this->right!= nullptr){
            this->right->printElementsWithDifferentHeight();
        }

        if(this->left!= nullptr){
            this->left->printElementsWithDifferentHeight();
        }
    }
};

int main() {
    int n;
    std::cout<<"Elements count"<<std::endl;
    std::cin>>n;
    if(n<=0){
        std::cout<<"Incorrect value"<<std::endl;
        return 0;
    }
    int a;
    std::cout<<"a[0]="<<std::endl;
    std::cin>>a;
    TreeNode* root = new TreeNode(a);
    for(int i =1; i<n; i++){
        std::cout<<"a["<<i<<"]="<<std::endl;
        std::cin>>a;
        root->insert(a);
    }

    std::cout<<"Tree"<<std::endl;
    root->print();

    std::cout<<"Elements with different elements count"<<std::endl;
    root->printElementsWithDifferentHeight();
    std::cout<<std::endl;

    return 0;
}
