#pragma once
#include "singletonBase.h"
#include <vector>

struct tagIniData
{
	const char* subject;	//����
	const char* title;		//����
	const char* body;		//100
};

class iniDataManager : public singletonBase<iniDataManager>
{
private:
	typedef vector<tagIniData>				arrIniData;
	typedef vector<tagIniData>::iterator	arrIniDataIter;

	typedef vector<arrIniData>				arrIniDatas;
	typedef vector<arrIniData>::iterator	arrIniDatasIter;

private:
	arrIniDatas _vIniData;

	iniDataManager();
	~iniDataManager();

	friend singletonBase;

public:

	HRESULT init();
	void release();

	void addData(const char* subject, const char* title, const char* body);
	void iniSave(const char* fileName);

	char* loadDataString(const char* fileName, const char* subject, const char* title);

	int loadDataInterger(const char* fileName, const char* subject, const char* title);

};

