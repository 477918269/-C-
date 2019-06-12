
//hash_shm.h
#ifndef _STORMLI_HASH_SHM_H_
#define _STORMLI_HASH_SHM_H_

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<sys/shm.h>
using namespace std;

template<typename valueType, unsigned long maxLine, int lines>
class hash_shm
{
public:
	int find(unsigned long _key);    //if _key in the table,return 0,and set lastFound the position,otherwise return -1
	int remove(unsigned long _key);    //if _key not in the table,return-1,else remove the node,set the node key 0 and return 0

	//insert node into the table,if the _key exists,return 1,if insert success,return 0;and if fail return -1
	int insert(unsigned long _key, const valueType &_value);
	void clear();        //remove all the data

public:    //some statistic function
	double getFullRate()const;        //the rate of the space used

public:
	//constructor,with the share memory start position and the space size,if the space is not enough,the program will exit
	hash_shm(void *startShm, unsigned long shmSize = sizeof(hash_node)*maxLine*lines);

	//constructor,with the share memory key,it will get share memory,if fail,exit
	hash_shm(key_t shm_key);
	~hash_shm(){}    //destroy the class
private:
	void *mem;        //the start position of the share memory  // the mem+memSize  space used to storage the runtime data:currentSize
	unsigned long memSize;    //the size of the share memory
	unsigned long modTable[lines];    //modtable,the largest primes
	unsigned long maxSize;        //the size of the table
	unsigned long *currentSize;    //current size of the table ,the pointer of the shm mem+memSize
	void *lastFound;        //write by the find function,record the last find place

	struct hash_node{        //the node of the hash table
		unsigned long key;    //when key==0,the node is empty
		valueType value;    //name-value pair
	};
private:
	bool getShm(key_t shm_key);    //get share memory,used by the constructor
	void getMode();        //get the largest primes blow maxLine,use by the constructor
	void *getPos(unsigned int _row, unsigned long _col);//get the positon with the (row,col)
};

template<typename vT, unsigned long maxLine, int lines>
hash_shm<vT, maxLine, lines>::hash_shm(void *startShm, unsigned long shmSize)
{
	if (startShm != NULL){
		cerr << "Argument error\n Please check the shm address\n";
		exit(-1);
	}
	getMode();
	maxSize = 0;
	int i;
	for (i = 0; i<lines; i++)    //count the maxSize
		maxSize += modTable[i];
	if (shmSize<sizeof(hash_node)*(maxSize + 1)){    //check the share memory size
		cerr << "Not enough share memory space\n";
		exit(-1);
	}
	memSize = shmSize;
	if (*(currentSize = (unsigned long *)((long)mem + memSize))<0)
		*currentSize = 0;;
}

template<typename vT, unsigned long maxLine, int lines>
hash_shm<vT, maxLine, lines>::hash_shm(key_t shm_key)
{    //constructor with get share memory
	getMode();
	maxSize = 0;
	for (int i = 0; i<lines; i++)
		maxSize += modTable[i];
	memSize = sizeof(hash_node)*maxSize;
	if (!getShm(shm_key)){
		exit(-1);
	}
	//    memset(mem,0,memSize);
	if (*(currentSize = (unsigned long *)((long)mem + memSize))<0)
		*currentSize = 0;
}


template<typename vT, unsigned long maxLine, int lines>
int hash_shm<vT, maxLine, lines>::find(unsigned long _key)
{
	unsigned long hash;
	hash_node *pH = NULL;
	for (int i = 0; i<lines; i++)
	{
		hash = (_key + maxLine) % modTable[i];    //calculate the col position
		pH = (hash_node *)getPos(i, hash);
		//        if(pH==NULL)return -2;    //almost not need
		if (pH->key == _key){
			lastFound = pH;
			return 0;
		}
	}
	return -1;
}

template<typename vT, unsigned long maxLine, int lines>
int hash_shm<vT, maxLine, lines>::remove(unsigned long _key)
{
	if (find(_key) == -1)return -1;    //not found
	hash_node *pH = (hash_node *)lastFound;
	pH->key = 0;        //only set the key 0
	(*currentSize)--;
	return 0;
}

