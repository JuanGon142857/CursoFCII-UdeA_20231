import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('posicionesXYZ.csv', sep = ',')

x = df['x']
y = df['y']
z = df['z']

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot(x, y, z, color = 'Crimson')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
plt.suptitle('Trayectoria de la particula')
plt.show()