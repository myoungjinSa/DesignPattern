#pragma once
#include "Singleton.h"

class CNewDynamicObject :
	public CNewDynamicAllocSingleton<CNewDynamicObject>
{
public:
	CNewDynamicObject() {}
	~CNewDynamicObject()
	{
		std::cout << "~CNewDynamicObject has been called \n";
	}
};

