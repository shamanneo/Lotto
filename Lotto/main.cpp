#include <iostream>
#include "Lotto.h"

// draw
// show
// stat
// exit

int main()
{
	{
	CLotto lotto ;
	int nCont = 0 ; 
	while(nCont != 10) 
	{
		std::cin >> nCont ; 
		switch(nCont)
		{
			case 1 :
			{
				lotto.draw() ;
				break ; 
			}
			case 2 :
			{
				int i = 0 ;
				std::cin >> i ; 
				lotto.show(i) ;
				break ; 
			}
			case 3 :
			{
				lotto.stat() ;
				break ; 
			}
			default :
			{
				break ; 
			}
		}
	}
	}
	_CrtDumpMemoryLeaks() ; 
	return 0 ;
}