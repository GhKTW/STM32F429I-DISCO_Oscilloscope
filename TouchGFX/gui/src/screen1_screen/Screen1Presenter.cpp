#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::updateBuffer()
{
	unsigned short buf_size = model->getBufSize();
	unsigned short* buf = model->getBuf();

	view.drawValue(buf, buf_size);

}
void Screen1Presenter::updateScaler()
{
	view.printScale();
}

