#include "Lotto.h"

static void Swap(int &a, int &b)
{
	int temp = a ; 
	a = b ;
	b = temp ; 
}

static void Sort(std::vector<int> &numbers)
{
	const size_t nSize = numbers.size() - 2 ; // The last element is bonus number that is not contained.
	for(int x = 0 ; x < nSize ; x++)
	{
		for(int y = 0 ; y < nSize - 1 - x ; y++)
		{
			if(numbers[y] > numbers[y + 1])
			{
				::Swap(numbers[y], numbers[y + 1]) ; // Call by reference.
			}
		}
	}
}

CLotto::CLotto() 
{
	nCount = 0 ; 
	::memset(m_hTables, 0, sizeof(m_hTables)) ; 
}

CLotto::~CLotto() 
{
	while(!m_cache.empty())
	{
		delete *m_cache.begin() ;
		m_cache.erase(m_cache.begin()) ; 
	}
}

void CLotto::Save(std::vector<int> *numbers) 
{
	if(IsMax())
	{
		delete *m_cache.begin() ;
		m_cache.erase(m_cache.begin()) ; 
	}
	m_cache.emplace_back(numbers) ; 
}

void CLotto::draw()
{
	int n = 0 ;
	std::vector<int> *pNumbers = new std::vector<int> ; 
	std::random_device rd ; 
	std::mt19937 gen(rd()) ; 
	std::uniform_int_distribution<int> dis { 1, 45 } ; 
	for(int i = 0 ; i < 7 ; i++)
	{
		n = dis(gen) ; // Get random number.
		pNumbers->push_back(n) ; 
		m_hTables[n]++ ; 
	}
	::Sort(*pNumbers) ; 
	Save(pNumbers) ; 
	nCount++ ; 
}

void CLotto::show(int n) 
{
	int tempCount = n ;
	std::vector<int> tempNumbers ;
	if(n > MAX_CACHE_SIZE) return ; 
	for(auto ri = m_cache.rbegin() ; ri != m_cache.rend() ; ri++, tempCount--)
	{
		//		= cache =
		if(tempCount == 0) return ; 
		tempNumbers = **ri ; 
		std::cout << tempNumbers[0] << " " << tempNumbers[1] << " " << tempNumbers[2] << " " 
				  << tempNumbers[3] << " " << tempNumbers[4] << " " << tempNumbers[5] << '\n' ; 
	}
}

void CLotto::stat() 
{
	for(int idx = 1 ; idx <= RANGE_SIZE ; idx++)
	{
		const float value = static_cast<float>(m_hTables[idx]) ; 
		const float rangeSize = 45.0f ; 
		std::cout << std::fixed ; 
		std::cout.precision(7) ;
		std::cout << " Frequency of " << idx << " : " << (value / (rangeSize * nCount)) * 100 << "%\n" ; 
	}
}

