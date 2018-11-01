#ifndef PQUEUE_HPP
#define PQUEUE_HPP
#include "VectorTree.hpp"
#include <math.h>


bool isPowerOfTwo (int x) {
  return x && (!(x&(x-1))); 
} 

template <typename E>
class locator{
public:
	int index;
};

template <typename E, typename C>		//E is element type and C is comparator
class pQueue{ 			// adaptable priority queue
  private:	
  	C isLess;
    typedef typename VectorTree<E>::Position position;	//iterator to vectortree
	VectorTree<E> Q;
	VectorTree<locator<E>*> QL;
	typedef typename VectorTree<locator<E>*>::Position lposition;

  public:

	pQueue(){

	}

	pQueue(vector<E> arr){
		for(int i=0;i<=arr.size()-1;i++){
			insert(arr[i]);
			//Q.root()->print();
		}
	}

	int size() const{
		return Q.size();
	}

	bool empty() const{
		return this->size()==0;
	}

	const E& min(){
		return *(Q.root());	// root is the first element in the vector which is the minimum in case of a minheap
	}


    int insert(const E& e){		// bottom up construction of the heap returns the index of the element just inserted
		locator<E>* el=new locator<E>();
		Q.addLast(e);
		QL.addLast(el);
		position temp=Q.last();		// initialised temporary position with the initial insertion position of the 
		lposition templ=QL.last();
		while(!Q.isRoot(temp)){
			position par = Q.parent(temp);
			lposition parl = QL.parent(templ);
			if(!isLess(*temp,*par))
				break;
			else{
				Q.swap(temp,par);
				QL.swap(templ,parl);
				(*templ)->index=QL.idx(templ);
				(*parl)->index=QL.idx(parl);
				temp=par;
				templ=parl;
			}
		}
		(*templ)->index=Q.idx(temp);
		return QL.idx(templ);
	}

    void removeMin() {
		if (size() == 1){
			Q.removeLast();
			QL.removeLast();
		}
		else {
			position temp = Q.root();
			lposition templ=QL.root();
			Q.swap(temp, Q.last());
			QL.swap(templ,QL.last());
			(*templ)->index=QL.idx(templ);
			(*QL.last())->index=QL.idx(QL.last());
			Q.removeLast();
			QL.removeLast();
			while(Q.hasLeft(temp)){
				position rep = Q.left(temp);
				lposition repl = QL.left(templ);
				if(Q.hasRight(temp)){
					position r = Q.right(temp);
					lposition rl=QL.right(templ);
					if(isLess(*r,*rep)){
						rep=r;
						repl=rl;
					}
				}
				if(isLess(*rep,*temp)){
					Q.swap(rep,temp);
					QL.swap(repl,templ);
					(*templ)->index=QL.idx(templ);
					(*repl)->index=QL.idx(repl);
					temp=rep;
					templ=repl;
				}
				else
					break;
			}
		}
	}


	void remove(int dp){
		position l=Q.pos(dp);
		lposition ll=QL.pos(dp);
		if(dp==1){
			removeMin();
			return;
		}
		Q.swap(l,Q.last());
		QL.swap(ll,QL.last());
		(*ll)->index=QL.idx(ll);
		(*QL.last())->index=QL.idx(QL.last());
		Q.removeLast();
		QL.removeLast();
		if(isLess(*Q.parent(l),*l))	{	//if new element at l is greater than the parent then bubble down to correct position
			while(Q.hasLeft(l)){
				position rep = Q.left(l);
				lposition repl = QL.left(ll);
				if(Q.hasRight(l)){
					position r = Q.right(l);
					lposition rl = QL.right(ll);
					if(isLess(*r,*rep)){
						rep=r;
						repl=rl;
					}
				}
				if(isLess(*rep,*l)){
					Q.swap(rep,l);
					QL.swap(repl,ll);
					(*ll)->index=QL.idx(ll);
					(*repl)->index=QL.idx(repl);
					l=rep;
					ll=repl;
				}
				else 
					break;
			}
		}
		// if new element at l is smaller than its parent then it needs to be bubbled up
		else if(isLess(*l,*Q.parent(l))){
			while(!Q.isRoot(l)){
				position par = Q.parent(l);
				lposition parl = QL.parent(ll);
				if(!isLess(*l,*par))
					break;
				else{
					Q.swap(l,par);
					QL.swap(ll,parl);
					(*ll)->index=QL.idx(ll);
					(*parl)->index=QL.idx(parl);					
					l=par;
					ll=parl;
				}
			}
		}
	}

    int replace(int dp, const E& e){
		position l=Q.pos(dp);
		lposition ll=QL.pos(dp);
		locator<E>* el=new locator<E>();
		Q.addLast(e);
		QL.addLast(el);
		Q.swap(l,Q.last());
		QL.swap(ll,QL.last());
		(*ll)->index=QL.idx(ll);
		(*QL.last())->index=QL.idx(QL.last());
		Q.removeLast();
		QL.removeLast();
		// now the new e is the place of the position l need to bubble up or bubble down accordingly
		if(Q.isRoot(l)){
			while(Q.hasLeft(l)){
				position rep = Q.left(l);
				lposition repl = QL.left(ll);
				if(Q.hasRight(l)){
					position r = Q.right(l);
					lposition rl = QL.right(ll);
					if(isLess(*r,*rep)){
						rep=r;
						repl=rl;
					}
				}
				if(isLess(*rep,*l)){
					Q.swap(rep,l);
					QL.swap(repl,ll);
					(*ll)->index=QL.idx(ll);
					(*repl)->index=QL.idx(repl);
					l=rep;
					ll=repl;
				}
				else
					break;
			}
		}
		else if(isLess(*Q.parent(l),*l))	{	//if new element at l is greater than the parent then bubble down to correct position
			while(Q.hasLeft(l)){
				position rep = Q.left(l);
				lposition repl = QL.left(ll);
				if(Q.hasRight(l)){
					position r = Q.right(l);
					lposition rl = QL.right(ll);
					if(isLess(*r,*rep)){
						rep=r;
						repl=rl;
					}
				}
				if(isLess(*rep,*l)){
					Q.swap(rep,l);
					QL.swap(repl,ll);
					(*ll)->index=QL.idx(ll);
					(*repl)->index=QL.idx(repl);
					l=rep;
					ll=repl;
				}
				else 
					break;
			}
		}
		// if new element at l is smaller than its parent then it needs to be bubbled up
		else if(isLess(*l,*Q.parent(l))){
			while(!Q.isRoot(l)){
				position par = Q.parent(l);
				lposition parl = QL.parent(ll);
				if(!isLess(*l,*par))
					break;
				else{
					Q.swap(l,par);
					QL.swap(ll,parl);
					(*ll)->index=QL.idx(ll);
					(*parl)->index=QL.idx(parl);					
					l=par;
					ll=parl;
				}
			}
		}
		return Q.idx(l);
	}

	void printHeap(){
		for(int i=1;i<=Q.size();i++){
			if(floor(log2(i))==ceil(log2(i)))
				cout<<endl;
			cout<<Q.pos(i)->getName()<<" ";
		}
		cout<<endl;
	}

};


#endif
