#ifndef SERVER_H 
#define SERVER_H

#include <iostream>
#include <cstdio>

class Server {

	public :
		int _capacite;
		int _size;
		int _pool;
		int _r;
		int _s;
		
		Server(int ca, int si, int po);
		Server();
		
};

#endif // SERVER_H 
