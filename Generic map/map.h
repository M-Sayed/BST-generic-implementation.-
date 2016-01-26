#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define node Node<T1, T2>

template<class T1, class T2> struct Node {
	Node *parent, *left, *right;
	int leftHeight, rightHeight;
	T1 key;
	T2 value;
	Node() { left = right = parent = null, leftHeight = rightHeight = 0; }
	Node(T1 t1, T2 t2) { left = right = parent = null, key = t1, value = t2, leftHeight = rightHeight = 0; }
};
namespace DS {
	template<class T1, class T2> class map {
	public:
		map<T1, T2>() { root = null; }
		map(T1 k, T2 v) { root = new node(k, v); }
		~map() { _destroy(root); }
		bool containsKey(T1);
		node* search(T1);
		T2 getValue(T1);
		void insert(T1, T2);
		void insertAVL(T1, T2);
		void modify(T1, T2);
		void insertOrModify(T1, T2);
		void print();
	private:
		node* root;
		// these functions used for simplifying their uses for the user.
		node* _search(node*, T1);
		void _insert(node*, node*, T1, T2);
		void _insertAVL(node*, node*, T1, T2);
		void _modify(node*, T1, T2);
		void _print(node*);
		void singleRotateLeft(node*);
		void singleRotateRight(node*);
		void doubleRotateLeft(node*);
		void doubleRotateRight(node*);
		void _destroy(node*);
	};
}
