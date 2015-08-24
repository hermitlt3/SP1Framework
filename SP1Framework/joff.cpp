    
#include "jofff.h"
#include "Framework\console.h"

void joff();

void joff()
{
	string jtk;
ifstream swaggy;

   swaggy.open("joff3.nfo");
      if(swaggy.is_open())
    {
        while(getline(swaggy,jtk))
		{	
			colour(0xFC);
            cout << jtk;
        }
         swaggy.close();
    }
}
