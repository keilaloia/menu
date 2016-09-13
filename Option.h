#pragma once
#include "constdel.h"
class Option
{
	int font;
	float timer;
	int select;
public:
	//called on startup
	void init(int a_font);

	//called activation
	void play();

	// called on update
	void draw();
	void step();
	

	APP_STATE next();
};