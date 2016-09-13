#include "Option.h"
#include "sfwdraw.h"
#include <iostream>

void Option::init(int a_font) {font = a_font;}

void Option::play() { select = 0; timer = 1.f; }

void Option::draw()
{
	sfw::drawString(font, "GOTO (S)Splash!", 100, 120, 16, 16,0,0, select == 1? MAGENTA:WHITE);
	sfw::drawString(font, "GOTO (D)Depart!", 100, 100, 16, 16,0,0, select == 0? MAGENTA:WHITE);

	sfw::drawLine(100, 80, 100 + 500 * (timer / 5.f), 80);
}

void Option::step() 
{ 
	timer -= sfw::getDeltaTime(); 
	if (timer < 0)
	{
		timer = 1.f;
		select = 1 - select; //flip selsction between 0 and 1

	}
}

APP_STATE Option::next()
{
	if (sfw::getKey(KEY_ENTER))
	{
		if (select == 0)
			return ENTER_DEPART;
		if (select == 1)
			return ENTER_SPLASH;
	}
	return OPTION;

}
