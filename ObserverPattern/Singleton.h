#pragma once
#include "Object.h"

template <typename T>
class CSingleton : 
	public CObject
{
public:
	CSingleton() {}
	~CSingleton() {}

	static T* Get()
	{
		if (!Instance)
		{
			Instance = new T;
		}

		return Instance;
	}

	static void Destroy()
	{
		if (Instance)
		{
			delete Instance;
		}
		else
		{
			// Gunny Todo. JsonLog
			// Can be added by NUGET?
			std::cout << "Instance does not exist." << std::endl;
		}
	}

private:
	static T* Instance;
};

template <typename T>
T* CSingleton<T>::Instance = nullptr;
