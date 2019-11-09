#pragma once

#include "Singleton.h"
#include "Observer.h"

CObserver* GetObserver()
{
	return CObserver::Get();
}
