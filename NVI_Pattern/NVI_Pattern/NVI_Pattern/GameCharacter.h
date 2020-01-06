#pragma once
class GameCharacter{
	

public:
	GameCharacter();
	virtual ~GameCharacter();

	void Control();			

	void DoPreWork();		//���� ������ ���� -- �θ� Ŭ�������� ���� ������ ����
	void DoPostWork();		//���� ������ ���� -- �θ� Ŭ�������� ���� ������ ����


private:

	virtual void DoSkill()const = 0;		//�ڽ� Ŭ�������� ������ ����

};