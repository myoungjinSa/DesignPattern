#pragma once
#include "Includer.h"

//////////////////////////////////////////////////////////////////////////
// �����Ҵ� �̱���
// ���� �̱����� Destroy �Լ��� �ҷ��� �����Ҵ��� �����ؾ��ϴ� ���ŷο��� �ִ�. 
// * new �� ������ ��ü�̱⶧���� �ڵ����� �Ҹ��ڸ� �ҷ����� �ʴ´�. 
//////////////////////////////////////////////////////////////////////////
template<typename T>
class CDynamicAllocSingleton
{
public:
	CDynamicAllocSingleton() {}
	virtual ~CDynamicAllocSingleton()
	{
		std::cout << "~CDynamicAllocSingleton has been called \n";
	}

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
		std::cout << "~CDynamicAllocSingleton has been called \n";
		if (Instance)
		{
			delete Instance;
		}
	}

private:
	static T* Instance;
};

template<typename T>
T* CDynamicAllocSingleton<T>::Instance = nullptr;

//////////////////////////////////////////////////////////////////////////
// ������ ������ �̱���
// �Ҹ��ڰ� �Ҹ��鼭 �ش� ��ü�� �˾Ƽ� ������� (scope ���� ��� ��ü�� ������� ��)
//////////////////////////////////////////////////////////////////////////
template<typename T>
class CNonDynamicAllocSingleton
{
public:
	CNonDynamicAllocSingleton() {}
	~CNonDynamicAllocSingleton()
	{
		std::cout << "~CNonDynamicAllocSingleton has been called \n";
	}

	static T* Get()
	{
		return &Instance;
	}

private:
	static T Instance;
};

template<typename T>
T CNonDynamicAllocSingleton<T>::Instance;

//////////////////////////////////////////////////////////////////////////
// C++����� �����Ҵ� �̱���
// ���� �̱����� Destroy �Լ��� �ҷ��� �����Ҵ��� �����ؾ��ϴ� ���ŷο��� �ִ�. 
// * new �� ������ ��ü�̱⶧���� �ڵ����� �Ҹ��ڸ� �ҷ����� �ʴ´�. 
//////////////////////////////////////////////////////////////////////////
template<typename T>
class CNewDynamicAllocSingleton
{
public:
	CNewDynamicAllocSingleton() {}
	virtual ~CNewDynamicAllocSingleton()
	{
		std::cout << "~CNewDynamicAllocSingleton has been called \n";
	}

	static T* Get()
	{
		static T* Instance = new T;
		return Instance;
	}

	static void Destroy()
	{
		T* Instance = CNewDynamicAllocSingleton::Get();
		delete Instance;
	}
};