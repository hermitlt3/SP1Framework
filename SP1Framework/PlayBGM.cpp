#include "PlayBGM.h"

ISoundEngine* engine;

void Play()
 {
        engine = createIrrKlangDevice();

		engine->play2D("../media/BGM.mp3", true); // play some mp3 file, looped
 } 

void Play2()
{	
	if (engine ->isCurrentlyPlaying ("../media/0knock.wav"))
	return;

	engine->play2D("../media/0knock.wav", false);
}

void DeleteEngine()
{
	engine->drop();
}