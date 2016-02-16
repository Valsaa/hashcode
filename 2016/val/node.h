#ifndef NODE_H
#define NODE_H

class Node {

	public :
		Node(void);
		Node(Node *node);
		~Node(void);

		int x;
		int y;
};

#endif // NODE_H
