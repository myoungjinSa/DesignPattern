#include "Observer.h"

//////////////////////////////////////////////////////////////////////////
// Observer content
#include "World.h"
//////////////////////////////////////////////////////////////////////////

void CObserver::NativeConstruct()
{
	InitObserverMember();
}

void CObserver::NativeDestuct()
{
	DestroyObserverMember();
}

void CObserver::Tick()
{
	GetWorld()->Tick();
}

void CObserver::InitObserverMember()
{
	// Set Observers size
	Observers.reserve(static_cast<size_t>(EObserverContent::Max));

	// Max has no content
	for (int i = 0; i < static_cast<int>(EObserverContent::Max); ++i)
	{
		Observers.push_back(GetObserver(EObserverContent(i)));
	}

}

void CObserver::DestroyObserverMember()
{
	for (CObserver* Observer : Observers)
	{
		delete Observer;
	}

	if (!Observers.empty())
	{
		std::cout << "CObserver::DestroyObserverMember - Observers empty fail.";
		return;
	}
}

CObserver* CObserver::GetObserver(EObserverContent InObserverContent)
{
	switch (InObserverContent)
	{
		case EObserverContent::World:
			return reinterpret_cast<CObserver*>(CWorld::Get());
		case EObserverContent::Max:
			std::cout << "CObserver::GetObserver - you inputs EObserverContent::Max";
			return nullptr;
	}

	return nullptr;
}

CWorld* CObserver::GetWorld()
{
	return CWorld::Get();
}
