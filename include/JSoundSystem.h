/*******************************************************
 * 
 * Copyright (C) 2019 Francesco Pham (pham.francesco@gmail.com)
 * Copyright (c) 2007 James Hui (a.k.a. Dr.Watson) <jhkhui@gmail.com>
 * 
 *******************************************************/
#ifndef _JSOUNDSYSTEM_H_
#define _JSOUNDSYSTEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <SDL2/SDL_mixer.h>

#include "JTypes.h"


//------------------------------------------------------------------------------------------------
class JMusic
{
public:
	JMusic();
	~JMusic();
};


//------------------------------------------------------------------------------------------------
class JSample
{
public:
	JSample();
	~JSample();

	int mVoice;
	int mVolume;
	int mPanning;
	Mix_Chunk *mSample;
};


//////////////////////////////////////////////////////////////////////////
/// Sound engine for playing sound effects (WAV) and background 
/// music (MP3).
///
//////////////////////////////////////////////////////////////////////////
class JSoundSystem
{

public:

	//////////////////////////////////////////////////////////////////////////
	/// Get the singleton instance
	///
	//////////////////////////////////////////////////////////////////////////
	static JSoundSystem* GetInstance();

	static void Destroy();



	//////////////////////////////////////////////////////////////////////////
	/// Load music.
	/// 
	/// @note MP3 is the only supported format for the moment.
	/// 
	/// @param filename - Name of the music file.
	/// 
	//////////////////////////////////////////////////////////////////////////
	JMusic *LoadMusic(const char *fileName);

	//////////////////////////////////////////////////////////////////////////
	/// Delete music from memory.
	/// 
	/// @param music - Music to be deleted.
	/// 
	//////////////////////////////////////////////////////////////////////////
	//void FreeMusic(JMusic *music);

	//////////////////////////////////////////////////////////////////////////
	/// Play music.
	/// 
	/// @param music - Music to be played.
	/// @param looping - Play the music in a loop.
	/// 
	//////////////////////////////////////////////////////////////////////////
	void PlayMusic(JMusic *music, bool looping = false);

	//////////////////////////////////////////////////////////////////////////
	/// Stop playing.
	/// 
	/// @param music - Music to be stopped.
	/// 
	//////////////////////////////////////////////////////////////////////////
	void StopMusic(JMusic *music);


	//////////////////////////////////////////////////////////////////////////
	/// Resume playing.
	/// 
	/// @param music - Music to be resumed.
	/// 
	//////////////////////////////////////////////////////////////////////////
	void ResumeMusic(JMusic *music);

	//////////////////////////////////////////////////////////////////////////
	/// Load sound effect.
	/// 
	/// @note WAV sound effect only.
	/// 
	/// @param fileName - Sound effect for loading.
	/// 
	//////////////////////////////////////////////////////////////////////////
	JSample *LoadSample(const char *fileName);

	//////////////////////////////////////////////////////////////////////////
	/// Delete sound effect from memory.
	/// 
	/// @param sample - Sound to be deleted.
	/// 
	//////////////////////////////////////////////////////////////////////////
	//void FreeSample(JSample *sample);

	//////////////////////////////////////////////////////////////////////////
	/// Play sound effect.
	/// 
	/// @param sample - Sound for playing.
	/// 
	//////////////////////////////////////////////////////////////////////////
	void PlaySample(JSample *sample);

	//////////////////////////////////////////////////////////////////////////
	/// Stop sound effect.
	/// 
	/// @param voice - voice of sample.
	/// 
	//////////////////////////////////////////////////////////////////////////
	void StopSample(int voice);

	//////////////////////////////////////////////////////////////////////////
	/// Set volume for audio playback.
	/// 
	/// @param volume - New volume.
	/// 
	//////////////////////////////////////////////////////////////////////////
	void SetVolume(int volume);

protected:
	JSoundSystem();
	~JSoundSystem();
	
	void InitSoundSystem();
	void DestroySoundSystem();

private:

	JMusic *mCurrentMusic;

	int mVolume;
	int mChannel;

	static JSoundSystem* mInstance;

};

#endif
