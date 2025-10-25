#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern "C" {
	extern unsigned short buf[3000];
	extern unsigned short buf_size;
	extern unsigned short scaler;
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

}

unsigned short Model::getBufSize()
{
   return buf_size;
}

unsigned short* Model::getBuf()
{
   return buf;
}

unsigned short Model::getScaler() {
	return scaler;
}
