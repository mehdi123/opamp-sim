// DataClasses.h: interface for the CNewValues class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATACLASSES_H__0F2662D9_FE85_4796_9C37_BBBCA3D7130E__INCLUDED_)
#define AFX_DATACLASSES_H__0F2662D9_FE85_4796_9C37_BBBCA3D7130E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define BMY		187
#define BMXINV  269
#define BMXNON  326

class CNewValues  
{
public:
	CNewValues();
	~CNewValues();
	double	gain;
	float	inpr;
	float	max;
	float	min;
	float	outr;
	BOOL	rev;
	BOOL	type;
};


class COpAmp : public CObject
{
public:
	COpAmp(float r1, float r2, BOOL type);
	~COpAmp(void);
	double GetGain();
	double r1, r2;
	int type;
};

class CAmplifier  
{
public:
	CAmplifier(void);
	~CAmplifier(void);
	void AddOpAmp(COpAmp &opamp);
	void RemoveAll(void);
	double GetGain();
	void Trace(void);
	COpAmp *GetOpAmp(int index);
	int GetCount()
	{
		return amps->GetCount();
	}
	CObList *amps;
	BOOL type;
	double m_min;
	double m_max;
};

#endif // !defined(AFX_DATACLASSES_H__0F2662D9_FE85_4796_9C37_BBBCA3D7130E__INCLUDED_)
