import matplotlib.pyplot as plt

# Data for each configuration
sizes = [1, 2, 3, 4]
raw_times = [0.016466, 0.059713, 0.811359, 8.655239]
asan_times = [0.022702, 0.147210, 1.646950, 18.822408]
valgrind_times = [0.095810, 0.732563, 5.827417, 53.858525]
wasm2c_times = [0.228859, 1.753142, 14.025142, 118.977436]

# Plotting
# Re-plotting with a linear scale on the x-axis for clear, direct labeling of specified sizes

plt.figure(figsize=(10, 6))
plt.plot(sizes, raw_times, marker='o', label="Raw")
plt.plot(sizes, asan_times, marker='o', label="Asan")
plt.plot(sizes, valgrind_times, marker='o', label="Valgrind")
plt.plot(sizes, wasm2c_times, marker='o', label="Wasm2c")

# Setting labels and title
plt.xlabel("SIZE")
plt.ylabel("TIME (s)")
plt.title("Performance Comparison Across Raw, Asan, Valgrind, and Wasm2c")
plt.yscale("log")  # Keep y-axis as logarithmic for time values
plt.xticks(sizes, labels=[str(2**size * 64) for size in sizes])  # Ensure only specified sizes are labeled on x-axis
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

# Show the plot with linear x-axis
plt.show()


plt.savefig("plt.png")