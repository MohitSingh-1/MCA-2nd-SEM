import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("search_comparisons.csv")

size = df["DataSize"]
bestCase = df["BestCase"]
worstCase = df["WorstCase"]
averageCase = df["AverageCase"]

# //plotting the graph

plt.figure(figsize=(10,6))
plt.plot(size,bestCase,label="Best Case",marker="*")
plt.plot(size, worstCase, label="Worst Case", marker='o')
plt.plot(size, averageCase, label="Average Case", marker='o')

plt.title("Insertion Sort Comparision")
plt.xlabel("Array Size(n)")
plt.ylabel("Number of Comparision")
plt.legend()
plt.grid(True)

plt.savefig("diagram.png")

plt.show()