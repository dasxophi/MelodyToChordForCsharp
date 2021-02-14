#include "pch.h"

#include "MelodyToChord.h"
#include "MelodyToChordForCsharp.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include <iostream>

using namespace System::Collections::Generic;
using namespace msclr::interop;

namespace MelodyToChordForCsharp {

	Logic::Logic() : m_pMelodyToChord(new MelodyToChord) {
		std::cout << " create " << std::endl;
	}

	Logic::~Logic() {
		std::cout << " delete " << std::endl;
		if (m_pMelodyToChord) {
			delete m_pMelodyToChord;
			m_pMelodyToChord = 0;
		}
	}



	Dictionary<String^, int>^ Convert(map<string, int>* myMap) {
		//std::cout << "convert " << std::endl;
		if (!myMap)
			throw gcnew System::ArgumentNullException("myMap");

		Dictionary<String^, int>^ h_result = gcnew Dictionary<String^, int>(myMap->size());

		for (pair<string, int> kvp : *myMap)
		{
			String^ s1 = marshal_as<String^>(kvp.first);
			h_result->Add(s1, kvp.second);
			
		}

		return h_result;
	}

	int Logic::Setting() {
		return m_pMelodyToChord->Setting();
	}


	Dictionary<String^, int>^ Logic::ChordRecommendClock(std::multimap<int, int>& melodyAndTime, ChordRecommend& chords, bool stop) {
		map<string, int> myMap  = m_pMelodyToChord->ChordRecommendClock(melodyAndTime, chords, stop);
		std::cout << "chordrecommendclock " << std::endl;
		return Convert(&myMap);

	}


	Dictionary<String^, int>^ Logic::main() {
		map<string, int> myMap = m_pMelodyToChord->main();
		Logic::~Logic();
		return Convert(&myMap);
	}
}
