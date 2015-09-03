#include "PlayBGM.h"

ISoundEngine* engine;

void Play()
 {
        engine = createIrrKlangDevice();

		engine->play2D("../media/BGM.mp3", true); // play some mp3 file, looped
 } 

void Play2()
{	
	if (engine ->isCurrentlyPlaying ("../media/female_scream.wav"))
	return;

	engine->play2D("../media/female_scream.wav", false); 
}
void DeleteEngine()
{
	engine->drop();
}