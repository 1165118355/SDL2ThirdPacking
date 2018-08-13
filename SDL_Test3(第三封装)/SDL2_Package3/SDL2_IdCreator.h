///////////////////////////////
//	this class is a idCreator in SDL2.
//	��������id�ͻ���id
//	��id�ࡷ
//	2018��8��13�� 20:07:34
//	by	ˮ������

#ifndef _SDL2_IDCREATOR_H_BOX
#define _SDL2_IDCREATOR_H_BOX

#include <vector>
#include <unordered_set>

class SDL2_IdCreator
{
public:
	static SDL2_IdCreator *get();

	///	brief	����һ��id
	int createId();

	///	brief	�Ƴ�һ��id
	int removeId(int id);
private:
	SDL2_IdCreator();
	~SDL2_IdCreator();
private:
	static SDL2_IdCreator *m_IdCreator;
	//std::vector<int> m_Ids;
	std::unordered_set<int> m_Ids;
};

#endif // !_SDL2_IDCREATOR_H_BOX
