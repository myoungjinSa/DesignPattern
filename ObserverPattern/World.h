#pragma once
#include "Observer.h"

class CWorld :
	public CSingleton<CWorld>
{
public:
	CWorld() {}
	~CWorld() {}

	// Construct and Destruct
	virtual void NativeConstruct() override;
	virtual void NativeDestuct() override;

	void Tick() override;
	// Subscriber 
	//virtual void Subscribe() override;
	//virtual void Unsubscribe() override;

};
