#pragma once
#include "Chords.h"
using namespace std;


class ChordRecommend : public Chords {

private:
	string longMelody;

public:
	void AddictionalPoint(multimap <int, int> ::iterator max) {
		longMelody = ReturnNoteset(max->first); // ���Z�_
	}
	map<string, int> Recommend() {
		int count = 0;

		for (string noteset : savenoteset) {
			for (auto chordname : AllchordList) {

				if (std::find(chordname.begin(), chordname.end(), noteset) != chordname.end()) {
					if (std::find(set.begin(), set.end(), chordname) == set.end()) { // set�̒��ɐ��E����R�[�h�����݂��Ă��Ȃ��ꍇ
						set.push_back(chordname); //�@�R�[�h�𐄑E���X�g�ɒǉ��@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@
						ChordAndCount.insert(pair<vector<string>, int>(chordname, 1));
						//cout << chordname.at(0) << "�����E����܂���" << endl;


					}
					else if (std::find(set.begin(), set.end(), chordname) != set.end()) { // set�̒��ɐ��E����R�[�h�����݂��Ă�ꍇ�@
						count++;
						ChordAndCount[chordname] = ChordAndCount[chordname] + count;// ���݂��Ă���R�[�h�̐��E�񐔂�����₷
						//cout << chordname.at(0) << "�����E����܂���" << endl;
						count = 0;
					}

				}
				//longMelody�ɂ��Ă̓R�[�h���E��������x�s��(longMelody�̓R�[�h�����肷��Ƃ��ɓ��ɏd�v�Ȃ̂�)
				if (std::find(chordname.begin(), chordname.end(), longMelody) != chordname.end()) {
					if (std::find(set.begin(), set.end(), chordname) == set.end()) { // set�̒��ɐ��E����R�[�h�����݂��Ă��Ȃ��ꍇ
						set.push_back(chordname); //�@�R�[�h�𐄑E���X�g�ɒǉ��@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@
						ChordAndCount.insert(pair<vector<string>, int>(chordname, 1));
						//cout << chordname.at(0) << "�����E����܂���" << endl;


					}
					else if (std::find(set.begin(), set.end(), chordname) != set.end()) { // set�̒��ɐ��E����R�[�h�����݂��Ă�ꍇ�@
						count++;
						//ChordAndCount[chordname] = ChordAndCount[chordname] + count;// ���݂��Ă���R�[�h�̐��E�񐔂�����₷
						//cout << chordname.at(0) << "�����E����܂���" << endl;
						count = 0;
					}
				}

			}
		}
		map < vector<string>, int> ::iterator iter;
		map<string, int>  result;
		
		for (iter = ChordAndCount.begin(); iter != ChordAndCount.end(); iter++) {
			cout << iter->first.at(0) << " " << iter->second << "point  " << endl;
			result.insert(pair<string,int>(iter->first.at(0), iter->second));
			//String^ csString = msclr::interop::marshal_as<String^>(iter->first.at(0));
			//result->Add(csString, iter->second);
		}
		//Dictionary<String^, int>^ result2 = marshal_as<Dictionary<String^, int>^>(result);
		return result;
		savenoteset.clear();
		ChordAndCount.clear();
		
	}


};