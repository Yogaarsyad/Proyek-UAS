import pandas as pd
import matplotlib.pyplot as plt

# Baca data dari file CSV untuk simulasi pertama
data1 = pd.read_csv("Data1.csv")

# Plot grafik untuk simulasi pertama
plt.figure(figsize=(10, 6))
plt.plot(data1["Iterasi"], data1["Populasi Predator"], label="Predator (Simulasi 1)", color="red")
plt.plot(data1["Iterasi"], data1["Populasi Prey"], label="Prey (Simulasi 1)", color="blue")

# Tambahkan label dan judul
plt.title("Simulasi Lotka-Volterra - Simulasi 1", fontsize=16)
plt.xlabel("Iterasi", fontsize=14)
plt.ylabel("Populasi", fontsize=14)
plt.legend(fontsize=12)
plt.grid(True)

# Simpan grafik ke file
plt.savefig("simulasi1_grafik.png")
plt.show()