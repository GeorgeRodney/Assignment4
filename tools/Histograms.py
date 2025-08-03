import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

dataInterArrival = pd.read_csv("../output/interArrival.csv", header=None).squeeze()
dataInterService = pd.read_csv("../output/interService.csv", header=None).squeeze()
avgTimes = pd.read_csv("../output/avgTimes.csv", header=None).squeeze()

print(f"Simulated for {avgTimes[5]} hours")

print(f"AvgSystemTime: {avgTimes[0]}")
print(f"AvgQueueTime: {avgTimes[1]}")
print(f"AvgServiceTime: {avgTimes[2]}")
print(f"numServiceCompletions: {avgTimes[3]}")
print(f"numSystemArrivals: {avgTimes[4]}")

print(f" Interarrival mean {np.mean(dataInterArrival)} in seconds")
print(f" Interservice mean {np.mean(dataInterService)} in seconds")
print(f" Interarrival median {np.median(dataInterArrival)} in seconds")
print(f" Interservice median {np.median(dataInterService)} in seconds")

print(f"Empirically calculate Interarrival rate: {(1 / np.mean(dataInterArrival)) * 60 * 60}")
print(f"Empirically calculate Interservice rate: {(1 / np.mean(dataInterService)) * 60 * 60}")

xMax = max(max(dataInterArrival), max(dataInterService))
fig, axs = plt.subplots(2, 1)  # 2 rows, 1 column
axs[0].hist(dataInterArrival, bins=100, density=True, color='cyan', alpha=1, label='Inter Arrival')
axs[1].hist(dataInterService, bins=100, density= True, color='magenta', alpha=0.25, label='Inter Service')
axs[1].set_xlabel("Interval Times [seconds]")
axs[0].set_xticks(np.arange(0, xMax, 50.0))
axs[1].set_xticks(np.arange(0, xMax, 50.0))
axs[0].set_ylabel("Density")
axs[1].set_ylabel("Density")
axs[0].legend()
axs[1].legend()
axs[0].set_title(f"Simulated for {avgTimes[5]} hours")
plt.grid(True)
plt.tight_layout()
plt.show()
