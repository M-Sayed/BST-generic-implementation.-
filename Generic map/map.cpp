#include "../Generic map/map.h"


// These next method are only used privately.
template<class T1, class T2> Node<T1, T2>* DS::map<T1, T2>::_search(Node<T1, T2>* current, T1 key) {
	if(current == null || current->key == key) return current;
	return _search(current->key < key ? current->right : current->left, key);
}

template<class T1, class T2> void DS::map<T1, T2>::_insert(Node<T1, T2>* current, Node<T1, T2>* prv, T1 key, T2 value) {
	if(current == null){
		current = new Node<T1, T2>();
		current->value = value, current->key = key, current->parent = prv;
		if(prv != null) (prv->key < key ? prv->right = current : prv->left = current);
		else root = current;
		return;
	}
	_insert(current->key < key ? current->right : current->left, current, key, value);
}

template<class T1, class T2> void DS::map<T1, T2>::_modify(Node<T1, T2>* current, T1 key, T2 value) {
	if(current->key == key) current->value = value;
	else if(current->key < key) _modify(current->right, key, value);
	else _modify(current->left, key, value);
}

template<class T1, class T2> void DS::map<T1, T2>::_print(Node<T1, T2>* current) {
	if(current == null) return;
	_print(current->left);
	printf("[%d, %s]\t", current->key, current->value.c_str());
	_print(current->right);
}

// these next methods are used publicly.
template<class T1, class T2> Node<T1, T2>* DS::map<T1, T2>::search(T1 key) {
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

template<class T1, class T2> void DS::map<T1, T2>::modify(T1 key, T2 value) {
	if(!containsKey(key))
		throw invalid_argument("this key doesn\'t exist");
	_modify(root, key, value);
}

template<class T1, class T2> void DS::map<T1, T2>::insertOrModify(T1 key, T2 value) {
	if(containsKey(key)) _modify(root, key, value);
	else _insert(root, new Node<T1, T2>, key, value);
}

template<class T1, class T2> void DS::map<T1, T2>::print() {
	_print(root);
	puts("");
}


int main() {
	DS::map<int, string> mp1;
	for(int i = 1; i <= 26; i++) {
		string tmp = "";
		tmp.push_back(char(i - 1 + 'a'));
		mp1.insert(i, tmp);
	}
	for(int i = 1; i <= 26; i++) {
		cout << i << " " << mp1.getValue(i) << "\n";
	}
	mp1.print();
	for(int i = 1; i <= 26; i++) {
		string tmp = "";
		tmp.push_back(char(i - 1 + 'A'));
		if(i & 1)
			mp1.modify(i, tmp);
	}
	for(int i = 1; i <= 26; i++) {
		cout << i << " " << mp1.getValue(i) << "\n";
	}
	mp1.print();
	mp1.insertOrModify(1, "a");
	mp1.print();
	if(mp1.containsKey(1)) cout << "yup\n";
}

