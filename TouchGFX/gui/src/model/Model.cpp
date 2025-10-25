#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern "C" {
	extern unsigned short buf[6000];
	extern unsigned short buf_size;
	extern unsigned short scaler;
	extern int scalerStateT;
}


Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	static int counter = 0;
	if(++counter >= 5) {
		modelListener->updateBuffer();
		counter = 0;
	}
	if (scalerStateT == 1) {
		scalerStateT = 0;
		modelListener->updateScaler();

	}

}

unsigned short Model::getBufSize()
{
   return buf_size;
}

unsigned short* Model::getBuf()
{
   return buf;
}

