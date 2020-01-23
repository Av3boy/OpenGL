#include "AudioPlayer.h"
#include <irrKlang/irrKlang.h>
#include <string>

using namespace irrklang;

ISoundEngine* SoundEngine = createIrrKlangDevice();

void AudioPlayer::PlayAudioFromFile(std::string file, bool loop)
{

	ISound* sound = SoundEngine->play2D(file.c_str(), loop);

	SoundEngine->play2D(file.c_str(), loop);
	SoundEngine->setSoundVolume(0.25f);

	//ISoundSource* source = SoundEngine->getSoundSource(sound);
	//SoundEngine->s;

}