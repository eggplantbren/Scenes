#include "Scene.h"

using namespace std;

Scene::Scene(int ni, int nj)
:ni(ni), nj(nj)
,size(ni*nj)
,pixels(ni, vector<double>(nj))
{

}

void Scene::resize(int ni, int nj)
{
	this->ni = ni; this->nj = nj;
	size = ni*nj;
	pixels.resize(ni, vector<double>(nj));
}

void Scene::blur(const Scene& psf)
{

}

