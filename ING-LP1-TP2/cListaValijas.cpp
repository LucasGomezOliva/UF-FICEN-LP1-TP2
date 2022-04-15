#include "cListaValijas.h"

cListaValijas::cListaValijas(){
	this-> PesoActual = 0;
	this->CantidadValijas = 0;
	this->ArrayValijas = new cValija * [CantidadMax];
	for (int i = 0; i < CantidadMax; i++)
	{
		ArrayValijas[i] = NULL;
	}
}

cListaValijas::~cListaValijas() {
	if (ArrayValijas != NULL) {
		for (int i = 0; i < CantidadValijas; i++) {
			if (ArrayValijas[i] != NULL)
				delete ArrayValijas[i];
		}
		delete[] ArrayValijas;
	}
}

bool cListaValijas::AgregarValija(int peso) {
	if ((CantidadValijas == CantidadMax) && (PesoMax <= PesoActual + peso)) {
		return false;
	}
	this->ArrayValijas[CantidadValijas++] = new cValija(peso);
	PesoActual = PesoActual + peso;
	return true;
}