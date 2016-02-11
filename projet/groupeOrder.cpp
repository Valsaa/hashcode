#include "hashcode.h"

int getTotalWeight(Command *command);
Command* getNextFreeOrder(vector<Command*> *_listCmd, int ind);
int euclidien(Command *command);

void groupOrder(DataObject *data) {
	for(int i = 0 ; i < NBORDER ; i++) {
		int maxload = MAXLOAD;
		Command *command = data->_listCmd->at(i);
		if(command->_groupid == -1) {
			data->_group->push_back(new Grp());
			command->_groupid = data->_group->size();
		}
		Command *next = getNextFreeOrder(data->_listCmd, i);
		maxload -= getTotalWeight(next);
		if(maxload >= 0) {
			data->_group->at(command->_groupid)->_cmd->push_back(next);		
			next->_groupid = command->_groupid;
		}		
	}
}

Command* getNextFreeOrder(vector<Command*> *_listCmd, int ind) {
	
	Command *now = _listCmd->at(ind);
	int dist_min = 0;
	bool debut = true;
	Command *next = NULL;
	for(int i = 0 ; i < _listCmd->size() ; i++) {
		if(debut) {
			dist_min = euclidien(_listCmd->at(ind));
		}
		if(euclidien(_listCmd->at(i)) < dist_min) {
			next = _listCmd->at(i);
		}
	}

	return next;
}

int euclidien(Command *command) {
	return floor(sqrt(command->_positionX * command->_positionX + command->_positionY * command->_positionY));

}

int getTotalWeight(Command *command) {
	int weight = 0;

	for(int i = 0 ; i < command->listProduct.size() ; i++) {
		weight += command->listProduct.at(i);
	}

	return weight;
}
