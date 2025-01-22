/*
 * BSTNode.cpp
 * 
 * Description: Models a node required to build a link-based binary search tree (BST).
 * 
 * Author: AL
 * Date of last modification: Oct. 2023
 */

#include "BSTNode.h"
#include "WordPair.h"

// Constructors
BSTNode::BSTNode() { }

BSTNode::BSTNode(WordPair & newElement) : element(newElement) { }

BSTNode::BSTNode(WordPair & newElement, BSTNode * left, BSTNode * right) {
   this->element = newElement;
   this->left = left;
   this->right = right;   
}

// Boolean helper functions
bool BSTNode::isLeaf() const {
   return (left == nullptr && right == nullptr);
}

bool BSTNode::hasLeft() const {
   return (left != nullptr);
}

bool BSTNode::hasRight() const {
   return (right != nullptr);
}
