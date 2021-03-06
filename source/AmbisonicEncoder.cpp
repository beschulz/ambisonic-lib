/*############################################################################*/
/*#                                                                          #*/
/*#  Ambisonic C++ Library                                                   #*/
/*#  CAmbisonicEncoder - Ambisonic Encoder                                   #*/
/*#  Copyright � 2007 Aristotel Digenis                                      #*/
/*#                                                                          #*/
/*#  Filename:      AmbisonicEncoder.cpp                                     #*/
/*#  Version:       0.1                                                      #*/
/*#  Date:          19/05/2007                                               #*/
/*#  Author(s):     Aristotel Digenis                                        #*/
/*#  Licence:       MIT                                                      #*/
/*#                                                                          #*/
/*############################################################################*/


#include "AmbisonicEncoder.h"


CAmbisonicEncoder::CAmbisonicEncoder()
{
    Create(DEFAULT_ORDER, DEFAULT_HEIGHT, 0);
	Refresh();
}

CAmbisonicEncoder::~CAmbisonicEncoder()
{
	
}

bool CAmbisonicEncoder::Create(AmbUInt nOrder, AmbBool b3D, AmbUInt nMisc)
{
    bool success = CAmbisonicSource::Create(nOrder, b3D, nMisc);
    if(!success)
        return false;
    SetOrderWeight(0, 1.f / sqrtf(2.f));
    
    return true;
}

void CAmbisonicEncoder::Refresh()
{
	CAmbisonicSource::Refresh();
}

void CAmbisonicEncoder::Process(const AmbFloat *pfSrc, AmbUInt nSamples, CBFormat *pfDst)
{
	AmbUInt niChannel = 0;
	AmbUInt niSample = 0;
	for(niChannel = 0; niChannel < m_nChannelCount; niChannel++)
	{
		for(niSample = 0; niSample < nSamples; niSample++)
		{
			pfDst->m_ppfChannels[niChannel][niSample] = pfSrc[niSample] * m_pfCoeff[niChannel];
		}
	}
}

void CAmbisonicEncoder::ProcessAdditive(const AmbFloat *pfSrc, AmbUInt nSamples, CBFormat *pfDst)
{
	AmbUInt niChannel = 0;
	AmbUInt niSample = 0;
	for(niChannel = 0; niChannel < m_nChannelCount; niChannel++)
	{
		for(niSample = 0; niSample < nSamples; niSample++)
		{
			pfDst->m_ppfChannels[niChannel][niSample] = pfSrc[niSample] * m_pfCoeff[niChannel];
		}
	}
}