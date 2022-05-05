#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <utility>

using namespace std;

template<class Key, class T>
class Container{
private:
	pair<Key, T> *aptr;
	int num;
	int allocated_size;

public:
	Container();
	Container(int);
	bool push_back(Key, T);
	int size();
	int max_size();
	T data(int);
	Key key(int);
	bool retrieve_by_key(Key, T);
	T& operator[](int);
	virtual ~Container();
};

#endif /* CONTAINER_H_ */
