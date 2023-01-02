import numpy as np
from sklearn.linear_model import LinearRegression

regressor = LinearRegression()

x = np.array([-45, -40, -35, -30, -25, -20, -15, -10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45]).reshape((-1, 1))
y = np.array([0, 4.5, 8.5, 12, 15, 17.5, 19.5, 21, 22, 22.5, 22.5, 22, 21, 19.5, 17.5, 15, 12, 8.5, 4.5])

x_pred = np.array([50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]).reshape((-1, 1))

from sklearn.preprocessing import PolynomialFeatures

poly = PolynomialFeatures(degree=2)
x_poly = poly.fit_transform(x)

regressor.fit(x_poly, y)

# predict the value of y for given x
y_pred = regressor.predict(poly.fit_transform(x_pred))

import matplotlib.pyplot as plt

# plot the data
plt.plot(x, y, 'o', label='given data')
plt.plot(x_pred, y_pred, 'o', label='predicted data')

# add labels
plt.xlabel('x ')
plt.ylabel('y')

# add legend
plt.legend()

# show the plot
plt.show()

