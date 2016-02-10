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

void Server::affiche(void) {
	printf("server %d : taille = %d - capa = %d - pool = %d - pos : [%d][%d] ;\n",_id, _size ,_capacite, _pool, _r, _s);
}
