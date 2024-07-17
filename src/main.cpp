#include "pch.h"
#include "include\menu.h"

using namespace std;

int main()
{
	BOOST_LOG_TRIVIAL(info) << "Boost Log initialized!";

	Menu menu;
	menu.MenuLoop();
	return 0;
	
}
