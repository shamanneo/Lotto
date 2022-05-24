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
	int i = 0 ;
	while(nCont != 4) 
	{
		std::cout << "1 : Draw, 2 : Show, 3 : Stat, 4 : Exit. Enter your input -> " ; 
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
				std::cout << "Your input is Show function, Enter your parameter N -> " ; 
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