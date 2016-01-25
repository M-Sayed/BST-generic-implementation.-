#include <bits/stdc++.h>
using namespace std;
#define null NULL

template<class T1, class T2> struct Node {
	Node *parent, *left, *right;
	T1 key;
	T2 value;
	Node() { left = right = parent = null; }
	Node(T1 t1, T2 t2) { left = right = parent = null, key = t1, value = t2; }
};
namespace DS {
	template<class T1, class T2> class map {
	public:
		map<T1, T2>() { root = null; }
		map(T1 k, T2 v) { root = new Node<T1, T2>(k, v); }
		bool containsKey(T1);
		Node<T1, T2>* search(T1);
		T2 getValue(T1);
		void insert(T1, T2);
		void modify(T1, T2);
		void insertOrModify(T1, T2);
		void print();
	private:
		Node<T1, T2>* root;
		// these functions used for simplifying their uses for the user.
		Node<T1, T2>* _search(Node<T1, T2>*, T1);
		void _insert(Node<T1, T2>*, Node<T1, T2>*, T1, T2);
		void _modify(Node<T1, T2>*, T1, T2);
		void _print(Node<T1, T2>*);
	};
}
