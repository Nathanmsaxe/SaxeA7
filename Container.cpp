#include "Container.h"
#include <iostream>
#include <climits>
#include <exception>
#include <utility>
using namespace std;


template<class Key, class T>
Container<Key,T>::Container(){
	this->aptr = NULL;
	this->num = 0;
	this->allocated_size = 0;

}
template<class Key, class T>
Container<Key,T>::Container(const int number){
	aptr = new pair<Key, T>[number];
	this->allocated_size = number;
	this->num = 0;


}
template<class Key, class T>
int Container<Key,T>::push_back(Key keytype, T data){
	bool s = true;

	if(num<allocated_size){
		this->aptr[this->num] = make_pair(keytype, data);
		this->num++;
	}
	else{
		cout << "ERROR: Memory not allocated" << endl;
		string f = "ERROR";
		throw(f);
		s = false;
	}
	return s;
}
template<class Key, class T>
int Container<Key,T>::size(){
	return num;
}
template<class Key, class T>
int Container<Key,T>::max_size(){
	return allocated_size;
}
template<class Key, class T>
T Container<Key,T>::data(int n){
	return get<1>(aptr[n]);
}
template<class Key, class T>
Key Container<Key,T>::key(int n){
	return get<0>(aptr[n]);
}
template<class Key, class T>
bool Container<Key,T>::retrieve_by_key(Key keyName, T data){
	for(int i = 0; i < num; i++){
		if(get<1>(aptr[i]) == data){
			if(get<0>(aptr[i]) == keyName){
				return true;
			}
		}
	}
	return false;
}
template<class Key, class T>
T& Container<Key,T>::operator[](int n){
	try{
		return this->aptr[n].second;
	}
	catch(string&){
		cout << "ERROR: space is not allocated";
	}
}
template<class Key, class T>
Container<Key,T>::~Container(){
	delete[] aptr;
}
