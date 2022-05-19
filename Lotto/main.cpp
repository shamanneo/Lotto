#include "Lotto.h"

// draw
// show
// stat
// exit

int main()
{
	{
	CLotto lotto ;
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 
	lotto.draw() ; 

	lotto.show(6) ; 
	lotto.stat() ; 
	}
	_CrtDumpMemoryLeaks() ; 
	return 0 ;
}