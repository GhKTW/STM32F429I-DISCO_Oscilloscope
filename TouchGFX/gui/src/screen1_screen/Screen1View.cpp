#include <gui/screen1_screen/Screen1View.hpp>
#include <texts/TextKeysAndLanguages.hpp>
extern "C" {
	extern int center;
	extern unsigned short scaler;
	extern unsigned short bDrawTransition;
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::drawValue(unsigned short* buf, unsigned short buf_size)
{
	if (bDrawTransition) {
		dynamicGraph1.clear();
		for (int i = 0; i < 300; i++)
		{
			float v = float((buf[center + ((i - 150))* scaler]) / 4095.0f) * 50.0f + 30.0f;
			dynamicGraph1.addDataPoint(v);
		}
		dynamicGraph1.invalidate();
	}
}

void Screen1View::printScale() {
	if (scaler == 13) {
		secondperdivision.setTypedText(touchgfx::TypedText(T_1000US));
		secondperdivision.invalidate();
	}
	else if (scaler == 6) {
		secondperdivision.setTypedText(touchgfx::TypedText(T_500US));
		secondperdivision.invalidate();
	}
	else if (scaler == 3) {
		secondperdivision.setTypedText(touchgfx::TypedText(T_250US));
		secondperdivision.invalidate();
	}
}
