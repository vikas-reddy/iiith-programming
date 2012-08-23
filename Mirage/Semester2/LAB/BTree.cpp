#include <iostream>
using namespace std;

class BTNode
{
	public:
		int num_keys;
		int *key;
		BTNode *ptr;

		BTNode(int order)
		{
			num_keys = 0;
			key = new int[ 2 * order ];
			ptr = new BTNode[ 2 * order + 1 ];
		}
};

class BTree
{
	private:
		BTNode *root;
	public:
		void insert(int num);
};


