/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: Oct. 2023
 */
 

#include "BST.h"
#include "WordPair.h"
#include <iostream>

using std::cout;
using std::endl;

// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver 
// - the one we will use to mark this assignment - will not know about them
// since we will use these public method prototypes to create our test driver.

/* Constructors and destructor */

   // Default constructor
   BST::BST(){             
      root = nullptr;
      elementCount = 0;
   }         

   // Copy constructor
   BST::BST(const BST &aBST) {
      //copying the element count
      elementCount = aBST.elementCount;

    
      if (aBST.root != nullptr) {
        root = new BSTNode(aBST.root->element);

        //copying the left side
        if (aBST.root->left != nullptr) {
            root->left = new BSTNode(aBST.root->left->element);
         }

        //copying the right side
        if (aBST.root->right != nullptr) {
            root->right = new BSTNode(aBST.root->right->element);
         }
      } 
      else {
        root = nullptr;
      }
   }

   // Destructor 
   BST::~BST() {
    
      if (root != nullptr) {
        delete(root->left);
        delete(root->right);
        delete root;
      }
   }
   
/* Getters and setters */

   // Description: Returns the number of elements currently stored in the binary search tree.   
   // Time efficiency: O(1)   
   unsigned int BST::getElementCount() const {     

     return this->elementCount;
   }
   

/* BST Operations */

   // Description: Inserts an element into the binary search tree.
   //              This is a wrapper method which calls the recursive insertR( ).
   // Precondition: "newElement" does not already exist in the binary search tree.
   // Exception: Throws the exception "UnableToInsertException" when newElement 
   //            cannot be inserted because the "new" operator failed. 
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the binary search tree.
   // Time efficiency: O(log2 n)   
  
   void BST::insert(WordPair &newElement) {
      BSTNode *newNode = new BSTNode(newElement);

      if (root == nullptr) {
         root = newNode;
         elementCount++;
      } 
      else {
        insertR(newNode, root);
      }
   }

   
   // Description: Recursive insertion into a binary search tree.
   //              Returns true when "anElement" has been successfully inserted into the 
   //              binary search tree. Otherwise, returns false.
   // Precondition: "newElement" does not already exist in the binary search tree.
   // Exception: Throws the exception "UnableToInsertException" when newElement 
   //            cannot be inserted because the "new" operator failed. 
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the binary search tree.
   
   bool BST::insertR(BSTNode *newBSTNode, BSTNode *current) {

      if (current == nullptr) {
         current = newBSTNode;
         elementCount++;
         return true;
      }
      //if already exists
      if (newBSTNode->element == current->element) {
         throw ElementAlreadyExistsException("Element already exists in the tree.");
      
      } 
      //insert in left subtree
      else if (newBSTNode->element < current->element) {
         //find the leftmost
         if (current->hasLeft()) {
            return insertR(newBSTNode, current->left);
         } 
         
         else {
            try{
               current->left = newBSTNode;
               elementCount++;
               return true;
            }
            catch(UnableToInsertException &e)
            {
               throw UnableToInsertException("Insertion Failed");
            }

            
         }
      } 
      //insert in right subtree
      else {
         //find the rightmost
         if (current->hasRight()) {
            return insertR(newBSTNode, current->right);
         } 
         else {
            try{
               current->right = newBSTNode;
               elementCount++;
               return true;
            }
            
            catch(UnableToInsertException &e)
            {
               throw UnableToInsertException("Insertion Failed");
            }
            
         }
      }
   }



   
   // Description: Retrieves "targetElement" from the binary search tree.
   //           This is a wrapper method which calls the recursive retrieveR( ).
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the binary search tree is empty.
   // Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
   //            thrown from the retrieveR(...)
   //            if "targetElement" is not in the binary search tree.
   // Time efficiency: O(log2 n)
   WordPair& BST::retrieve(WordPair & targetElement) const {
      
     if (elementCount == 0)  
        throw EmptyDataCollectionException("Binary search tree is empty.");
	
     WordPair& translated = retrieveR(targetElement, root);
	 
     return translated;
   }

   // Description: Recursive retrieval from a binary search tree.
   // Exception: Throws the exception "ElementDoesNotExistException" 
   //            if "targetElement" is not found in the binary search tree.
  
   WordPair &BST::retrieveR(WordPair &targetElement, BSTNode *current) const {
      
      if (current == nullptr) {
         throw ElementDoesNotExistException("Element does not exist in the tree.");
      }

      if (targetElement == current->element) {
         return current->element;
      } 
      //search left subtree
      else if (targetElement < current->element) {
        return retrieveR(targetElement, current->left);
      } 
      //search right subtree
      else {
        return retrieveR(targetElement, current->right);
      }
   }
   
   // Description: Traverses the binary search tree in order.
   //           This is a wrapper method which calls the recursive traverseInOrderR( ).
   //           The action to be done on each element during the traverse is the function "visit".
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //         if the binary search tree is empty.
   // Time efficiency: O(n)     
   void BST::traverseInOrder(void visit(WordPair &)) const {
     
     if (elementCount == 0)  
       throw EmptyDataCollectionException("Binary search tree is empty.");

     traverseInOrderR(visit, root);
     
     return;
   }

   // Description: Recursive in order traversal of a binary search tree.   
   void BST::traverseInOrderR(void visit(WordPair &), BSTNode* current) const { 
      
      if (current != nullptr) {
         //go left, then root and then right
        traverseInOrderR(visit, current->left);
        visit(current->element);
        traverseInOrderR(visit, current->right);
      }
	  
   }
