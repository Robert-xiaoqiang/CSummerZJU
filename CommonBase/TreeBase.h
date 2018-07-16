#ifndef TREEBASE_H_
#define TREEBASE_H_

#include <functional>
#include "../CommonModel/Common.h"
#include <queue>
using namespace std;

template <typename T>
struct BaseNode {
	T key;
	BaseNode *left;
	BaseNode *right;

	int depth;
	int inorderIndex; 
	NodeType state;

	BaseNode(const T& key);
	virtual ~BaseNode(); 
};

template <typename T>
BaseNode<T>::BaseNode(const T& key):
	key(key),
	left(nullptr),
	right(nullptr),
	depth(0),
	inorderIndex(0),
	state(OTHER)
{

}

// root-first recurrensive dtor!
template <typename T>
BaseNode<T>::~BaseNode()
{
	if(left) delete left;
	if(right) delete right;
}

template <typename T, typename S = std::less<T>>
class BaseTree {
protected:
	BaseNode<T> *root;
protected:
	void inorder(BaseNode<T> *cur, int *count);
	void levelorder();
public:
	BaseTree();
	virtual ~BaseTree();
	BaseNode<T> *getRoot();
};

template <typename T, typename S>
BaseTree<T, S>::BaseTree():
	root(nullptr)
{

}

template <typename T, typename S>
BaseTree<T, S>::~BaseTree()
{
	if(root != nullptr) delete root;
}

template <typename T, typename S>
BaseNode<T> *BaseTree<T, S>::getRoot()
{
	return root;
}

template <typename T, typename S>
void BaseTree<T, S>::inorder(BaseNode<T> *cur, int *count)
{
	if(cur != nullptr) {
		inorder(cur->left, count);
		cur->inorderIndex = (*count)++;
		inorder(cur->right, count);
	}
}

template <typename T, typename S>
void BaseTree<T, S>::levelorder()
{
	queue<BaseNode<T> *> myQueue;
	if(root) {
		root->depth = 0;
		myQueue.push(root);
		while(!myQueue.empty()) {
			BaseNode<T> *cur = myQueue.front();
			myQueue.pop();
			cur->state = OTHER;
			if(cur->left) {
				cur->left->depth = cur->depth + 1;
				myQueue.push(cur->left);
			}
			if(cur->right) {
				cur->right->depth = cur->depth + 1;
				myQueue.push(cur->right);
			}
		}
	}
}

#endif