#include "Lotto.h"

static void Swap(int &a, int &b)
{
	int temp = a ; 
	a = b ;
	b = temp ; 
}

static void Sort(std::vector<int> &numbers)
{
	const size_t size = numbers.size() - 1 ; // The last element is bonus number that is not contained.
	for(int x = 0 ; x < size ; x++)
	{
		for(int y = 0 ; y < size - 1 - x ; y++)
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
	this->m_count = 0 ; 
	::memset(this->m_countTable, 0, sizeof(this->m_countTable)) ; 
}

CLotto::~CLotto() 
{
	while(!this->m_cache.empty())
	{
		delete *this->m_cache.begin() ;
		m_cache.erase(this->m_cache.begin()) ; 
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
	int rn = 0 ;
	int tempCount = 7 ; 
	bool duplTable[RANGE_SIZE + 1] { false } ;  // Variable to check whether the given random number is duplicated.
	std::vector<int> *pNumbers = new std::vector<int> ; // Dynamic allocation. It should be elements.
	std::random_device rd ; 
	std::mt19937 gen(rd()) ; 
	std::uniform_int_distribution<int> dis { 1, 45 } ; 
	while(tempCount--)
	{
		rn = dis(gen) ; // Get random number.
		if(duplTable[rn] == true) // No duplicate.
		{
			tempCount++ ; 
			continue ; 
		}
		pNumbers->push_back(rn) ; 
		duplTable[rn] = true ; 
		m_countTable[rn]++ ; 
	}
	::Sort(*pNumbers) ; 
	Save(pNumbers) ; 
	//		sample
	std::vector<int> tempNumbers = *pNumbers ; 
	std::cout << tempNumbers[0] << " " << tempNumbers[1] << " " << tempNumbers[2] << " " 
			  << tempNumbers[3] << " " << tempNumbers[4] << " " << tempNumbers[5] << " | " << tempNumbers[6] << '\n' ; 
	//
	m_count++ ; 
}

void CLotto::show(int n) 
{
	int tempCount = n ;
	if(tempCount == 0) tempCount = 1 ; // If Show(0) -> Show the most recent one.
	std::vector<int> tempNumbers ;
	if(n > MAX_CACHE_SIZE) return ; // Out of range.
	for(auto ri = m_cache.rbegin() ; ri != m_cache.rend() ; ri++, tempCount--)
	{
		//		cache 
		if(tempCount == 0) return ; // Base case.
		tempNumbers = **ri ; 
		std::cout << tempNumbers[0] << " " << tempNumbers[1] << " " << tempNumbers[2] << " " 
				  << tempNumbers[3] << " " << tempNumbers[4] << " " << tempNumbers[5] << " | " << tempNumbers[6] << '\n' ; 
	}
}

void CLotto::stat() 
{
	for(int idx = 1 ; idx <= RANGE_SIZE ; idx++)
	{
		float prob ;
		const float value = static_cast<float>(m_countTable[idx]) ; 
		const float rangeSize = 45.0f ; 
		std::cout << std::fixed ; 
		std::cout.precision(7) ;
		if(m_count == 0) // If m_nCount is zero, prov value is not defined.
		{
			prob = 0 ; 
		}
		else 
		{
			prob = (value / (rangeSize * m_count)) * 100 ; 
		}
		std::cout << " Frequency of " << idx << " : " << prob << "%\n" ; 
	}
}

