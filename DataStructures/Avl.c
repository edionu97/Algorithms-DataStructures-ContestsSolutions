#include <stdio.h>
#include <stdlib.h>
#define cout(x) printf("\n%d\n",x)


typedef struct nd {

	struct nd * st, *dr, *parent;
	int info, nrLeft, nrRight;

}node;


typedef struct {

	node* root;
	int(*fct)(const int, const int);

}trie;

node* createNode() {
	node* __node = (node*)calloc(1, sizeof(node));
	return __node;
}

trie * createTrie(int(*fct)(const int ,const int ) )  {

	trie* __trie = (trie*)calloc(1, sizeof(trie));

	__trie->root = NULL;
	__trie->fct = fct;
	
	return __trie;
}

node* rotateLeft(node * root) {

	node* newRoot = root->dr;

	root->dr = newRoot->st;

	newRoot->st = root; 
	
	newRoot->parent = root->parent, root->parent = newRoot;

	root->nrRight = (!root->dr ? 0 : 1 + max(root->dr->nrRight , root->dr->nrLeft));

	if (root->dr)root->dr->parent = root;

	newRoot->nrLeft = 1 + max(root->nrRight , root->nrLeft);

	return newRoot;
}

node* rotateRight(node* root) {

	node* newRoot = root->st;

	root->st = newRoot->dr;

	newRoot->dr = root;

	newRoot->parent = root->parent, root->parent = newRoot;

	root->nrLeft = (!root->st ? 0 : 1 +  max(root->st->nrRight , root->st->nrLeft));

	if (root->st)root->st->parent = root;

	newRoot->nrRight = 1 + max(root->nrRight ,root->nrLeft);

	return newRoot;
}

int checkLeftHeavy(node* root) {
	return root->nrLeft > root->nrRight;
}


node* balance(node* root) {

	if (abs(root->nrRight - root->nrLeft) <= 1)return root;

	if (!checkLeftHeavy(root)) {//right heavy ->rotate left 

		if (checkLeftHeavy(root->dr)) root->dr = rotateRight(root->dr);//left right rotation

		return rotateLeft(root);
	}
	
	if (!checkLeftHeavy(root->st)) root->st = rotateLeft(root->st);//right left rotation

	return rotateRight(root); //right heavy rotate right
}


node* balanceTrie(node* root,trie* trie) {

	if (!root)return NULL;

	while (root->parent) {

		root = balance(root);
		

		if (!trie->fct(root->parent->info , root->info)) {
			root->parent->st = root;
			root->parent->nrLeft = 1 + max(root->nrRight , root->nrLeft);
			root = root->parent;
			continue;
		}

		root->parent->dr = root;
		root->parent->nrRight = 1 + max(root->nrRight , root->nrLeft);

		root = root->parent;
	}

	return balance(root);
}

void setLeftRight(node* node,trie * trie) {

	while (node->parent) {
		
		if ( !trie->fct(node->info , node->parent->info) ) {

			node->parent->nrRight = max(node->parent->nrRight, 1 + max(node->nrRight, node->nrLeft));
			
			node = node->parent;

			continue;
		}

		node->parent->nrLeft = max(node->parent->nrLeft, 1 + max(node->nrRight, node->nrLeft));

		node = node->parent;
	}

}


void insert(trie** __trie, int info) {

	trie * _trie = *__trie;

	if (_trie->root == NULL) {
		_trie->root = createNode(),_trie->root->info = info;
		return;
	}
	
	node* root = _trie->root, *last = root;

	while (root) {

		if (!_trie->fct(root->info , info) ) {
			last = root, root = root->st;
			continue;
		}

		last = root, root = root->dr;

	}


	if (!_trie->fct(last->info, info) ) {
		last->st = createNode(), last->st->info = info, last->st->parent = last;


		setLeftRight(last->st,_trie);

		_trie->root = balanceTrie(last->st,_trie);
		return;
	}

	last->dr = createNode(), last->dr->info = info, last->dr->parent = last;

	setLeftRight(last->dr,_trie);

	_trie->root = balanceTrie(last->dr,_trie);
}


