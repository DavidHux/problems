/*完成下述代码中注释的部分，使程序能读取物品讯息，检查合法性，并在合法时输出总重。*/

/*注意：
1. 不能修改其他部分。
2. 不能有内存泄漏。*/

#include <iostream>
#include <vector>

class Item {
public:
    /* 编写构造函数、析构函数 */
    Item(int w):weight_(w){

    }

    virtual void addw(int w){
        weight_+=w;
    }

    virtual int GetWeight() const {
        return weight_;
    }

    virtual bool IsValid() const {
        return true;
    }

private:
   int weight_;
};

class Bag : public Item {
public:
   /* 编写构造函数、析构函数及其他函数 */
    Bag(int w, int mw):Item(w), maxWeight_(mw){
        valid = true;
    }
    bool insertbag(Bag* b, int k){
        return insert(b, k, 1);
    }

    bool insert(Item* it, int k, int bag){
        // std::cout<<it->GetWeight()<<' '<<k<<' '<<bag<<std::endl;
        if(k<0){
            valid = false;
            return false;
        }
        if(!valid)
            return false;
        if(k == 0){
            this->addw(it->GetWeight());
            valid = this->GetWeight() <= maxWeight_;
            if(bag)
                items_.push_back(it);
            return valid;
        } else{
            if(items_.size() == 0){
                valid = false;
                return valid;
            } else{
                this->addw(it->GetWeight());
                valid = this->GetWeight() <= maxWeight_;
                if(!valid)
                    return false;
                valid = ((Bag*)items_.back())->insert(it, k-1, bag);
                return valid;
            }
        }
    }

    bool IsValid() const {
        return valid;
    }
    bool valid;
private:
    std::vector<Item*> items_;
    int maxWeight_;
};

Bag* Parse() {
    /* 编写读入数据的代码 */
    int n;
    std::cin>>n;
    int t,k,w,mw;
    std::cin>>t>>k>>w>>mw;
    Bag* root = new Bag(w, mw);
    while(std::cin>>t){
        if(t == 1){
            std::cin>>k>>w>>mw;
            Bag* temp = new Bag(w, mw);
            root->insertbag(temp, k-1);
        } else{
            std::cin>>k>>w;
            Item* it = new Item(w);
            root->insert(it, k-1,0);
        }
    }
    return root;
}

int main() {
    Bag* root = Parse();

    if (root->IsValid())
        std::cout << root->GetWeight() << std::endl;
    else
        std::cout << "invalid";

    delete root;
}