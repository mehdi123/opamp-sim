// DataClasses.cpp: implementation of the CNewValues class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OpAmp.h"
#include "DataClasses.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CNewValues Class
//////////////////////////////////////////////////////////////////////

CNewValues::CNewValues()
{
}

CNewValues::~CNewValues()
{
}

//////////////////////////////////////////////////////////////////////
// COpAmp Class
//////////////////////////////////////////////////////////////////////

COpAmp::COpAmp(float _r1, float _r2, BOOL _type)
{
	r1=_r1;
	r2=_r2;
	type=_type;
}

COpAmp::~COpAmp()
{
}

double COpAmp::GetGain()
{
	return type ? (-r2/r1) : (1+r2/r1);
}

//////////////////////////////////////////////////////////////////////
// CAmplifier Class
//////////////////////////////////////////////////////////////////////

CAmplifier::CAmplifier()
{
	amps=new CObList;
}

CAmplifier::~CAmplifier()
{
	RemoveAll();
	delete amps;
}

void CAmplifier::AddOpAmp(COpAmp &opamp)
{
	amps->AddTail((CObject*)&opamp);
}

double CAmplifier::GetGain()
{
	POSITION pos;
	COpAmp *opAmp;
	double gain=1.0;
	pos=amps->GetHeadPosition();
	while(pos)
	{
		opAmp=(COpAmp*)amps->GetNext(pos);
		gain*=opAmp->GetGain();
	}
	return gain;
}

void CAmplifier::RemoveAll(void)
{
	amps->RemoveAll();
}

COpAmp *CAmplifier::GetOpAmp(int index)
{
	POSITION pos;
	COpAmp *opAmp;
	pos=amps->GetHeadPosition();
	int n=0;

	while(pos && n<=index)
	{
		opAmp=(COpAmp*)amps->GetNext(pos);
		n++;
	}
	return opAmp;
}

void CAmplifier::Trace(void)
{
	POSITION pos;
	COpAmp *opAmp;

	pos=amps->GetHeadPosition();
	while(pos)
	{
		opAmp=(COpAmp*)amps->GetNext(pos);
		TRACE("R1=%g\tR2=%g\tType=%d\n",opAmp->r1, opAmp->r2, opAmp->type);
	}
	TRACE("*****************\n");
}
