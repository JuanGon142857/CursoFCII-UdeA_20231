import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('espiral.csv', names=['x', 'y', 'z'])


def graph():
    x = df['x']
    y = df['y']
    z = df['z']


    ax = plt.figure().add_subplot(projection='3d')
    ax.plot(x, y, z)

    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')

    ax.set_title('Espiral')

    plt.savefig('espiral.png')
    plt.show()
    


if __name__ == '__main__':
    graph()