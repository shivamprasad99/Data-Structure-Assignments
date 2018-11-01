#ifndef VECTORTREE_HPP
#define VECTORTREE_HPP

#include <vector>
#include <iostream>
using namespace std;

template <typename E>
class VectorTree{

public:

	typedef typename std::vector<E>::iterator Position;

	VectorTree() : v(1) {}    // constructor

	int size() const{
		return v.size() - 1; 
	}

	Position left(const Position& p){
		if(hasLeft(p))
			return pos(2*idx(p)); 
	}

	Position right(const Position& p){
		if(hasRight(p))
			return pos(2*idx(p) + 1); 
	}

	Position parent(const Position& p){
		if(!isRoot(p))
			return pos(idx(p)/2); 
	}

	bool hasLeft(const Position& p) const{
		return 2*idx(p) <= size(); 
	}

	bool hasRight(const Position& p) const {
		return 2*idx(p) + 1 <= size(); 
	}

	bool isRoot(const Position& p) const{
		return idx(p) == 1; 
	}

	Position root(){
		return pos(1);
	}

	Position last(){
		return pos(size()); 
	}

	void addLast(const E& e){
		v.push_back(e); 
	}

	void removeLast(){
		v.pop_back(); 
	}

	void swap(const Position& p, const Position& q){
		E e = *q; *q = *p; *p = e; 
	}

	Position pos(int i){
		return v.begin() + i; 
	} 

	int idx(const Position& p) const{
		return p - v.begin(); 
	}
private: 
	vector<E> v; 


};

#endif