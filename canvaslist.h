///Name: Cosmin Narovici
///
///Program Purpose: Implementing a linked list of shape objects which will be "drawn" where their information will be displayed. 

#pragma once

#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;

    public:
        //Default constructor
        CanvasList() {
            listSize = 0;
            listFront = nullptr;
        }
        //Copy constructor, takes another CanvasList object as the param.
        //Creates a deep copy of all the nodes in the linked list by allocating 
        //memory for each node being copied over.
        CanvasList(const CanvasList & other) {
            listSize = other.listSize;
            if (other.listFront == nullptr) {
                listFront = nullptr;
                return;
            }
            ShapeNode* traverse = other.listFront; //traverse and newOther are used to traverse through the other CanvasList.
            ShapeNode* newOther = new ShapeNode;
            newOther->value = traverse->value->copy();
            newOther->next = nullptr;
            traverse = traverse->next;
            listFront = newOther;
            while (traverse != nullptr) {
                ShapeNode* tempNode = new ShapeNode;
                tempNode->value = traverse->value->copy();
                tempNode->next = nullptr;
                newOther->next = tempNode;
                newOther = newOther->next;
                traverse = traverse->next;
            }
        }
        //Function that takes in the parameter of a second CanvasList and sets one equal to the other by making a deep copy.
        //Returns deep copy of CanvasList
        CanvasList operator=(const CanvasList & other) {
            clear(); //Clear is called to empty the CanvasList that will be copied to.

            listSize = other.listSize;
            if (other.listFront == nullptr) {
                listFront = nullptr;
                return *this;
            }
            ShapeNode* traverse = other.listFront; //traverse is used to traverse the other CanvasList
            ShapeNode* newOther = new ShapeNode; 
            newOther->value = traverse->value->copy();
            newOther->next = nullptr;
            traverse = traverse->next;
            listFront = newOther;
            while (traverse != nullptr) { //loop to deep copy all nodes
                ShapeNode* tempNode = new ShapeNode;
                tempNode->value = traverse->value->copy();
                tempNode->next = nullptr;
                newOther->next = tempNode;
                newOther = newOther->next;
                traverse = traverse->next;
            }

            return *this; //returns the deep copy of the CanvasList
        }
        //Destructor for CanvasList which calls clear to deallocate all memory.
        virtual ~CanvasList() {
            clear();
        }
        //Function to empty CanvasList and deallocate memory.
        void clear() {
            ShapeNode* tempNode = new ShapeNode;
            while (listFront != nullptr) {
                tempNode = listFront;
                listFront = listFront->next;
                delete tempNode->value;
                delete tempNode;
            }
            listSize = 0;
        }
        //Function that takes an int for the index to insert after and the shape being inserted.
        void insertAfter(int pos, Shape * s) {
            if (pos >= listSize || pos < 0) {
                return;
            } 
            ShapeNode* traverse; //traverse used to traverse the CanvasList.
            traverse = listFront;
            while (pos--) {
                traverse = traverse->next;
            }
            ShapeNode* inserting = new ShapeNode; //allocating memory for the node to be inserted.
            inserting->value = s; 
            inserting->next = traverse->next;
            traverse->next = inserting;
            listSize++;
        } 
        //Function that takes in a Shape object which will be appended to the front of CanvasList.
        void push_front(Shape * s) {
            ShapeNode* inserting = new ShapeNode;
            inserting->value = s;
            inserting->next = listFront;
            listFront = inserting;
            listSize++;
        }
        //Function that takes in a Shape object which will be appended to the end of CanvasList.
        void push_back(Shape * s) {
            ShapeNode* temp = new ShapeNode;
            ShapeNode* traverse = listFront;
            temp->value = s;
            temp->next = nullptr;
            if (listFront == nullptr) { //Conditional to check for an empty CanvasList.
                listFront = temp;
                listSize++;
                return;
            }
            
            while (traverse->next != nullptr) { //Loop to traverse through the nodes of CanvasList.
                traverse = traverse->next;
            }
            traverse->next = temp;
            listSize++;
        }
        //Function that takes an int for the index of the node to be removed from CanvasList.
        void removeAt(int pos) {
            if (pos >= listSize || pos < 0) {
                return;
            }
            if (pos == 0) { //If the first node is being removed, the listFront is changed.
                ShapeNode* tempNode = listFront;
                listFront = listFront->next;
                delete tempNode->value;
                delete tempNode;
                listSize--;
                return;
            }
            if (pos == (listSize-1)) {
                pop_back(); //Calls pop_back function to remove the last node if the index is 1 less than the size of CanvasList.
                return;
            }
            ShapeNode* tempNode = listFront;
            while (--pos > 0) {
                tempNode = tempNode->next;
            }
            ShapeNode* beforeNode = tempNode; //Used to store the node before the node to be deleted.
            ShapeNode* nextNode = tempNode->next->next; //Used to store the node after the node to be deleted.
            delete tempNode->next->value;
            delete tempNode->next; //Deletes target node.
            beforeNode->next = nextNode; //Reconnects CanvasList.
            listSize--;
        }
        //Function that deletes the first node of CanvasList while returning the Shape object that was being stored.
        Shape* pop_front() {
            if (listFront == nullptr) {
                return nullptr;
            }
            ShapeNode* tempNode = listFront;
            listFront = listFront->next;
            Shape* temp;
            temp = tempNode->value;
            delete tempNode;
            listSize--;
            return temp;
        }
        //Function that deletes the last node of CanvasList while returning the Shape object that was being stored.
        Shape* pop_back() {
            if (listFront == nullptr) {
                return nullptr;
            }
            if (listFront->next == nullptr) {
                listSize--;
                Shape* temp;
                temp = listFront->value;
                listFront = nullptr;
                return temp;
            }
            ShapeNode* tempNode = listFront;
            while (tempNode->next->next != nullptr) {
                tempNode = tempNode->next;
            }
            Shape* temp;
            temp = tempNode->next->value;
            delete tempNode->next;
            tempNode->next = nullptr;
            listSize--;
            return temp;
        }
        //Function that returns the first node in CanvasList.
        ShapeNode* front() const {
            return listFront;
        }
        //Function that returns if CanvasList is empty.
        bool isempty() const {
            if (listSize == 0) {
                return true;
            }
            return false;
        }
        //Function that returns the size of CanvasList.
        int size() const {
            return listSize;
        }
        //Function that takes 2 ints and checks CanvasList to find the index of a shape
        // that has the same values or reeturns -1 if not found.
        int find(int x, int y) const {
            if (listSize == 0) {
                return -1;
            }
            int counter = 0;
            ShapeNode* traverse = listFront;
            while (counter < listSize) {
                if (traverse->value->getX() == x && traverse->value->getY() == y) {
                    return counter;
                }
                traverse = traverse->next;
                counter++;
            }
            return -1;
        }
        //Function that takes in the index of what node is being looked for in CanvasList and returns the shape being stored there.
        Shape* shapeAt(int index) const {
            if (listFront == nullptr) {
                return nullptr;
            }
            if (index >= listSize || index < 0) {
                return nullptr;
            }
            ShapeNode* traverse = listFront;
            int counter = 0;
            while (counter < index) {
                traverse = traverse->next;
                counter++;
            }
            return traverse->value;
        }
        //Function that prints each shape in CanvasList node by node.
        void draw() const {
            if (listFront != nullptr) {
                ShapeNode* traverse = listFront;
                while (traverse != nullptr) {
                    traverse->value->printShape();
                    traverse = traverse->next;
                }
            }
        }
        //Function that prints each address of the node and shape being stored in the node.
        //It prints node by node.
        void printAddresses() const {
            if (listFront != nullptr) {
                ShapeNode* traverse = listFront;
                while (traverse != nullptr) {
                    cout << "Node address: " << traverse << "\tShape address: " << traverse->value << endl;
                    traverse = traverse->next;
                }
            }
        }
};
