#ifndef A04Q2C_H
#define A04Q2C_H


#include <cstddef>

#include <ostream>
#include <iostream>

#include <string>
#include <cstdio>
enum Color {
    NONE = 0,
    BLACK, RED, GREEN,
    YELLOW, BLUE, MAGENTA,
    CYAN, WHITE
};

std::string set_color(Color foreground = NONE, Color background = NONE);

class BSTNode {
private:
      int value;
      BSTNode* left;
      BSTNode* right;
      
      float balance;
      int leftDescendants;
      int rightDescendants;

public:
      BSTNode( int value );

      bool Insert(int value);
      bool Search(int value);

      int Value() const { return value; }
      BSTNode* Left() const { return left; }
      BSTNode* Right() const { return right; }

      float Balance() const { return balance; }
      int LeftDescendants() const { return leftDescendants; }
      int RightDescendants() const { return rightDescendants; } 
			friend std::ostream &operator<<(std::ostream &os,BSTNode &bn){
				using namespace std;
				return os << '(' << bn.value << ',' << bn.leftDescendants << ',' << bn.rightDescendants << ',' << bn.balance << ')';
			}
			void fixMetaData();
			bool isBalance();

			friend class BinarySearchTree;
};


class BinarySearchTree {
private:
      BSTNode* root;

public:
      BinarySearchTree() {
            root = NULL;
      }

      bool Insert(int value);
      bool Search(int value);
			void rotateLeft(BSTNode **tar);
			void rotateRight(BSTNode **tar);
			void doubleLeft(BSTNode **tar);
			void doubleRight(BSTNode **tar);

      BSTNode* Root() const { return root; }

#ifdef ALFRED_DEBUG
			void clean_helper(BSTNode *n){
				if (!n) return;
				clean_helper(n->Left());
				clean_helper(n->Right());
				delete n;
			}
			void print_helper(BSTNode *n, int depth = 0){
				using namespace std;
				if (!n) return;
				int new_d = depth + 4;
				print_helper(n->Right(), new_d);
				for (int i = 0; i < depth; i++){
					cout << ' ';
				}
				cout << *n << endl;
				print_helper(n->Left(), new_d);
			}
			void print(){
				using namespace std;
				cout << set_color(BLUE)<<"Start of tree" << set_color(YELLOW)<< endl;
				print_helper(root);
				cout << set_color(BLUE)<< "End of tree" << set_color()<<endl;
			}
			~BinarySearchTree(){
				print_helper(root);
				clean_helper(root);
			}
#endif
};


#endif
