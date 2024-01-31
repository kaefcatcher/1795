import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


with open('results/vis/circular-mobility-model-coordinates.txt', 'r') as file:
    file.readline()
    data = [line.strip().split('\t') for line in file]


n0_posx = [float(entry[0]) for entry in data]
n0_posy = [float(entry[1]) for entry in data]
n1_posx = [float(entry[2]) for entry in data]
n1_posy = [float(entry[3]) for entry in data]


fig, ax = plt.subplots()
line_n0, = ax.plot([], [], label='Node 0', marker='o')
line_n1, = ax.plot([], [], label='Node 1', marker='o')
ax.set_title('Circular Mobility Model Movement')
ax.set_xlabel('X Coordinate')
ax.set_ylabel('Y Coordinate')
ax.legend()
ax.grid(True)


def init():
    line_n0.set_data([], [])
    line_n1.set_data([], [])
    return line_n0, line_n1


def update(frame):
    line_n0.set_data(n0_posx[frame], n0_posy[frame])
    line_n1.set_data(n1_posx[frame], n1_posy[frame])
    return line_n0, line_n1


ax.set_xlim(min(n0_posx + n1_posx), max(n0_posx + n1_posx))
ax.set_ylim(min(n0_posy + n1_posy), max(n0_posy + n1_posy))


animation = FuncAnimation(fig, update, frames=len(n0_posx), init_func=init, interval=100, blit=True)


animation.save('results/vis/movement_animation.gif', writer='pillow', fps=10) 
# sudo apt-get install imagemagick
