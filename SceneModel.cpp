/*
* Copyright (c) 2009, 2010, 2011, 2012 Brendon J. Brewer.
*
* This file is part of DNest3.
*
* DNest3 is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* DNest3 is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with DNest3. If not, see <http://www.gnu.org/licenses/>.
*/

#include "SceneModel.h"
#include "RandomNumberGenerator.h"
#include "Utils.h"
#include <cmath>
#include <iomanip>

using namespace std;
using namespace DNest3;

SceneModel::SceneModel()
:scene(256, 256)
{

}

void SceneModel::fromPrior()
{
	mu = exp(log(1E-3) + log(1E6)*randomU());

	for(int i=0; i<scene.get_ni(); i++)
		for(int j=0; j<scene.get_nj(); j++)
			scene(i, j) = -log(randomU());
}

double SceneModel::perturb1()
{
	double logH = 0.;

	double chance = pow(10., 0.5 - 4.*randomU());
	double scale = pow(10., 1.5 - 6.*randomU());
	double U;

	for(int i=0; i<scene.get_ni(); i++)
	{
		for(int j=0; j<scene.get_nj(); j++)
		{
			if(randomU() <= chance)
			{
				U = 1. - exp(-scene(i, j));
				U += scale*randn();
				U = mod(U, 1.);
				scene(i, j) = -log(1. - U);
			}
		}
	}

	return logH;
}

double SceneModel::perturb2()
{
	double logH = 0.;

	double ratio = 1./mu;

	mu = log(mu);
	mu += log(1E6)*pow(10., 1.5 - 6.*randomU())*randn();
	mu = mod(mu - log(1E-3), log(1E6)) + log(1E-3);
	mu = exp(mu);

	ratio *= mu;
	for(int i=0; i<scene.get_ni(); i++)
		for(int j=0; j<scene.get_nj(); j++)
			scene(i, j) *= ratio;

	return logH;
}

double SceneModel::perturb()
{
	double logH = 0.;
	int which = randInt(2);

	if(which == 0)
		logH += perturb1();
	else
		logH += perturb2();

	return logH;
}

double SceneModel::logLikelihood() const
{
	return 0.;
}

void SceneModel::print(ostream& out) const
{
	out<<setprecision(4);
	for(int i=0; i<scene.get_ni(); i++)
		for(int j=0; j<scene.get_nj(); j++)
			out<<scene(i, j)<<' ';
}

string SceneModel::description() const
{
	return string("256^2 pixels");
}

