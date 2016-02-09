#include "server.h" 

Server::Server() {

}

Server::Server(int ca, int si, int po) {
	_capacite = ca;
	_size = si;
	_pool = po;
	_r = 0;
	_s = 0;
}

