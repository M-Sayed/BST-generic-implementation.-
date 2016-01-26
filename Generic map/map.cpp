#include "map.h"

template<class T1, class T2> int _max(node* a) {
	return max(a->rightHeight, a->leftHeight);
}


// These next method are only used privately.
template<class T1, class T2> void DS::map<T1, T2>::_destroy(node* current) {
	if(!current) return;
	_destroy(current->left);
	_destroy(current->right);
	delete current;
}
template<class T1, class T2> node* DS::map<T1, T2>::_search(node* current, T1 key) {
	if(current == null || current->key == key) return current;
	return _search(current->key < key ? current->right : current->left, key);
}

template<class T1, class T2> void DS::map<T1, T2>::_insert(node* current, node* prv, T1 key, T2 value) {
	if(current == null){
		current = new node();
		current->value = value, current->key = key, current->parent = prv;
		if(prv != null) (prv->key < key ? prv->right = current : prv->left = current);
		else root = current;
		return;
	}
	_insert(current->key < key ? current->right : current->left, current, key, value);
}
template<class T1, class T2> void DS::map<T1, T2>::_insertAVL(node* current, node* prv, T1 key, T2 value) {
	if(current == null){
		current = new node();
		current->value = value, current->key = key, current->parent = prv, current->leftHeight = current->rightHeight = 0;
		if(prv) {
			if(prv->key < key) prv->right = current, prv->rightHeight = 1;
			else prv->left = current, prv->leftHeight = 1;
		} else root = current;

		return;
	}

	_insertAVL(current->key < key ? current->right : current->left, current, key, value);
	current->rightHeight = current->right ? _max(current->right) + 1 : 0;
	current->leftHeight = current->left ? _max(current->left) + 1 : 0;
	int diff = abs(current->rightHeight - current->leftHeight);
	node* tmp;
	if(diff > 1) { // AVL tree policy is violated - :o - and needs balancing. :D
		if(current->rightHeight > current->leftHeight) { // left-rotation
			tmp = current->right;
			if(tmp->rightHeight > tmp->leftHeight) {  // single-rotation
				singleRotateLeft(current);
			}else { // double-rotation
				doubleRotateLeft(current);
			}
		}else { // right rotation
			tmp = current->left;
			if(tmp->leftHeight > tmp->rightHeight) { // single-rotation
				singleRotateRight(current);
			}else { // double-rotation
				doubleRotateRight(current);
			}
		}
	}
}

template<class T1, class T2> void DS::map<T1, T2>::singleRotateLeft(node* x) {
	node* y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if(!x->parent)
		root = y;
	else if(x == x->parent->left)
		x->parent->left = y;
	else x->parent->right = y;
	y->left = x;
	x->parent = y;

	// updating heights..
	x->leftHeight = x->left ? _max(x->left) + 1 : 0;
	x->rightHeight = x->right ? _max(x->right) + 1 : 0;
	node* tmp = y->right;
	if(tmp) {
		tmp->rightHeight = tmp->right ? _max(tmp->right) : 0;
		tmp->leftHeight = tmp->left ? _max(tmp->left) : 0;
	}
	y->leftHeight = y->left ? _max(y->left) + 1 : 0;
	y->rightHeight = y->right ? _max(y->right) + 1 : 0;
	if(y != root) {
		y->parent->leftHeight = y->parent->left ? _max(y->parent->left) + 1 : 0;
		y->parent->rightHeight = y->parent->right ? _max(y->parent->right) + 1 : 0;
	}
}

template<class T1, class T2> void DS::map<T1, T2>::singleRotateRight(node* x) {
	node* y = x->left;
	x->left = y->right;
	if(y->right)
		y->right->parent = x;
	if(!x->parent)
		root = y;
	else if(x == x->parent->left)
		x->parent->left = y;
	else x->parent->right = y;
	y->right = x;
	x->parent = y;

	// updating heights..
	x->leftHeight = x->left ? _max(x->left) + 1 : 0;
	x->rightHeight = x->right ? _max(x->right) + 1 : 0;
	y->leftHeight = y->left ? _max(y->left) + 1 : 0;
	y->rightHeight = y->right ? _max(y->right) + 1 : 0;
	if(y != root) {
		y->parent->leftHeight = y->parent->left ? _max(y->parent->left) + 1 : 0;
		y->parent->rightHeight = y->parent->right ? _max(y->parent->right) + 1 : 0;
	}
}

