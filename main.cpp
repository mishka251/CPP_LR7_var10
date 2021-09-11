#include <iostream>

class TreeNode{  // класс для вершины дерева
    TreeNode* left, *right; // указатели на правое и левое поддерево
    int value; // значение этой вершины
public: // начало публичных методов класса
    TreeNode(int value){ // конструктор вершины дерева
        this->value = value; // записываем вершине дерева её значение
        this->left = nullptr; // при создании вершины дерева л и п поддерева нет
        this->right = nullptr;
    }

    ~TreeNode(){ // деструктор класса
        if(this->right!= nullptr){ // если мы удаляем вершину дерева, у которого есть правое поддерево
            delete this->right; // то удаляем и п поддерево
        }
        if(this->left!= nullptr){
            delete this->left;
        }
    }

    void print(int level=0){ // вывод дерева на экран
        if(this->right){ // если у дерева есть п поддерево,то сперва выводим правое
            this->right->print(level+1); // на один уровень дальше от корня
        }
        for(int i=0; i<level; i++){ // выводим кол-во пробелов равное расстоянию от корня дерева до текущей вершины
            std::cout<<"  ";
        }
        std::cout<<this->value<<std::endl;
        if(this->left){
            this->left->print(level+1);
        }
    }

    void insert(int value){ // добавление значений в дерево
        if(value > this->value){ // если значение больше, чем в текущей вершине
            if(this->right == nullptr){ // и если п  поддерева нет
                this->right = new TreeNode(value); // то мы его создаём с новым значением
            }else{
                this->right->insert(value); // иначе просто вставляем в п поддерево
            }
        }else{
            if(this->left == nullptr){
                this->left = new TreeNode(value);
            }else{
                this->left->insert(value);
            }
        }
    }

    int getElementsCount(){ // получение количества элементов в дереве
        int count = 1;
        if(this->left!= nullptr){ // если есть левое, добавляем количество значений в элементе
            count += this->left->getElementsCount();
        }
        if(this->right!= nullptr){
            count += this->right->getElementsCount();
        }
        return count;
    }

    int leftCount(){ // колво эл в левом дереве
        if(this->left == nullptr){ // если л нет, =0
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

    void printElementsWithDifferentHeight(){ //
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
    int n; // кол-во вершин в дереве
    std::cout<<"Elements count"<<std::endl;
    std::cin>>n;
    if(n<=0){
        std::cout<<"Incorrect value"<<std::endl;
        return 0;
    }
    int a; // переменная в которой будет значения для каждой вершины дерева
    std::cout<<"a[0]="<<std::endl;
    std::cin>>a;
    TreeNode* root = new TreeNode(a); // создаём корень дерева
    for(int i =1; i<n; i++){
        std::cout<<"a["<<i<<"]="<<std::endl; // создаём остальные вершины
        std::cin>>a;
        root->insert(a); //
    }

    std::cout<<"Tree"<<std::endl;
    root->print();

    std::cout<<"Elements with different elements count"<<std::endl;
    root->printElementsWithDifferentHeight();
    std::cout<<std::endl;

    return 0;
}
