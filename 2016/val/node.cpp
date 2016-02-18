#include "node.h"

Node::Node(void) {
	this->x = 0;
	this->y = 0;
	this->type = WAREHOUSE;
}

Node::Node(Node *node) {
	this->x = node->x;
	this->y = node->y;
	this->type = node->type;
}

Node::~Node(void) {

}
