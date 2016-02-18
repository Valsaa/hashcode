#ifndef NODE_H
#define NODE_H

typedef enum {WAREHOUSE, ORDER} Type;

class Node {

	public :
		Node(void);
		Node(Node *node);
		~Node(void);

		int x;
		int y;
		Type type;
};

#endif // NODE_H
