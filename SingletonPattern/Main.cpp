#include "DynamicObejct.h"
#include "NonDynamicObject.h"
#include "NewDynamicObject.h"

int main()
{
	CDynamicObject* DynamicObject = CDynamicObject::Get();
	CNonDynamicObject* NonDynamicObject = CNonDynamicObject::Get();
	CNewDynamicObject* NewDynamicObject = CNewDynamicObject::Get();
	
	// DynamicObject should call a CDynamicAllocSingleton::Destroy
	DynamicObject->Destroy();
	DynamicObject = nullptr;

	// NewDynamicObject should call a CNewDynamicAllocSingleton::Destroy
	NewDynamicObject->Destroy();
	NewDynamicObject = nullptr;
}