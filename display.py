import numpy as np
import matplotlib.pyplot as plt

sample = np.atleast_2d(np.loadtxt('posterior_sample.txt'))

for i in xrange(0, sample.shape[0]):
	plt.imshow(sample[i, :].reshape(1000, 1000))
	plt.show()



