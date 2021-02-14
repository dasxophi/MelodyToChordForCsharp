#pragma once
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <thread>
#include <functional>
#include <string>
#include <map>
#include "MelodyToChord.h"
using namespace System;
using namespace System::Collections::Generic;

namespace MelodyToChordForCsharp {
	using namespace std;
	MIDIIn* pMIDIIn;
	MIDIOut* pMIDIOut;
	wchar_t szDeviceName[32];
	unsigned char byMessage[256];
	long lRet;
	public ref class Logic
	{

	protected:
		MelodyToChord* m_pMelodyToChord;

	public:
		Logic();
		virtual ~Logic();
		int Setting();
		//int MelodyPrint(std::multimap<int, int>& melodyAndTime);
		//int MelodyPrintOne(std::multimap<int, int>& melodyAndTime);
		Dictionary<String^, int>^ main();
		Dictionary<String^, int>^ ChordRecommendClock(multimap<int, int>& melodyAndTime, ChordRecommend& chords, bool stop);
	};
}