template<typename vT, unsigned long maxLine, int lines>
int hash_shm<vT, maxLine, lines>::insert(unsigned long _key, const vT &_value)
{
	if (find(_key) == 0)return 1;    //if the key exists
	unsigned long hash;
	hash_node *pH = NULL;
	for (int i = 0; i<lines; i++){
		hash = (_key + maxLine) % modTable[i];
		pH = (hash_node *)getPos(i, hash);
		if (pH->key == 0){        //find the insert position,insert the value
			pH->key = _key;
			pH->value = _value;
			(*currentSize)++;
			return 0;
		}
	}
	return -1;    //all the appropriate position filled
}


template<typename vT, unsigned long maxLine, int lines>
void hash_shm<vT, maxLine, lines>::clear()
{
	memset(mem, 0, memSize);
	*currentSize = 0;
}


template<typename vT, unsigned long maxLine, int lines>
bool hash_shm<vT, maxLine, lines>::getShm(key_t shm_key)
{
	int shm_id = shmget(shm_key, memSize, 0666);
	if (shm_id == -1)    //check if the shm exists
	{
		shm_id = shmget(shm_key, memSize, 0666 | IPC_CREAT);//create the shm
		if (shm_id == -1){
			cerr << "Share memory get failed\n";
			return false;
		}
	}
	mem = shmat(shm_id, NULL, 0);    //mount the shm
	if (int(mem) == -1){
		cerr << "shmat system call failed\n";
		return false;
	}
	return true;
}

template<typename vT, unsigned long maxLine, int lines>
void hash_shm<vT, maxLine, lines>::getMode()
{        //���� 6n+1 6n-1 ��������ԭ��
	if (maxLine<5){ exit(-1); }

	unsigned long t, m, n, p;
	int i, j, a, b, k;
	int z = 0;

	for (t = maxLine / 6; t >= 0, z<lines; t--)
	{
		i = 1; j = 1; k = t % 10;
		m = 6 * t;                                        /**i,j��ֵ ���Ƿ������֤�ı�־Ҳ�Ƕ�Ӧ��6t-1��6t+1�����Ա�־**/
		if (((k - 4) == 0) || ((k - 9) == 0) || ((m + 1) % 3 == 0))j = 0;/*�˴��Ǽ���֤6*t-1,6*t+1 �ǲ������������������������**/
		if (((k - 6) == 0) || ((m - 1) % 3 == 0))i = 0;            /***��ͨ�������ж�ȥ��ĩβ��5������3��������***/
		for (p = 1; p * 6 <= sqrt(m + 1) + 2; p++)
		{
			n = p * 6;                                    /**��6*p-1��6*p+1����α�������Գ�*****/
			k = p % 10;
			a = 1; b = 1;                                /**ͬ���˴�a,b��ֵҲ�������жϳ����Ƿ�Ϊ������߳�������������**/
			if (((k - 4) == 0) || ((k - 9) == 0))a = 0;
			if (((k - 6) == 0))b = 0;
			if (i){                            /*���i����Ͷ�m-1����ν6*t-1������֤����Ȼ��Ҫ������n+1,n-1,���Դ���*/
				if (a){ if ((m - 1) % (n + 1) == 0)i = 0; }        /***һ����������˵����������������Ϊ�㼴��i ��ֵΪ��***/
				if (b){ if ((m - 1) % (n - 1) == 0)i = 0; }
			}
			if (j){                           /**���j����Ͷ�m+1����ν6*t+1������֤����Ȼ��Ҫ������n+1,n-1,���Դ���*/
				if (a){ if ((m + 1) % (n + 1) == 0)j = 0; }         /***һ����������˵����������������Ϊ�㼴��j ��ֵΪ��***/
				if (b){ if ((m + 1) % (n - 1) == 0)j = 0; }
			}
			if ((i + j) == 0)break;                     /**����Ѿ�֪��6*t-1,6*t+1�������������Ǿͽ����Գ�ѭ��***/
		}
		if (j){ modTable[z++] = m + 1; if (z >= lines)return; }
		if (i){ modTable[z++] = m - 1; if (z >= lines)return; }
	}
}

template<typename vT, unsigned long maxLine, int lines>
void *hash_shm<vT, maxLine, lines>::getPos(unsigned int _row, unsigned long _col)
{
	unsigned long pos = 0UL;
	for (int i = 0; i<_row; i++)    //calculate the positon from the start
		pos += modTable[i];
	pos += _col;
	if (pos >= maxSize)return NULL;
	return (void *)((long)mem + pos*sizeof(hash_node));
}

template<typename vT, unsigned long maxLine, int lines>
double hash_shm<vT, maxLine, lines>::getFullRate()const
{
	return double(*currentSize) / maxSize;
}


#endif