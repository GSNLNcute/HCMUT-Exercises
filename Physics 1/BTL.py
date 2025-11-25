import sympy as sp
import numpy as np
import matplotlib.pyplot as plt

# 1. Nhập biểu thức điện thế V(x, y)
x, y = sp.symbols('x y')
expr_str = input("Nhập vào biểu thức V(x, y): ")

V = sp.sympify(expr_str)

# 2. Tạo lưới điểm
X_vals = np.linspace(-10, 10, 41)
Y_vals = np.linspace(-10, 10, 41)
X, Y = np.meshgrid(X_vals, Y_vals)

# 3. Tính đạo hàm Ex, Ey
dVdx = sp.diff(V, x)
dVdy = sp.diff(V, y)

fV = sp.lambdify((x, y), V, "numpy")
fEx = sp.lambdify((x, y), -dVdx, "numpy")
fEy = sp.lambdify((x, y), -dVdy, "numpy")

V_grid = fV(X, Y)
Ex_grid = fEx(X, Y)
Ey_grid = fEy(X, Y)

# 4. Vẽ đồ thị
fig = plt.figure(figsize=(12, 5))

# Đồ thị điện thế 3D
ax1 = fig.add_subplot(1, 2, 1, projection='3d')
ax1.plot_surface(X, Y, V_grid, cmap='viridis')
ax1.set_title("Điện thế V(x, y)")
ax1.set_xlabel("x")
ax1.set_ylabel("y")
ax1.set_zlabel("V")

# Trường điện
ax2 = fig.add_subplot(1, 2, 2)
ax2.quiver(X, Y, Ex_grid, Ey_grid, color='red')
ax2.set_title("Điện trường E(x, y)")
ax2.set_xlabel("x")
ax2.set_ylabel("y")

plt.tight_layout()
plt.show()
