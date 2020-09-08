# CheckBeat

A simple checkbox-based drum machine for Windows. It was originally released 
on http://zetacentauri.com and was downloaded more than 110,000 times before 
being open-sourced.

![CheckBeat Screenshot](https://github.com/Xangis/CheckBeat/blob/master/images/CheckBeat.png)

A prebuilt installer is in the installer directory:

https://github.com/Xangis/CheckBeat/blob/master/installer/CheckBeat3.1Setup.exe

CheckBeat uses the SDL libraries for sound generation.

# Building

CheckBeat requires libsndfile for .wav file loading. It also requires the 
the AudioFile project from my GitHub account to be checked out into a directory
next to the directory containing CheckBeat.

You can get AudioFile here:

https://github.com/Xangis/AudioFile

CheckBeat also requires libsdl2 and libsdl_mixer 2. They are available here:

https://www.libsdl.org/

https://www.libsdl.org/projects/SDL_mixer/

### Windows

You can get the libsndfile dependency here:

http://www.mega-nerd.com/libsndfile/

You'll need to update the include and library paths to point to where libsndfile is
on your system, and to set where your SDL libraries are.

### Linux

This program has not been ported to Linux yet and will not build. However, there is 
a Makefile that will try to build the program. It will fail because the UI uses 
Win32 and Windows-specific code.

To get libsndfile and the SDL dependencies, run:

sudo apt-get install libsndfile-dev libsdl2-dev libsdl2-mixer-dev

I'd like to port it to either Qt or wxWidgets, but haven't decided which to use yet.

# Changelog

Changes For CheckBeat Version 3.1:

- Switched to SDL for sound playback because it's easier to use and more cross-platform friendly.

Changes For CheckBeat Version 3:

- Now uses XAudio2 for sound playback.  Versions before 3 used DirectMusic, which Microsoft no longer supports.
- Interface now has the rounded button styles.
- Added a help button.
- Controls that don't affect the beat while it's playing are grayed out during playback.
- Includes 18 drum samples instead of the basic 4.

Changes For CheckBeat Version 2:

- Now allows the selection of division length (1/4 to 1/32 note).
- Multithreaded to allow interaction with dialog without disrupting currently playing beat.

# Development Status

I consider this program to be feature complete and am no longer developing
new features for it. However, I do maintain it and will update it as 
necessary.

It currently only runs on Windows. I plan to port it to Linux at some point 
when I have the time and motivation.