int find(trie* trie, int value) {

	node* root = trie->root;
	
	while (root) {

		if (root->info == value)return 1;

		if (trie->fct(root->info, value)) {
			root = root->dr;
			continue;
		}

		root = root->st;
	}

	return 0;
}

int isLeaf(node* root) {
	return !root->st && !root->dr;
}

int isTwo(node* root) {
	return root->st && root->dr;
}

void deleteLeaf(node* root,trie** __trie) {

	trie * _trie = *__trie;


	if (root->parent == NULL) { //cazul in care avem un nod
		free(root);
		_trie->root = NULL;
		return;
	}


	if (_trie->fct(root->info, root->parent->info)) {

		--root->parent->nrLeft, root->parent->st = NULL;

	}else {
		--root->parent->nrRight; root->parent->dr = NULL;
	}
	
	setLeftRight(root->parent,_trie);

	_trie->root = balanceTrie(root->parent, _trie);

	free(root);
}

void deleteSingle(node* root, trie ** __trie) {

	trie* _trie = *__trie;

	if (root->parent == NULL) {//cazul in care radacina are un singur fiu

		root->info = (root->st ? root->st->info : root->dr->info);

		free(root->st ? root->st : root->dr);

		root->st = root->dr = NULL;

		return;
	}


	node* parent = root->parent, *son = (root->st ? root->st : root->dr);

	if (_trie->fct(son->info,parent->info)) {
		parent->st = son; son->parent = parent;
	}
	else {
		parent->dr = son; son->parent = parent;
	}

	free(root);

	setLeftRight(son, _trie);

	_trie->root = balanceTrie(son, _trie);
}


void deleteTwo(node* root, trie** __trie) {

	trie* _trie = *__trie;

	node* left = root->st;

	for (; left && left->dr; left = left->dr);

	root->info = left->info--;//scad valoare cu 1 ca sa nu am confilcte(gen radacina alre valoarea 1 si fiul are tot valoarea 1(vezi cazul 1 2 3)


	if (isLeaf(left)) {
		deleteLeaf(left, __trie);
		return;
	}


	deleteSingle(left, __trie);
}



void delete(trie** __trie, int info) {

	trie * _trie = *__trie;

	node* root = _trie->root;

	while (root) {

		if (root->info == info)break;

		if (_trie->fct(root->info, info)) {
			root = root->dr;
			continue;
		}

		root = root->st;
	}

	if (!root)return;

	if (isLeaf(root)) {
		deleteLeaf(root,__trie);return;
	}

	if (isTwo(root)) {
		deleteTwo(root,__trie);return;
	}

	deleteSingle(root,__trie);

}


void deleteAvl(trie **__trie) {//sdr

	trie* _trie = *__trie;

	node* root = _trie->root;


	while (root) {


		if (root->st) {
			root = root->st; continue;
		}

		if (root->dr) {
			root = root->dr; continue;
		}

		node* dad = root->parent;


		if (dad) {

			if (!_trie->fct(root->info, dad->info)) {
				dad->dr = NULL;
			}

			else dad->st = NULL;

		}

		free(root);

		root = dad;
	}

	_trie->root = NULL;
}




void srd(node* root) {

	if (!root)return;

	srd(root->st);
	
	cout(root->info);

	//printf("V%d L%d R%d\n", root->info,root->nrLeft,root->nrRight);
	srd(root->dr);
}



int cresc(const int a, const int b) {
	return a < b;
}

int descCresc(const int a, const int b) {
	return a > b;
}


int main() {

	trie* trie = createTrie(&cresc);

	for (int i = 1; i <= 7; ++i)insert(&trie, i);


	srd(trie->root);


	deleteAvl(&trie);


	///for (int i = 1; i <= 7; ++i)insert(&trie, i);


	printf("\nPress any key to continue\n");
	fgetc(stdin);

	return 0;
}