// AVL.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>
#include <stack>
#define elif else if

using namespace std;

template <typename T> class  AVL {
private:

	struct __avl {
		T info;
		int lf, rg;
		unique_ptr < __avl > st, dr;
		__avl() {
			lf = rg = 0;
		}
	};

	unique_ptr < __avl > root;
	int __size;

	inline int __getHighest(unique_ptr < __avl > &root) {
		if (!root)return -1;//in caz ca e null operatia -1 + 1 da 0
		return max(root->lf, root->rg);
	}

	inline bool __leftHeavy(const unique_ptr < __avl > &root) {
		return root->lf >= root->rg;
	}

	unique_ptr < __avl > __RotateLeft(unique_ptr < __avl > &root) {
		///if right-heavy then rotate left
		auto q = move(root->dr);
		root->dr = move(q->st);
		root->rg = __getHighest(root->dr) + 1;
		q->st = move(root);
		q->lf = __getHighest(q->st) + 1;
		return q;
	}

	unique_ptr < __avl > __RotateRight(unique_ptr < __avl > &root) {
		///if left-heavy then rotate right
		auto q = move(root->st);//q owns root->st  , root->st = null
		root->st = move(q->dr);//root->st owns left's right sons , q->dr = null;
		root->lf = __getHighest(root->st) + 1;
		q->dr = move(root);//root = null;
		q->rg = __getHighest(q->dr) + 1;
		return q;
	}

	inline bool __NeedBalance(unique_ptr < __avl > &root) {
		return root && abs(root->lf - root->rg) >= 2;
	}

	unique_ptr < __avl > Balance(unique_ptr < __avl > &root) {
		auto q = move(root);
		if (__NeedBalance(q)) {
			if (__leftHeavy(q)) {
				///if root is leaftHeavy we need to perorm or a right-right rotation or a right-left rotation
				if (!__leftHeavy(q->st))q->st = move(__RotateLeft(q->st));//if we need to perform a right-left rotation firstly rotate left the root's left son
				return __RotateRight(q);//perform a right rotation
			}
			///elese if root is right heavy we need to perform or a left-left rotation or a left-right rotation
			if (__leftHeavy(q->dr)) q->dr = move(__RotateRight(q->dr));//if we need to perform a left right rotation firstly rotate right the root's right son
			return __RotateLeft(q);//perform  a left rotation
		}
		return q;
	}


	unique_ptr < __avl > __insert(unique_ptr < __avl > &root, const T &val) {

		if (!root) {
			auto q = make_unique < __avl >();
			q->info = val;
			return q;
		}

		if (root->info > val) {
			root->st = move(__insert(root->st, val));
			root->lf = max(root->lf, __getHighest(root->st) + 1);
		}

		elif(root->info != val) {
			root->dr = move(__insert(root->dr, val));
			root->rg = max(root->rg, __getHighest(root->dr) + 1);
		}
		else --__size;

		return Balance(root);
	}

	void __rsd(__avl *root) {
		if (root) {
			cout << root->info << ' ';
			__rsd(root->st.get());
			__rsd(root->dr.get());
		}
	}

	bool __find(unique_ptr < __avl > &root, const T & val) {
		if (root) {
			if (root->info == val)return true;
			if (root->info > val)return __find(root->st, val);
			return __find(root->dr, val);
		}
		return false;
	}


	void __deleteLeaf(unique_ptr <__avl > &root, unique_ptr < __avl > &dad) {

		if (dad == root) {///then the root is the tree's root
			dad.reset(nullptr);
			return;
		}


		if (root->info > dad->info) {
			auto q = move(dad->dr);
			return;
		}

		auto q = move(dad->st);
	}

	void __deleteSingleChild(unique_ptr <__avl > &root, unique_ptr < __avl > &dad) {
		if (root == dad) {///tree's root case
			root = move(root->st ? root->st : root->dr);
			return;
		}
		if (dad->info > root->info) {
			dad->st = move(root->dr ? root->dr : root->st);
			return;
		}
		dad->dr = move(root->dr ? root->dr : root->st);
	}

	T __deleteTwoChilds(unique_ptr <__avl > &root) {
		auto q = root->st.get();
		while (q->dr)q = q->dr.get();
		return q->info;
	}

	void __erase(unique_ptr <__avl > &root, const T & val, unique_ptr < __avl > &dad) {

		if (!root) {
			++__size;
			return;
		}

		if (root->info == val) {

			if (!root->st && !root->dr) {
				__deleteLeaf(root, dad);
				return;
			}

			if (!root->st || !root->dr) {
				__deleteSingleChild(root, dad);
				return;
			}

			root->info = __deleteTwoChilds(root);///chose the biggest son which is less than root->info

			__erase(root->st, root->info, root);///erase that value from the root's left-subtree (in that way because it's the only way which ensure us that tree remains balanced)
			if (root)root->lf = __getHighest(root->st) + 1;///update root->lf size(only in __deleteTwoChilds case)
		}

		elif(root->info > val) {
			__erase(root->st, val, root);
			if (root)root->lf = __getHighest(root->st) + 1;
		}

		else {
			__erase(root->dr, val, root);
			if (root)root->rg = __getHighest(root->dr) + 1;
		}

		root = move(Balance(root));
	}


	void __Tidy(unique_ptr < __avl  >&root) {
		if (!root)return;
		if (root->dr) __Tidy(root->dr);
		if (root->st)__Tidy(root->st);
		auto q = move(root);
		--__size;
	}

public:

	AVL() {
		__size = 0;
	}

	void Insert(const T & val) {
		if (!__size) {
			root = make_unique  < __avl >();
			root->info = val;
		}
		else root = move(__insert(root, val));
		++__size;
	}

	inline bool Find(const T&val) {
		return __find(root, val);
	}

	void Erase(const T & val) {
		__erase(root, val, root);
		--__size;
	}

	inline int Size() const {
		return __size;
	}

	~AVL() {
		__Tidy(root);
	}

	class iterator;

	iterator begin();

	iterator end();
};


template <typename T>class AVL<T>::iterator {

private:
	stack < __avl* >stack;
	__avl* root;


	void __goLeft() {

		while (root) {
			stack.push(root);
			root = root->st.get();
		}

		if (stack.empty())return;

		root = stack.top(); stack.pop();
	}

public:

	iterator(__avl* root) : root{ root } { __goLeft(); }

	iterator(const iterator& other) {
		*this = other;
	}

	iterator& operator ++() {//++it
		root = root->dr.get();
		__goLeft();
		return *this;
	}

	iterator operator ++(int) {//it ++
		auto last = *this;
		root = root->dr.get();
		__goLeft();
		return last;
	}

	iterator& operator =(const iterator& other) {
		root = other.root;
		stack = other.stack;
		return *this;
	}

	const T& operator *() const{
		return root->info;
	}


	bool operator !=(const iterator& other) const {
		return !(stack.empty() && root == other.root);
	}

};

template < typename T> typename AVL<T>::iterator AVL<T>::begin() {
	return iterator(root.get());
}

template < typename T> typename AVL<T>::iterator AVL<T>::end() {
	return iterator(nullptr);
}
