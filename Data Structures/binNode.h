/*
Binary Search Tree Node/Tool-Kit Prototypes
*/

#ifndef BINNODE_H
#define BINNODE_H

// Headers
#include <cstdlib>

template <class Type> class BinNode {
public:
	// Typedefs
	typedef Type value_type;
	
	// Constructors
	BinNode(const Type &dataIn = Type(), BinNode *leftIn = 0, BinNode *rightIn = 0)
		: data(dataIn), left(leftIn), right(rightIn) {}
	
	// Modification Member Functions
	Type& getData() { return data; }
	BinNode*& getLeft() { return left; }
	BinNode*& getRight() { return right; }
	void setData(const Type &dataIn) { data = dataIn; }
	void setLeft(BinNode *leftIn) { left = leftIn; }
	void sertRight(BinNode *rightIn) { right = rightIn; }

	// Const Member Functions
	const Type& getData() const { return data; }
	const BinNode* getLeft() const { return left; }
	const BinNode* getRight() const { return right; }
	bool  isLeaf() const { return (left == 0) && (right == 0); }

private:
	// Data Members
	Type data;
	BinNode *left, *right;
};

// Binary Tree Tool-Kit
template<class Process, class BNode>
void inOrder(Process f, BNode *nodeIn);

template<class Process, class BNode>
void preOrder(Process f, BNode *nodeIn);

template<class Process, class BNode>
void postOrder(Process f, BNode *nodeIn);

template<class Type>
void insertTree(const Type &entry, BinNode<Type> *&rootIn);

// delete
// is_balanced

template<class Type>
bool isLeaf(const BinNode<Type> *nodeIn);

template<class Type>
unsigned leafCount(const BinNode<Type> *rootIn);

template<class Type>
BinNode<Type>* inTree(const Type &entry, BinNode<Type>* rootIn);

template<class Type, class SizeType>
void printTree(const BinNode<Type> *nodeIn, SizeType depth);

template<class Type>
bool is_empty(const BinNode<Type> *rootIn);

template<class Type>
void treeClear(BinNode<Type> *&rootIn);

template<class Type>
BinNode<Type>* treeCopy(const BinNode<Type> *rootIn);

template<class Type>
std::size_t treeSize(const BinNode<Type> *nodeIn);

template<class Type>
std::size_t treeMaxDepth(const BinNode<Type> *nodeIn);

template<class Type>
std::size_t treeMinDepth(const BinNode<Type> *nodeIn);

template<class Type>
std::size_t treeEqualDepth(const BinNode<Type> *nodeIn); 

#include "binNode.tem"
#endif

