#ifndef Scene_h
#define Scene_h

#include <vector>

class Scene
{
	private:
		int ni, nj, size;
		std::vector< std::vector<double> > pixels;

	public:
		Scene(int ni, int nj);

		// Blur with a PSF
		void blur(const Scene& psf);

		// Resize (destructive)
		void resize(int ni, int j);

		// Element access
		double operator () (int i, int j) const;
		double& operator () (int i, int j);

		// Getters for size
		int get_ni() const;
		int get_nj() const;
		int get_size() const;

};

#endif


