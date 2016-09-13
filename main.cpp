
#include "sfwdraw.h"
#include "constdel.h"
#include "Splash.h"
#include "Depart.h"
#include "Option.h"


void main()
{
	sfw::initContext(800, 600, "NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	Splash splash;
	Depart depart;
	Option option;

	splash.init(font);
	depart.init(font);
	option.init(font);
	bool quit = false;

	APP_STATE state = ENTER_OPTION;

	while (sfw::stepContext() && !quit)
	{
		switch (state)
		{
		case ENTER_OPTION:
			option.play();
		case OPTION:
			option.step();
			option.draw();
			state = option.next();
			break;

		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;

		case ENTER_DEPART:
			depart.play();
		case DEPART:
			depart.step();
			depart.draw();
			state = depart.next();
			break;

		case TERMINATE: quit = true;
		}
	}
	sfw::termContext();
}