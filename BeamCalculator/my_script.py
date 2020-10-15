import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches
import matplotlib.lines
import matplotlib.path
import pylab

beam_y = 0.52
thick = 0.04
size = 10
def addForce(ax, x, value, len=0.25, text=True, width=0.2):
    if(value > 0):
        arrow = matplotlib.patches.Arrow (x, beam_y, 0, len, width=width, color="black")
    else:
        arrow = matplotlib.patches.Arrow (x, beam_y + len, 0, -len, width=width, color="black")
    ax.add_patch(arrow)
    if(text):
        pylab.text(x, beam_y + 0.27, "F = {}".format(value), horizontalalignment="center")


def addMoment(ax, x, value):
    len_line = 0.15
    shift = 0.1 * size
    shift = -shift if value > 0 else shift

    line = matplotlib.lines.Line2D ([x, x], [beam_y - len_line - thick, beam_y + len_line], color="k")   
    arrow1 = matplotlib.patches.Arrow (x, beam_y + len_line, shift, 0, width=0.01, color="black")
    arrow2 = matplotlib.patches.Arrow (x, beam_y - len_line - thick, -shift, 0, width=0.01, color="black")
    
    ax.add_line(line)
    ax.add_patch(arrow1)
    ax.add_patch(arrow2)
    
    pylab.text(x, beam_y + len_line + 0.02, "M = {}".format(value), horizontalalignment="center")

def addUniformLoad(ax, l, r, value):
    for x in np.linspace(l, r, round((r-l) / 0.25)):
        addForce(ax, x, value, len=0.1, text=False, width=0.1)
    
    pylab.text((l + r) / 2, beam_y + 0.12, "q = {}".format(value), horizontalalignment="center")

file_names = ["forces", "moments", "uniform_loads"]
data = {}
for name in file_names:
    f_key = open("beam_data/{}_key.txt".format(name))
    f_value = open("beam_data/{}_value.txt".format(name))
    data["{}_key".format(name)] = np.asarray([float(val) for val in f_key.read().split()])
    data["{}_val".format(name)] = np.asarray([float(val) for val in f_value.read().split()])

fig, ax = plt.subplots(figsize=(8, 6))
ax.set_xlim(0, 10)
ax.set_ylim(0, 1)
line1 = matplotlib.lines.Line2D ([0, 10], [beam_y, beam_y], color="k")
line2 = matplotlib.lines.Line2D ([0, 10], [0.48, 0.48], color="k")
line3 = matplotlib.lines.Line2D ([10, 10], [0.48, 0.52], color="k")
line4 = matplotlib.lines.Line2D ([0, 0], [0.48, 0.52], color="k")
ax.add_line(line1)
ax.add_line(line2)
ax.add_line(line3)
ax.add_line(line4)
for x, value in zip(data["forces_key"], data["forces_val"]):
    addForce(ax, x, value)

for x, value in zip(data["moments_key"], data["moments_val"]):
    addMoment(ax, x, value)

ls = data["uniform_loads_key"].reshape(-1, 2).T[0]
rs = data["uniform_loads_key"].reshape(-1, 2).T[1]

for l, r, value in zip(ls, rs, data["uniform_loads_val"]):
    addUniformLoad(ax, l, r, value)

plt.show()