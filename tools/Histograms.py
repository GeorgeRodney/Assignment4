import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

data = pd.read_csv("../output/interarrival.csv", header=None).squeeze()
plt.hist(data, bins=100, density=True)
plt.xlabel("Interarrival times [seconds]")
plt.xticks(np.arange(0, max(data), 50.0))  # x grid every 1 unit
plt.ylabel("Density")
plt.title("Packet Generator Arrival Interval Histogram")
plt.grid(True)
plt.show()
