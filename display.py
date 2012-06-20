import numpy as np
import matplotlib.pyplot as plt

sample = np.atleast_2d(np.loadtxt('sample.txt'))

plt.ion()
plt.hold(False)
for i in xrange(0, sample.shape[0]):
	plt.imshow(sample[i, :].reshape(256, 256))
	plt.gca().set_xticks([])
	plt.gca().set_yticks([])
	plt.title(i+1)
	plt.draw()

plt.ioff()
plt.show()


