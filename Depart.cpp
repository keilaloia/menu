#include "Depart.h"
#include "sfwdraw.h"
#include <iostream>

void Depart::init(int a_font)
{
	font = a_font;
}

void Depart::play() { timer = 5.f; }

void Depart::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Press 'Q' or Wait for Depart Time %f", timer);
	sfw::drawString(font, buffer, 100, 100, 20, 20);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 5.f), 80);
}

void Depart::step() { timer -= sfw::getDeltaTime(); }

APP_STATE Depart::next()
{
	if (timer < 0 || sfw::getKey('Q'))
		return TERMINATE;
	return DEPART;

}
