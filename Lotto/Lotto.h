#pragma once
#include <iostream>
#include <algorithm>
#include <random>

const int RANGE_SIZE = 45 ; 
const int MAX_CACHE_SIZE = 10 ;

class CLotto
{ 
	private :
		int nCount ;
		std::vector<std::vector<int> *> m_cache ; // Variable to show previous records.
		int m_hTables[RANGE_SIZE + 1] ; // Variable to caluclate stat().
	protected :
		void Save(std::vector<int> *numbers) ; // Insert data to cache.
		bool IsMax() ; // Determine whether cashe size is over than 10? -> erase the oldest data in containers.
	public :
		CLotto() ; 
		~CLotto() ; 
	public :
		void draw() ;
		void show(int n) ; 
		void stat() ; 
} ; 

inline bool CLotto::IsMax()
{
	return(m_cache.size() == MAX_CACHE_SIZE) ;
}


