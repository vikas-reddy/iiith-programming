#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	public:
		int info;
		node *next;
		node *prev;

		node(int val)
		{
			info = val;
			prev = NULL;
			next = NULL;
		}

};

class DoubleLL
{
	public:
		node *head;
		node *tail;

		DoubleLL()
		{
			head = NULL;
			tail = NULL;
		}

		void insert(int value)
		{
			node *NewNode;
			NewNode = new node(value);
			//NewNode->info = value;

			if(!head)
			{
				head = NewNode;
				tail = NewNode;
				return;
			}

			NewNode->next = head;
			head->prev = NewNode;
			head = NewNode;
			return;
		}
		
        bool delete_node(int value)
        {
            if(!head)
                return false;

            node *temp = head;
            for( ;(temp) && (temp->info != value); temp=temp->next);
            
            if(!temp)
                return false;

            if(temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if(temp->next)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev;

            delete temp;
            return true;
        }

		void print_start()
		{
            if(!head)
                return;

			node *temp = head;
			for(   ;temp; temp=temp->next)
				cout << temp->info << " ";
			cout << endl;
			return;
		}
		void print_end()
		{
            if(!tail)
                return;

			node *temp = tail;
			for(   ;temp; temp=temp->prev)
				cout << temp->info << " ";
			cout << endl;
			return;
		}

		void reverse()
		{
			if(!head->next)
				return;

			node *cur = head->next, *NewHead = NULL, *NewTail = NULL;

			tail = head;
			while(cur)
			{
				head->next = NewHead;

				if(NewHead)
					NewHead->prev = head;

				NewHead = head;

				cur->prev = NULL;

				head = cur;
				cur = head->next;

			}

			head->next = NewHead;
			NewHead->prev = head;
			return;
		}

		node* recursive_reverse(node* root)
		{
			if(!root || !root->next)
				return root;

			node* temp = recursive_reverse(root->next);

			root->next->next = root;
			root->prev = root->next;
			root->next = NULL;
			tail = root;

			temp->prev = NULL;
			return temp;
		}


};


int main()
{
	DoubleLL List;

	for(int i=0; i<15; List.insert(rand()%1000), i++);

	List.print_start();
	//List.head = List.recursive_reverse(List.head);
	//List.print_end();

    int val=0;
    cout << "Enter the node to be deleted: ";
    cin >> val;

    List.delete_node(val);
    List.print_start();
    List.print_end();

	return 0;
}
