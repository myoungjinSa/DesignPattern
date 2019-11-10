#include "ProjectHeader.h"

void InitInstance();
void DestroyInstance();

int main()
{
	InitInstance();

	while (true)
	{
		GetObserver()->Tick();
	}

	DestroyInstance();
}

void InitInstance()
{
	GetObserver()->NativeConstruct();
}

void DestroyInstance()
{
	GetObserver()->NativeDestuct();
}
