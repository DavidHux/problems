#include <iostream>
#include <vector>

using namespace std;

// player struct
struct Player {
    int id;
    int score;
    Player(int id, int score) : id(id), score(score) {}
    Player() : id(0), score(0) {}
    Player(Player& p) {
        id = p.id;
        score = p.score;
    }
};

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int leftnum;
    Player p;
    Node() {
        parent = left = right = NULL;
        leftnum = 0;
        p = Player(0, 0);
    }
    Node(Node* p, int l, Player p) : leftnum(l), p(p) {
        parent = p;
        left = right = NULL;
    }
};

class Btree {
    Node* root;

   public:
    void insert(Node* n);
    void update(Node* n);
    void delnode(Node* n);
    void getnode(Node* n);
};

class RankBoard {
   public:
    void insertPlayer(Player p);
    void getTopK(int k);
    void printTopK(int k);
};

void RankBoard::insertPlayer(Player p) {
    cout << "insert player here" << endl;
}

void RankBoard::getTopK(int k) {
    cout << "get top k here" << endl;
}

void RankBoard::printTopK(int k) {
    cout << "print top k here" << endl;
}

void init() {
    RankBoard rb;
    rb.insertPlayer({1, 1});
    rb.getTopK(1);
    rb.printTopK(1);
}

int main() {
    cout << "Million Players Rank Board Starts" << endl;
    init();
    return 0;
}