template<class T1, class T2> void DS::map<T1, T2>::doubleRotateLeft(node* x) {
	node* y = x->right->left;
	if(y->right) y->right->parent = y->parent;
	y->parent->left = y->right;
	y->right = y->parent;
	x->right->parent = y;
	x->right = y->left;
	if(y->left) y->left->parent = x;
	y->left = x;
	y->parent = x->parent;
	if(!x->parent) root = y;
	else if(x == x->parent->left) x->parent->left = y;
	else x->parent->right = y;
	x->parent = y;

	// updating heights :3
	node* tmp = y->right;
	tmp->rightHeight = tmp->right ? _max(tmp->right) + 1 : 0;
	tmp->leftHeight = tmp->left ? _max(tmp->left) + 1 : 0;
	tmp = y->left;
	tmp->rightHeight = tmp->right ? _max(tmp->right) + 1 : 0;
	tmp->leftHeight = tmp->left ? _max(tmp->left) + 1 : 0;
	tmp = y;
	tmp->rightHeight = tmp->right ? _max(tmp->right) + 1 : 0;
	tmp->leftHeight = tmp->left ? _max(tmp->left) + 1 : 0;
}

template<class T1, class T2> void DS::map<T1, T2>::doubleRotateRight(node* x) {
	node* y = x->left->right;
	if(y->left) y->left->parent = y->parent;
	y->parent->right = y->left;
	y->left = y->parent;
	y->left->parent = y;
	x->left = y->right;
	if(y->right) y->right->parent = x;
	y->right = x;
	y->parent = x->parent;
	if(!x->parent) root = y;
	else if(x == x->parent->left) x->parent->left = y;
	else x->parent->right = y;
	x->parent = y;

	// updating heights :3
	node* tmp = y->right;
	tmp->rightHeight = tmp->right ? _max(tmp->right) + 1 : 0;
	tmp->leftHeight = tmp->left ? _max(tmp->left) + 1 : 0;
	tmp = y->left;
	tmp->rightHeight = tmp->right ? _max(tmp->right) + 1 : 0;
	tmp->leftHeight = tmp->left ? _max(tmp->left) + 1 : 0;
	tmp = y;
	tmp->rightHeight = tmp->right ? _max(tmp->right) + 1 : 0;
	tmp->leftHeight = tmp->left ? _max(tmp->left) + 1 : 0;
}

template<class T1, class T2> void DS::map<T1, T2>::_modify(node* current, T1 key, T2 value) {
	if(current->key == key) current->value = value;
	else if(current->key < key) _modify(current->right, key, value);
	else _modify(current->left, key, value);
}

template<class T1, class T2> void DS::map<T1, T2>::_print(node* current) {
	if(current == null) return;
	_print(current->left);
	printf("[%d, %s, %d]\t", current->key, current->value.c_str(), _max(current));
	_print(current->right);
}

// these next methods are used publicly.
template<class T1, class T2> node* DS::map<T1, T2>::search(T1 key) {
	return _search(root, key);
}

template<class T1, class T2> bool DS::map<T1, T2>::containsKey(T1 key) {
	return search(key) != null;
}

template<class T1, class T2> T2 DS::map<T1, T2>::getValue(T1 key) {
	if(!containsKey(key))
			throw invalid_argument("this key doesn\'t exist.");
	return search(key)->value;
}

template<class T1, class T2> void DS::map<T1, T2>::insert(T1 key, T2 value) {
	 if(containsKey(key))
	 	throw invalid_argument("this key is already exist.");
	_insert(root, null, key, value);

}

template<class T1, class T2> void DS::map<T1, T2>::insertAVL(T1 key, T2 value) {
	if(containsKey(key))
		throw invalid_argument("this key is already exist.");
	_insertAVL(root, null, key, value);
}
template<class T1, class T2> void DS::map<T1, T2>::modify(T1 key, T2 value) {
	if(!containsKey(key))
		throw invalid_argument("this key doesn\'t exist");
	_modify(root, key, value);
}

template<class T1, class T2> void DS::map<T1, T2>::insertOrModify(T1 key, T2 value) {
	if(containsKey(key)) _modify(root, key, value);
	else _insert(root, new node, key, value);
}

template<class T1, class T2> void DS::map<T1, T2>::print() {
	_print(root);
	puts("");
}



int main() {
	DS::map<int, string> mp1;
	int X[] = {2, 7, 1, 8, 3, 4, 5};
	for(int i = 0; i < 7; i++) mp1.insertAVL(X[i], "AA");
	mp1.print();
//	for(int i = 1; i <= 26; i++) {
//		cout << i << " " << mp1.getValue(i) << "\n";
//	}
//	for(int i = 1; i <= 26; i++) {
//		string tmp = "";
//		tmp.push_back(char(i - 1 + 'A'));
//		if(i & 1)
//			mp1.modify(i, tmp);
//	}
//	for(int i = 1; i <= 26; i++) {
//		cout << i << " " << mp1.getValue(i) << "\n";
//	}
//	mp1.print();
//	mp1.insertOrModify(1, "a");
//	mp1.print();
//	if(mp1.containsKey(1)) cout << "yup\n";
}

