///////////////////////////////
//	this class is a idCreator in SDL2.
//	用来创建id和回收id
//	《id类》
//	2018年8月13日 20:07:34
//	by	水华宝箱

#ifndef _SDL2_IDCREATOR_H_BOX
#define _SDL2_IDCREATOR_H_BOX

#include <vector>
#include <unordered_set>

class SDL2_IdCreator
{
public:
	static SDL2_IdCreator *get();

	///	brief	创建一个id
	int createId();

	///	brief	移除一个id
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
