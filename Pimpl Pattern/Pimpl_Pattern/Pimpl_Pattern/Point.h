#pragma once
#include <iostream>
class PointImpl;			//������ ������ ��� �����ʹ� ����
class Point
{
	std::shared_ptr<PointImpl> pImpl;
public:
	Point();		//��� ���� �����ͷ� ���� �ִٸ� ��� ���� ��ſ� ���漱�� ���ָ� �ȴ�
	void print();
};

