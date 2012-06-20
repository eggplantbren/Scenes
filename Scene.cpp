#include "Scene.h"

using namespace std;

Scene::Scene(int ni, int nj)
:ni(ni), nj(nj)
,size(ni*nj)
,pixels(ni, vector<double>(nj))
{

}

void Scene::blur(const Scene& psf)
{

}

double Scene::operator () (int i, int j) const
{
	return pixels[i][j];
}

double& Scene::operator () (int i, int j)
{
	return pixels[i][j];
}

int Scene::get_ni() const
{
	return ni;
}

int Scene::get_nj() const
{
	return nj;
}

int Scene::get_size() const
{
	return size;
}

