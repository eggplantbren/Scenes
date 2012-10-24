#ifndef Scene_h
#define Scene_h

#include <vector>

class Scene
{
	protected:
		int ni, nj, size;
		std::vector< std::vector<double> > pixels;

	public:
		Scene(int ni, int nj);

		// Blur with a PSF
		void blur(const Scene& psf);

		// Resize (destructive)
		void resize(int ni, int j);

		double operator() (int i, int j) const
		{
			return pixels[i][j];
		}
};

#endif


