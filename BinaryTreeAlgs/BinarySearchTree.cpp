#include <iostream>
// curtesy of https://medium.com/@13dipty/binary-search-tree-implementation-in-c-537b9a9cedf8
// print nodes in level order - curtesy of https://www.geeksforgeeks.org/level-order-tree-traversal/

class BST
{
public:
	int value;
	BST* left;
	BST* right;


	BST(int val) {
		value = val;
		left = NULL;
		right = NULL;
	}

	BST& insert(int newval) {
		BST* currentNode = this;
		while (true) {
			if (newval < currentNode->value) {
				//explore left sub-tree
				if (currentNode->left == NULL) {
					//end of BST, inserting value here
					BST* newNode = new BST(newval);
					currentNode->left = newNode;
					break;
				}
				else {
					//going layer down
					currentNode = currentNode->left;
				}
			}
			else {
				//going right for new >= current
				//explore left sub-tree
				if (currentNode->right == NULL) {
					//end of BST, inserting value here
					BST* newNode = new BST(newval);
					currentNode->right = newNode;
					break;
				}
				else {
					//going layer down
					currentNode = currentNode->right;
				}
			}
		}
		return *this;
	}

	bool search(int val) {
		BST* currentNode = this;
		while (true) {
			if (val > currentNode->value) {
				currentNode = currentNode->right;
			}
			else if(val < currentNode->value) {
				currentNode = currentNode->left;
			}
			else //value is found
				return true;
		}
		return false;
	}

	BST& remove(int val, BST * parentNode = NULL) {
		BST* currentNode = this;
		while (true) { //find the node
			if (val > currentNode->value) {
				currentNode = currentNode->right;
			}
			else if(val < currentNode->value) {
				currentNode = currentNode->left;
			}
			else {//value is found
				//node is leaf, one-legged,or full sub-tree
				if (currentNode->right != NULL && currentNode->left != NULL) {
					currentNode->value = currentNode->right->getMinValue();
					currentNode->right->remove(currentNode->value, currentNode);
				}
//TODO copy the rest from https://medium.com/@13dipty/binary-search-tree-implementation-in-c-537b9a9cedf8
				else if (parentNode == NULL) {

				}
				else if (parentNode->left == currentNode) {

				}
				else if (parentNode->right == currentNode) {

				}

			}
		}
		return *this;
	}

	int getMinValue() {
		BST* currentNode = this;
		while (currentNode->left != NULL) {
			currentNode = currentNode->left;
		}
		return currentNode->value;
	}

	void printLeafNodes(void) {
		printLeafNodes(this);
		std::cout << std::endl;
	}

	void printLevelOrder() {
		BST* root = this;
		int tree_hight = hight(root);
		std::cout << "tree hight: " << tree_hight << std::endl;
		/*for (int level = 0; level < tree_hight; ++level) {
			printGivenLevel(root, level);
		}*/
		std::cout << std::endl;
	}

private:
	void printLeafNodes(BST *node) {
		if (node == NULL)
			return;
		if (node->right == NULL && node->left == NULL) {
			std::cout << node->value << " ";
		}
		printLeafNodes(node->left);
		printLeafNodes(node->right);
	}

	int hight(BST* node) {
		int res = 0;
		if (node == NULL) {
			res = 0;
		}
		else {
			int lhight = hight(node->left);
			std::cout << "node val: " << node->value << " lhight here: " << lhight << std::endl;
			int rhight = hight(node->right);
			std::cout << "node val: " << node->value << " rhight here: " << rhight << std::endl;

			if (lhight > rhight) {
				res = lhight + 1;
			} 
			else {
				res = rhight + 1;
			}
		}
		std::cout << "node val: " << node->value << " hight here: " << res << std::endl;
		return res;
	}

	void printGivenLevel(BST* node, int level) {
		if (node == NULL)
			return;
		if (level == 1) {
			std::cout << node->value << " ";
		}
		else if(level > 1) {
			printGivenLevel(node->left, level - 1);
			printGivenLevel(node->right, level - 1);
		}
	}

};