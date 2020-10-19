#include <stdbool.h>

typedef enum
{
	FADE_IN,
	FADE_OUT

}FadeType;

typedef struct 
{
	FadeType fadeType;

	bool isFading;

	float fadeAlpha,

		  timer;

}Fader;

Fader StartFade(Fader fader, FadeType fadeType);
Fader StopFade(Fader fader, FadeType fadeType);
Fader UpdateFade(Fader fader);