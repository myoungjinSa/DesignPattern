#pragma once
#include "Singleton.h"

enum class EObserverContent
{
	World,
	Max,
};

class CWorld;

class CObserver
	: public CSingleton<typename CObserver>
{
public:
	CObserver() {}
	~CObserver() {}

	// Construct and Destruct
	virtual void NativeConstruct() override;
	virtual void NativeDestuct() override;

	virtual	void Tick() override;

	// Subscriber 
	//virtual void Subscribe();
	//virtual void Unsubscribe();

private:
	void InitObserverMember();
	void DestroyObserverMember();

	CObserver* GetObserver(EObserverContent InObserverContent);
	CWorld* GetWorld();


	std::vector<CObserver*> Observers;
};
