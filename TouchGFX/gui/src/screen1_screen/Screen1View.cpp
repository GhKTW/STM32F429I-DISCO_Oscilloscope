#include <gui/screen1_screen/Screen1View.hpp>

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

void Screen1View::drawValue(unsigned short* buf, unsigned short buf_size, unsigned short scaler)
{
	dynamicGraph1.clear();
	for (int i = 0; i < 300; i++)
	{
		float v = float((buf[i * scaler]) / 4095.0f) * 50.0f + 30;
		dynamicGraph1.addDataPoint(v);
	}
    dynamicGraph1.invalidate();
}
