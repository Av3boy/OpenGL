#include "AudioPlayer.h"
#include <irrKlang/irrKlang.h>

using namespace irrklang;

ISoundEngine* SoundEngine = createIrrKlangDevice();

void AudioPlayer::PlayAudioFromFile(std::string file, bool loop)
{
	SoundEngine->play2D(file.c_str(), loop);

}