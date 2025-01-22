/*
 * BSTNode.h
 * 
 * Description: Models a node required to build a link-based binary search tree (BST).
 * 
 * Author: AL
 * Date of last modification: Oct. 2023
 */

#ifndef BST_NODE_H
#define BST_NODE_H

#include "WordPair.h"


class BSTNode {

public:

    WordPair element;
    BSTNode * left = nullptr;
    BSTNode * right = nullptr;

    // Constructors
    BSTNode();
    BSTNode(WordPair & element);
    BSTNode(WordPair & element, BSTNode * theLeftSubTree, BSTNode * theRightSubTree) ;

    // Boolean helper functions
    bool isLeaf() const;
    bool hasLeft() const;
    bool hasRight() const;

};
#endif
