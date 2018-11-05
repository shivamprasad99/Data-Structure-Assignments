#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "entry.hpp"
using namespace std;

template < typename K,typename V >
class node{
public:
	entry<K,V> data;
	node* left;
	node* right;
	node(){

	}
};

template < typename T,typename U, typename C>		// C is for comaparator
class searchtree{
private:
	node<T,U>* root;
	C isLess;
	int count;
public:
	int height(node<T,U>*);
	int diff(node<T,U>*);
	node<T,U>* insert(T,U);
	node<T,U>* insertUtil(node<T,U>* &,T,U);
	node<T,U>* rr_rotation(node<T,U>*);
	node<T,U>* ll_rotation(node<T,U>*);
	node<T,U>* rl_rotation(node<T,U>*);
	node<T,U>* lr_rotation(node<T,U>*);
	node<T,U>* balance(node<T,U>* &);
	void inorder(node<T,U>*);
	node<T,U>* printLevels();
	node<T,U>* search(T);
	node<T,U>* searchUtil(node<T,U>*,T);
	searchtree(){
		root = NULL;
		count = 0;
	}
	void remove(T);
	void removeUtil(node<T,U>* &,T); 		// delete the key
	node<T,U>* minValueNode(node<T,U>* );
	int size();
	list< entry<T,U> > countAllInRange(T, T);
};

template < typename T,typename U, typename C>
int searchtree<T,U,C>::height(node<T,U>* temp){
	int h=0;
	if(temp!=NULL){
		int lh=height(temp->left);
		int rh=height(temp->right);
		h=max(lh,rh)+1;
	}
	return h;
}

template < typename T,typename U, typename C>
int searchtree<T,U,C>::diff(node<T,U>* temp){
	return height(temp->left)-height(temp->right);
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::rr_rotation(node<T,U>* parent){
	node<T,U>* temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

template <typename T, typename U, typename C>
node<T,U>* searchtree<T,U,C>::ll_rotation(node<T,U>* parent){
	node<T,U>* temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::lr_rotation(node<T,U>* parent){
	node<T,U>* temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::rl_rotation(node<T,U>* parent){
	node<T,U>* temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::balance(node<T,U>* &temp){
	int bal = diff(temp);
	if(bal > 1){
		if(diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if(bal < -1){
		if(diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::insert(T key_,U value_){
	// count++;
	return insertUtil(root,key_,value_);
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::insertUtil(node<T,U>* &troot,T key_,U value_){
	if(troot==NULL){
		count++;
		troot = new node<T,U>;
		troot->data.setKey(key_);
		troot->data.setValue(value_);
		troot->left = NULL;
		troot->right = NULL;
		return troot;
	}
	else if(isLess(key_,troot->data.key())==1){
		troot->left = insertUtil(troot->left, key_, value_);
		troot = balance(troot);
	}
	else if(isLess(key_,troot->data.key())==-1){
		troot->right = insertUtil(troot->right, key_, value_);
		troot = balance(troot);
	}
	else if(isLess(key_,troot->data.key())==0){
		troot->data.setValue(value_);
	}
	return troot;
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::printLevels(){
	if(root == NULL)
		return NULL;
	queue< node<T,U>* > q;
	q.push(root);

	while(!q.empty()){
		int nodeCount = q.size();
		while(nodeCount > 0){
			node<T,U>* temp = q.front();
			cout << temp->data.key() << "     ";
			q.pop();
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			nodeCount--;
		}
		cout<<endl;
	}
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::search(T query){
	return searchUtil(root,query);
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::searchUtil(node<T,U>* troot,T query){
	if(troot == NULL)
		return NULL;
	if(isLess(troot->data.key(),query)==0){
		cout<<troot->data.key()<<"     "<<troot->data.value()<<endl;
		return troot;
	}
	else if(isLess(troot->data.key(),query)==-1)
		return searchUtil(troot->left,query);
	else
		return searchUtil(troot->right,query);
}

template < typename T,typename U, typename C>
node<T,U>* searchtree<T,U,C>::minValueNode(node<T,U>* temp){
	node<T,U>* curr = temp;
	while(curr->left != NULL)
		curr = curr->left;
	return curr;
}


template < typename T,typename U, typename C>
void searchtree<T,U,C>::remove(T query){
	removeUtil(root,query);
}

template < typename T,typename U, typename C>
void searchtree<T,U,C>::removeUtil(node<T,U>* &troot,T query){
	if(troot == NULL){
		return ;
	}
	if(isLess(query,troot->data.key())==1){
		removeUtil(troot->left,query);
	}
	else if(isLess(query,troot->data.key())==-1){
		removeUtil(troot->right,query);
	}
	else{
		if(troot->right == NULL || troot->left == NULL){	// condition for only one or no child
			node<T,U>* temp = troot->left ? troot->left : troot->right;
			if(temp == NULL){	// no child is present then delete directly
				temp = troot;
				troot = NULL;
			}
			else{
				troot->data.setKey(temp->data.key());
				troot->data.setValue(temp->data.value());
				troot->left = NULL;
				troot->right = NULL;
				temp = NULL;
			}
			free(temp);
			count--;
		}
		else{
			node<T,U>* temp = minValueNode(troot->right);
			troot->data.setKey(temp->data.key());
			troot->data.setValue(temp->data.value());
			removeUtil(troot->right,temp->data.key());
		}
	}
	if(troot == NULL){
		return ;
	}
	balance(troot);
	return ;
}

template < typename T,typename U, typename C>
int searchtree<T,U,C>::size(){
	return count;
}

template < typename T,typename U, typename C>
list< entry<T,U> > searchtree<T,U,C>::countAllInRange(T k1, T k2){
	list< entry<T,U> > ans;
	if(root == NULL)
		return ans;
	stack< node<T,U>* > s;
	node<T,U>* curr = root;

	while( curr != NULL || s.empty() == false){
		while(curr != NULL){
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		if(isLess(k1,curr->data.key())>=0 && isLess(curr->data.key(),k2)>=0)
		ans.push_back(curr->data);
		curr = curr->right;
	}
	return ans;
}

#endif
