#ifndef _SAMPLEDATA_H_
#define _SAMPLEDATA_H_

#include "wavefile.h"
#include <string>
#ifdef WIN32
#include <xaudio2.h>
#endif

// Contains all information related to a sample, including file information, what key it is mapped to,
// and any information used for playback.

class SampleData
{
public:
    SampleData();
    ~SampleData();
    int _keyboardNote; // Note which sample is mapped to on keyboard
    int _sampleNote; // Pitch of original sample.
    int _volume; // DirectSound volume (attenuation, 0 is max volume).
	bool _looping; // Does the sample repeat after playing through?
	bool _userSpecified; // Has this been specified by the user or is it autogenerated?
    std::string _filename; // File containing sample.
	WaveFile* _waveFile; // Actual wave file data for sample.  Should be a pointer
	                    // with reference counting in order to save memory.  That
	                    // comes later.
#ifdef WIN32
	IXAudio2SourceVoice* _sourceVoice; // The actual playback data.
	XAUDIO2_BUFFER* _buffer;
	void CreateSource(IXAudio2* xAudio2); // Creates an IXAudio2SourceVoice from the wave file.
	static std::string GetXAudioErrorString(HRESULT hr); // Gets an error string for an XAudio HRESULT.
	void DestroySource(); // Destroys source and clears buffer.
#endif
};

#endif
