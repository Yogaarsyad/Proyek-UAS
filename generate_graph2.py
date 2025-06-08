import pandas as pd
import matplotlib.pyplot as plt

# Baca data dari file CSV untuk simulasi kedua
data2 = pd.read_csv("Data2.csv")

# Plot grafik untuk simulasi kedua
plt.figure(figsize=(10, 6))
plt.plot(data2["Iterasi"], data2["Populasi Predator"], label="Predator (Simulasi 2)", color="orange")
plt.plot(data2["Iterasi"], data2["Populasi Prey"], label="Prey (Simulasi 2)", color="green")

# Tambahkan label dan judul
plt.title("Simulasi Lotka-Volterra - Simulasi 2", fontsize=16)
plt.xlabel("Iterasi", fontsize=14)
plt.ylabel("Populasi", fontsize=14)
plt.legend(fontsize=12)
plt.grid(True)

# Simpan grafik ke file
plt.savefig("simulasi2_grafik.png")
plt.show()