import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("search_comparisons.csv")
# Extracting the data to individual variables from csv file
size = df["Data Size"]
bestCase = df["Best Case"]
worstCase = df["Worst Case"]
averageCase = df["Average Case"]
timeTaken = df["Time Taken"]

# Plot the data
plt.figure(figsize=(10, 6))         # mesurments are in inches 
plt.plot(size, bestCase, label="Best Case", marker='*')
plt.plot(size, worstCase, label="Worst Case", marker='o')
plt.plot(size, averageCase, label="Average Case", marker='o')
plt.plot(size, timeTaken,color="Red", label="Time Take",marker="*")

# Add titles and labels
plt.title("Linear Search Comparisons")
plt.xlabel("Array Size (n)")
plt.ylabel("Number of Comparisons")
plt.legend()
plt.grid(True)

plt.show()
